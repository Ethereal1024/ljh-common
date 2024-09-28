#ifndef HELLO_HPP
#define HELLO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

class Motor{
    private:
        atomic<bool> power;
        double position;
        double speed;
        double acc;
        thread update_thread;
        void update();
    public:
        Motor();
        ~Motor();
        const atomic<bool>& get_power() const;
        const double& get_position() const;
        const double& get_speed() const;
        const double& get_acc() const;
        bool turn_off();
        bool turn_on();
        bool set_position(double v);
        bool set_speed(const double &v);
        bool set_acc(const double &v);
};

class UI{
    private:
        typedef struct Func{
            void (*excution)();
            string name;
        }Func;
        vector<Func> functions;
    public:
        const long size() const;
        void push_back(void (*f)(), string n);
        void display() const;
        void excute(const int &x);
};

#endif