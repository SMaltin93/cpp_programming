#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <random>

using namespace std;


class WaterManager  {
      
    public:
    
        void hyenaEnters();
        void hyenaLeaves();
        void gnuEnters();
        void gnuLeaves();

    private:

        mutex mutex;
        condition_variable conditionVar;
        int hyenasInside_ = 0;
        int gnusInside_ = 0;

};
