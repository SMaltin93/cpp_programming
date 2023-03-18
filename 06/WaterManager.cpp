#include "WaterManager.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
 
using namespace std;


WaterManager::WaterManager() {
    this->hyenasInside = 0;
    this->gnusInside = 0;
}

void WaterManager::hyenaEnters() {
    unique_lock<std::mutex> lock(mtx);
    CONDITIONVAR.wait(lock, [this] {return gnusInside == 0;}); 
    hyenasInside += 1;
    traceOutput
}

void WaterManager::gnuEnters() {
    unique_lock<std::mutex> lock(mtx);   
    CONDITIONVAR.wait(lock, [this] {return hyenasInside == 0;});
    gnusInside += 1;
}

void WaterManager::hyenaLeaves() {
    lock_guard<std::mutex> lock(mtx); // 
    hyenasInside -= 1;
    CONDITIONVAR.notify_all();
}

void WaterManager::gnuLeaves() {
    lock_guard<std::mutex> lock(mtx);
    gnusInside -= 1;
    CONDITIONVAR.notify_all();
}
void WaterManager::traceOutput(string message) {
    if (trace) {
        cout << message << endl;
    }
}





void hyena(int id, WaterManager& watermanager) {

    srand(time(nullptr));
    
    for (int i = 0; i < nrOfSimulations; i++) {
        int sleepTime = rand() % maxSleepTime + 1;
        this_thread::sleep_for(chrono::seconds(sleepTime));
   
        watermanager.hyenaEnters();
        int drinkTime = rand() % maxDrinkTime + 1;
        this_thread::sleep_for(chrono::seconds(drinkTime));
        watermanager.hyenaLeaves();
    }
}

void gnu(int id, WaterManager& watermanager) {

    srand(time(nullptr));
    for (int i = 0; i < nrOfSimulations; i++) {

        int sleepTime = rand() % maxSleepTime + 1;
        this_thread::sleep_for(chrono::seconds(sleepTime));

        watermanager.gnuEnters();

        // a random amount of time (smaller than sleeping) to drink
        int drinkTime = rand() % maxDrinkTime + 1;
        this_thread::sleep_for(chrono::seconds(drinkTime));
        watermanager.gnuLeaves();
    }
}

int main() {
    WaterManager watermanager;
    vector<thread> threads;
    // random animal
    srand(time(nullptr));
    // random Gnus
    vector<int> gn; 
    vector<int> hy;
    for (int i = 0; i < nrGnus; i++) {
        gn.push_back(i+1);
        hy.push_back(i+1);
    }
    random_shuffle(gn.begin(),gn.end());
    random_shuffle(hy.begin(),hy.end());


    for (int i = 0; i < nrGnus; i++)
        threads.push_back(thread(gnu, gn[i], ref(watermanager)));

    for (int i = 0; i < nrHyenas; i++)
        threads.push_back(thread(hyena, hy[i], ref(watermanager)));

    for (auto& thread : threads)
        thread.join();

    return 0;
}
