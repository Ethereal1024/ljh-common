#ifndef REACTION_HPP
#define REACTION_HPP

#include <iostream>
#include <mutex>
#include <string>
#include <thread>

class Reaction {
private:
    int n_carbon;
    int n_hydrogen;
    std::string elements;
    std::string candidate;
    bool reacting;
    std::mutex mtx;
    void releaseCarbon();
    void releaseHydrogen();
    void compose();

public:
    Reaction();
    void start();
};

#endif