#include <iostream>
#include "simulation.h"
#include <windows.h> 


void menu(){
    using namespace std;
    cout << "\n=== Симулятор физических процессов === \n" << endl;
    cout << "Выберите тему:" << endl;
    cout << "1) Падение тела с сопротивлением воздуха" << endl;
    cout << "2) Модель пружины (колебания)" << endl;
    cout << "3) Движение с постоянным ускорением" << endl;
    cout << "4) Движение заряда в поле" << endl;
    cout << "0) Выход" << endl;
    cout << "Введите номер темы: "; 
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    using namespace std;
    int number;
    bool running = true;

    while (running){
        menu();
        number = Input();
        cout << endl;

        switch(number){
            case(1):{
                InputConstant(1);
                break;
            }
            case(2):{
                InputConstant(2);
                break;
            }
            case(3):{
                InputConstant(3);
                break;
            }
            case(4):{
                InputConstant(4);
                break;
            }
            case(0):{
                running = false;
                cout << "Завершение работы." << endl;
                break;
            }
            default:{
                cout << "Неверный пункт меню. Попробуйте снова.\n";
            }
        }
    }

    
}