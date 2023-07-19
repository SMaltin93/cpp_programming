#include <bits/stdc++.h>
#include "WaterManager.h"
#include <mutex>
#include <condition_variable>


using namespace std;

mutex mtx;



class Gnu {

    private: 
        int id; 
        WaterManager *watermanager;

    public:
       
        Gnu(int id, WaterManager &watermanager) {
            this->id = id; // id is the number of the gnu
            this->watermanager = &watermanager;
        }

        void operator()() {

            srand(time(nullptr));

            for (int i = 0; i < nrOfSimulations ; i++) {
                watermanager->setGnusId(id);
                int sleepTime = rand() % maxSleepTime + 1;
                this_thread::sleep_for(chrono::seconds(sleepTime));
                lock_guard<mutex> lock(mtx);
                cout << *this  << " is thirsty and wants to drink " << endl;
                // free mutex
                lock.~lock_guard();
                watermanager->gnuEnters();
                int drinkTime = rand() % maxDrinkTime + 1;
                this_thread::sleep_for(chrono::seconds(drinkTime));
                watermanager->gnuLeaves();
            }
        }

        friend ostream& operator<<(ostream& os, const Gnu& gnu) {
            os << "Gnu nr " << gnu.id << " ";
            return os;
        }

        int getId() {
            return id;
        }

};