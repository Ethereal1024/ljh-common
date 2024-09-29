#include "func.hpp"

#include <unistd.h>

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

void Motor::update() {
    while (power) {
        speed += acc;
        position += speed;
        position = (int)position % 360 + (position - (int)position);
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}

Motor::Motor() {
    update_thread = thread(&Motor::update, this);
}

Motor::~Motor() {
    power = false;
    if (update_thread.joinable())
        update_thread.join();
}

const atomic<bool>& Motor::get_power() const { return this->power; }

const double& Motor::get_position() const { return this->position; }

const double& Motor::get_speed() const { return this->speed; }

const double& Motor::get_acc() const { return this->acc; }

bool Motor::turn_off() {
    if (this->power) {
        this->power = false;
        this->speed = 0;
        this->acc = 0;
        return true;
    }
    return false;
}

bool Motor::turn_on() {
    if (this->power) {
        return false;
    }
    this->power = true;
    return true;
}

bool Motor::set_position(double v) {
    if (this->power)
        return false;
    v = (int)v % 360 + (v - (int)v);
    if (v < 0)
        v += 360;
    this->position = v;
    return true;
}

bool Motor::set_speed(const double& v) {
    if (!this->power)
        return false;
    this->speed = v;
    return true;
}

bool Motor::set_acc(const double& v) {
    if (!this->power)
        return false;
    this->acc = v;
    return true;
}

const long UI::size() const {
    return this->functions.size();
}

void UI::push_back(void (*f)(), string n) {
    Func tmp{f, n};
    this->functions.push_back(tmp);
}

void UI::display() const {
    for (int i = 0; i < this->size(); i++) {
        cout << i << ". " << this->functions[i].name;
        if (i != this->size() - 1)
            cout << "\n";
    }
}

void UI::excute(const int& x) {
    if (x < 0 || x > this->size() - 1)
        return;
    printf("\033c");
    functions[x].excution();
}