#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


#include "Task1.h"

using namespace std;

void menutask1()
{
    // Введення початкових даних з клавіатури
    std::cout << "Input size of the array: ";
    int size;
    std::cin >> size;
    int* array = new int[size];
    std::cout << "Input elements of the array: ";
    for (int i = 0; i < size; i++) {
        std::cin >> array[i];
    }
    int min = findMinimum(array, size);
    std::cout << "Min element: " << min << std::endl;
    delete[] array;


    // Введення початкових даних використовуючи датчик випадкових чисел
    std::srand(std::time(0));
    size = 5; // Задаємо розмір масиву
    int* randomArray = new int[size];
    for (int i = 0; i < size; i++) {
        randomArray[i] = std::rand() % 100; // Генеруємо випадкове число в діапазоні 0-99
    }
    min = findMinimum(randomArray, size);
    std::cout << "Min random element: " << min << std::endl;
    delete[] randomArray;
    
    std::cin.get();
}

int main()
{

    char ch = '5';
    do {
        system("cls");
        cout << "1  Task1\n";
        cout << "2  Task2\n";
        cout << "3  Task3\n";
        cout << "4  Task4\n";
        cout << "5  Exit\n";
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': menutask1();   break;
        case '2': //menutask2();   break;
        case '3': //menutask3();   break;
        case '4': //menutask4();   break;
        case '5': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');

    return 0;
}
