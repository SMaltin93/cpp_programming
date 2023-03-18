#ifndef WATERMANAGER_H
#define WATERMANAGER_H

#include <mutex>
#include <condition_variable>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

const int maxSleepTime = 10;
const int maxDrinkTime = 5;
const int nrGnus = 5;
const int nrHyenas = 5;

int nrOfSimulations = 5;
bool trace = true; // set to false to turn off trace output

class WaterManager {

public:
    WaterManager();
    void hyenaEnters();
    void gnuEnters();
    void hyenaLeaves();
    void gnuLeaves();
    void traceOutput(string message);


private:
    condition_variable CONDITIONVAR;
    mutex mtx;
    atomic_int hyenasInside;
    atomic_int gnusInside;
};
void hyena (int id, WaterManager& waterManager);
void gnu (int id, WaterManager& waterManager);
#endif // WATERMANAGER_H
