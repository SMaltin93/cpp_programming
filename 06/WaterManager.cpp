#include "WaterManager.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include "gnu.cpp"

 
using namespace std;
using namespace std::chrono;


WaterManager::WaterManager() {
    this->hyenasInside = 0;
    this->gnusInside = 0;
    this -> gnus_id = 0;
}

WaterManager::~WaterManager() {
}


void WaterManager::setGnusId(int id) {
    this -> gnus_id = id;
}


void WaterManager::hyenaEnters() {
    unique_lock<std::mutex> lock(mtx);
    CONDITIONVAR.wait(lock, [this] {return gnusInside == 0;}); 
    hyenasInside ++;
    traceOutput("A hyena enters the water cave       hyenas = " + to_string(hyenasInside) + "       gnu = " + to_string(gnusInside)); 
}

void WaterManager::gnuEnters() {
    unique_lock<std::mutex> lock(mtx);   
    CONDITIONVAR.wait(lock, [this] {return hyenasInside == 0;});
    gnusInside ++;
    traceOutput("A gnu enters the water cave       hyenas = " + to_string(hyenasInside) + "       gnu = " + to_string(gnusInside));
}

void WaterManager::hyenaLeaves() {
    lock_guard<std::mutex> lock(mtx); // 
    hyenasInside --;
    CONDITIONVAR.notify_all();
    traceOutput(threadIdMap[this_thread::get_id()] + " finished drinking and exits the water cave");
}

void WaterManager::gnuLeaves() {
    lock_guard<std::mutex> lock(mtx);
    gnusInside --;
    // Gnu id leaves the water cave
    CONDITIONVAR.notify_all();
    traceOutput( "Gnu nr " + to_string(this->gnus_id) + " finished drinking and exits the water cave ");
}

void traceOutput(string message) {
    if (trace) {
        cout << message << endl;
    }
}


void hyena(int id, WaterManager& watermanager) {
    srand(time(nullptr)); // seed the random number generator

    for (int i = 0; i < nrOfSimulations; i++) {
        threadIdMap[this_thread::get_id()] = "Hyena nr " + to_string(id);
        int sleepTime = rand() % maxSleepTime + 1;
        this_thread::sleep_for(chrono::seconds(sleepTime));
        // get the value of the thread id and print it
        traceOutput(threadIdMap[this_thread::get_id()] + " is thirsty\n" );
        watermanager.hyenaEnters();
        int drinkTime = (rand() % maxDrinkTime + 1);
        this_thread::sleep_for(chrono::seconds(drinkTime));
        watermanager.hyenaLeaves();

    }

}

// void gnu(int id, WaterManager& watermanager) {

//     srand(time(nullptr));
//     for (int i = 0; i < nrOfSimulations; i++) {
//         threadIdMap [this_thread::get_id()] =  "Gnu nr " + to_string(id);
//         int sleepTime = rand() % maxSleepTime + 1;
//         this_thread::sleep_for(chrono::seconds(sleepTime));
//         traceOutput(threadIdMap[this_thread::get_id()] + " is thirsty\n");
//         watermanager.gnuEnters();
//         // a random amount of time (smaller than sleeping) to drink
//         int drinkTime = rand() % maxDrinkTime + 1;
//         this_thread::sleep_for(chrono::seconds(drinkTime));
//         watermanager.gnuLeaves();
//     }
// }

int main() {
    WaterManager watermanager;
    vector<thread> threads;
    // random animal
    srand(time(nullptr));
    // random Gnus
    vector<int> gn = {1,2,3};
    vector<int> hy = {4,5,6};

    // Unordered map to store the threads id and the animal id as string
    random_shuffle(gn.begin(),gn.end());
    random_shuffle(hy.begin(),hy.end());

    for (int i = 0; i < nrGnus; i++){   
        //threads.push_back(thread(gnu, gn[i], ref(watermanager)));
        Gnu g(gn[i], ref(watermanager));
        function<void(void)> f = g;
        threads.push_back(thread(f));
        threads.push_back(thread(hyena, hy[i], ref(watermanager)));
    }
       
    for (auto& thread : threads) {
        thread.join();
    }

    
    return 0;
}
