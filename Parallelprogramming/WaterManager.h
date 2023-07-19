#ifndef WATERMANAGER_H
#define WATERMANAGER_H

#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <vector>
#include <unordered_map>

using namespace std;

const int maxSleepTime = 10;
const int maxDrinkTime = 2;
const int nrGnus = 3;
const int nrHyenas = 3;

int nrOfSimulations = 1;
const bool trace = true; // set to false to turn off trace output

unordered_map<thread::id, string> threadIdMap; 

class WaterManager {

public:
    // constructor
    WaterManager();
    // destructor
    ~WaterManager();

    void hyenaEnters();
    void gnuEnters();
    void hyenaLeaves();
    void gnuLeaves();


    //void setHyenasId(int id);
    void setGnusId(int id);
    
private:
    condition_variable CONDITIONVAR;
    mutex mtx;
    atomic_int hyenasInside; 
    atomic_int gnusInside;
    //int hyenas_id;
    int gnus_id;
};
void hyena (int id, WaterManager& waterManager);
void traceOutput(string message);
#endif // WATERMANAGER_H
