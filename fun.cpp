#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <vector>
#include "simulation.h"

int Input() {
    using namespace std;
    int value;
    while (!(cin >> value)) {
        cout << "Ошибка! Введите целое число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

double InputAnyDouble() {
    using namespace std;
    double value;
    while (!(cin >> value)) {
        cout << "Ошибка! Введите корректное число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

double InputPositiveDouble() {
    using namespace std;
    while (true) {
        double value = InputAnyDouble();
        if (value > 0) {
            return value;
        } else {
            cout << "Ошибка! Это значение должно быть строго больше 0." << endl;
        }
    }
}

double InputDouble() {
    using namespace std;
        double value;
        while (true) {
            if (cin >> value && value > 0) {
                return value;
            } else {
                cout << "Ошибка! Значение должно быть числом больше 0." << endl;
                cout << "Введите значение заново: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
}


void printTable(const std::vector<SimulationStep>& results) {
    using namespace std;
    cout << endl << left << setw(10) << "Time" 
            << setw(10) << "Pos" 
            << setw(10) << "Speed" << "\n";

    for (const auto& step : results) {
        cout << left << setw(10) << step.time 
                << setw(10) << step.position 
                << setw(10) << step.speed << "\n";
    }
}

void saveToFile(const std::vector<SimulationStep>& results) {
    using namespace std;
    ofstream outFile("out.txt");
    if (!outFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    outFile << left << setw(10) << "Time" 
            << setw(10) << "Pos" 
            << setw(10) << "Speed" << "\n";

    for (const auto& step : results) {
        outFile << left << setw(10) << step.time 
                << setw(10) << step.position 
                << setw(10) << step.speed << "\n";
    }
}   

void InputConstant(int number) {
    using namespace std;
    switch(number){
        case(1):{
            cout << "Введите начальную высоту (м): ";
            double y = InputDouble();
            cout << "Введите массу тела (кг): ";
            double m = InputDouble();
            cout << "Введите коэф. сопротивления k (обычно 0.1 - 0.5): "; 
            double k = InputDouble();
            cout << "площадь поперечного сечения тела, перпендикулярная направлению движения (м²): ";
            double s = InputDouble();
            cout << "Введите шаг времени dt (сек): ";
            double dt = InputDouble();
            cout << "Введите общее время (сек): ";
            double totalTime = InputDouble();

            vector<SimulationStep> results;
            double v = 0.0;
            double currentTime = 0.0;
            const double g = 9.81;
            const double r = 1.25;

            while (currentTime <= totalTime && y > 0) {
                    results.push_back({currentTime, y, abs(v)});

                    double a = - g + (k * r * s) / (2 * m) * abs(v) * abs(v); 
                    y = y + v * dt + 0.5 * a * dt * dt;
                    v = v + a * dt;

                    currentTime += dt;

                    if (y <= 0) {
                        y = 0;
                        v = 0.0;
                        results.push_back({currentTime, y, abs(v)});
                        break;
                    }
                }

            printTable(results);
            saveToFile(results);
            break;
        }
        case(2):{
            cout << "--- Модель пружинного маятника ---" << endl;
            cout << "Введите жесткость пружины k (Н/м): ";
            double k = InputDouble();
            cout << "Введите массу груза m (кг): ";
            double m = InputDouble();
            cout << "Введите начальное смещение x (м): ";
            double x = InputDouble();
            cout << "Введите шаг времени dt (сек, рекомендую 0.01): ";
            double dt = InputDouble();
            cout << "Введите общее время (сек): ";
            double totalTime = InputDouble();

            vector<SimulationStep> results;
            double v = 0.0;
            double currentTime = 0.0;

            while (currentTime <= totalTime) {
                results.push_back({currentTime, x, v});

                double a = -(k / m) * x;

                x = x + v * dt + 0.5 * a * dt * dt;
                v = v + a * dt;
                currentTime += dt;
            }

            printTable(results);
            saveToFile(results);
            break;
        }
        case(3):{
            cout << "Введите начальную позицию (м): ";
            double x = InputPositiveDouble();
            cout << "Введите начальную скорость (м/с): ";
            double v = InputDouble();
            cout << "Введите ускорение (м/с^2): ";
            double a = InputDouble();
            cout << "Введите шаг времени (сек): ";
            double dt = InputDouble();
            cout << "Введите общее время симуляции (сек): ";
            double totalTime = InputDouble();

            vector<SimulationStep> results;
            double currentTime = 0;

            while (currentTime <= totalTime) {
                results.push_back({currentTime, x, v});
                
                x = x + v * dt + 0.5 * a * dt * dt;
                v = v + a * dt;
                currentTime += dt;
            }

            printTable(results);
            saveToFile(results);
            break;
        }
        case(4):{
            cout << "Введите величину заряда q (Кулон): ";
            double q = InputAnyDouble();
            cout << "Введите массу частицы m (кг): ";
            double m = InputDouble();
            cout << "Введите напряженность поля E (В/м): ";
            double E = InputDouble();
            cout << "Введите начальную позицию (м): ";
            double x = InputPositiveDouble();
            cout << "Введите шаг времени dt (сек): ";
            double dt = InputDouble();
            cout << "Введите общее время (сек): ";
            double totalTime = InputDouble();

            vector<SimulationStep> results;
            double v = 0.0;
            double currentTime = 0.0;

            double a = (q * E) / m;

            while (currentTime <= totalTime) {
                results.push_back({currentTime, x, v});

                x = x + v * dt + 0.5 * a * dt * dt;
                v = v + a * dt;
                currentTime += dt;
            }

            printTable(results);
            saveToFile(results);
            break;
        }
    }
    
}






