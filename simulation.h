#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <vector>

struct SimulationStep {
    double time;
    double position;
    double speed;
};

void menu();
int Input();
double InputDouble();
double InputAnyDouble();
double InputPositiveDouble();
void printTable(const std::vector<SimulationStep>& results);
void saveToFile(const std::vector<SimulationStep>& results);
void InputConstant(int number);

#endif
