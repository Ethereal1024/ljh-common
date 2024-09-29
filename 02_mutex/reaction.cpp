#include "reaction.hpp"

Reaction::Reaction() : 
reacting(false), n_carbon(0), n_hydrogen(0)
{}

void Reaction::releaseCarbon(){
    while(1){
        if(n_carbon){
            {
                mtx.lock();
                candidate.push_back('C');
                mtx.unlock();
            }
            n_carbon -= 1;
            break;
        }
    }
}

void Reaction::releaseHydrogen(){
    while(1){
        if(n_hydrogen >= 4){
            {
                mtx.lock();
                candidate += "HHHH";
                mtx.unlock();
            }
            n_hydrogen -= 4;
            break;
        }
    }
}

void Reaction::compose(){
    while(n_carbon && n_hydrogen >= 4 || !reacting){
        std::thread trdC(&Reaction::releaseCarbon, this);
        std::thread trdH(&Reaction::releaseHydrogen, this);
        trdC.join();
        trdH.join();
        std::cout << candidate;
        candidate = "";
    }
}

void Reaction::start(){
    std::cin >> elements; 
    std::thread cps(&Reaction::compose, this);
    for(auto c : elements){
        if(c == 'C') n_carbon++;
        if(c == 'H') n_hydrogen++;
    }
    reacting = true;
    cps.join();
    std::cout << "\n";
}