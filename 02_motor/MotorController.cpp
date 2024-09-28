#include <iostream>
#include <iomanip>
#include <atomic>
#include <thread>
#include "func.hpp"
using namespace std;

Motor my_motor;

void cls(){
    printf ("\033c"); 
}

void _pause(){
    cout << "\n*输入q退出.*\n";
    char c;
    while(c != 'q'){
        cin >> c;
    }
}

void stop_motor(){  //关闭电机
    if(!my_motor.turn_off()) cout << "电机已经处于关闭状态.\n";
    else cout << "电机已关闭.\n";
    _pause();
}

void start_motor(){  //开启电机
    if(!my_motor.turn_on()) cout << "电机已经处于打开状态.\n";
    else cout << "电机已打开.\n";
    _pause();
}

void set_position(){  //设置电机相位
    if(my_motor.get_power()) {
        cout << "电机处于运行状态, 请先关闭电机.\n";
        _pause();
        return;
    }
    double position;
    cout << "请输入旋转相位(单位: °):\n";
    cin >> position;
    if(my_motor.set_position(position)) cout << "电机相位已成功旋转到: " << fixed << setprecision(2) << position << "°.\n";
    else cout << "电机处于运行状态，请先关闭电机.";
    _pause();
}

void set_speed(){  //修改电机速度
    if(!my_motor.get_power()) {
        cout << "电机处于关闭状态, 请先开启电机.\n";
        _pause();
        return;
    }
    double speed;
    cout << "请输入设置速率(单位: °/ms):\n";
    cin >> speed;
    if(my_motor.set_speed(speed)) cout << "电机速度已成功设置为: " << fixed << setprecision(2) << speed << "°/ms.\n";
    else cout << "电机处于关闭状态, 请先开启电机.";
    _pause();
}

void set_acc(){  //修改电机加速度
    if(!my_motor.get_power()) {
        cout << "电机处于关闭状态, 请先开启电机.\n";
        _pause();
        return;
    }
    double acc;
    cout << "请输入设置加速度(单位: °/ms²):\n";
    cin >> acc;
    if(my_motor.set_acc(acc)) cout << "电机加速度已成功设置为: " << fixed << setprecision(2) << acc << "°/ms².\n";
    else cout << "电机处于关闭状态，请先开启电机.";
    _pause();
}

void get_status(){  //查看电机状态
    if(!my_motor.get_power()) cout << "电机处于关闭状态.\n";
    else {
        cout << "电机处于运行状态.\n";
        cout << "电机相位: " << fixed << setprecision(2) << my_motor.get_position() << "°.\n";
        cout << "电机速度: " << fixed << setprecision(2) << my_motor.get_speed() << "°/ms.\n";
        cout << "电机加速度: " << fixed << setprecision(2) << my_motor.get_acc() << "°/ms².\n";
    }
    _pause();
}

void get_direction(){  //查看电机旋转方向
    if(!my_motor.get_power()) {
        cout << "电机处于关闭状态, 请先开启电机.\n";
        _pause();
        return;
    }
    cout << "当前电机旋转方向为: ";
    if(my_motor.get_speed() > 0) cout << "逆时针";
    else cout << "顺时针"; 
    cout << "\n";
    _pause();
}

void change_direction(){  //改变电机旋转方向
    if(!my_motor.get_power()) {
        cout << "电机处于关闭状态, 请先开启电机.\n";
        _pause();
        return;
    }
    cout << "当前电机旋转方向为: ";
    if(my_motor.get_speed() > 0) cout << "逆时针";
    else cout << "顺时针"; 
    cout << "\n";
    while(1){   
        cout << "是否改变电机旋转方向? [Y/n]\n";
        char option;
        cin >> option;
        if(option == 'Y' || option == 'y'){
            my_motor.set_speed(-my_motor.get_speed());
            cout << "电机旋转方向已成功修改为: ";
            if(my_motor.get_speed() > 0) cout << "逆时针";
            else cout << "顺时针"; 
            cout << "\n";
            break;
        }
        else if(option == 'N' || option == 'n'){
            return;
        }
        else{
            cout << "无效指令, 请确认后重新输入. \n";
        }
    }
    _pause();
}

int main(){
    UI my_ui;
    my_ui.push_back(stop_motor, "关闭电机");
    my_ui.push_back(start_motor, "开启电机");
    my_ui.push_back(set_position, "设置电机相位");
    my_ui.push_back(set_speed, "修改电机速度");
    my_ui.push_back(set_acc, "修改电机加速度");
    my_ui.push_back(get_status, "查看电机状态");
    my_ui.push_back(get_direction, "查看电机旋转方向");
    my_ui.push_back(change_direction, "改变电机旋转方向");
    while(1){
        cls();
        cout << "-------------------------------\n输入对应序号操作或查看电机:\n";
        my_ui.display();
        cout << "\n-------------------------------\n";
        cout << "输入-1退出.\n";
        int tmp;
        cin >> tmp;
        if(tmp == -1){
            cls();
            break;
        }
        else if(tmp < 0 || tmp > my_ui.size() - 1) {
            cls();
            cout << "无效指令, 请确认后重新输入. \n";
            _pause();
        }
        else{
            my_ui.excute(tmp);
        }
    }
    return 0;
}

