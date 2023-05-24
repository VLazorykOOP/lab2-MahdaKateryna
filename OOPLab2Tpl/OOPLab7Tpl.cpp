#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


#include "Task1lab7.h"
#include "Task2lab7.h"
#include "Task3lab7.h"
#include "Task4lab7.h"


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
    size = 5; 
    int* randomArray = new int[size];
    for (int i = 0; i < size; i++) {
        randomArray[i] = std::rand() % 100; // Генеруємо випадкове число в діапазоні 0-99
    }
    min = findMinimum(randomArray, size);
    std::cout << "Min random element: " << min << std::endl;
    delete[] randomArray;
    
    std::cin.get();
}

void menutask2()
{
    const int size = 5;
    const char* arr[size] = { "first", "second", "third", "fourth", "fifth" };

    bubbleSort(arr, size);
    std::cout << "Sort mas: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Пошук елемента "first"
    const char* key = "first";
    int index = binarySearch(arr, size, key);
    if (index != -1) {
        std::cout << "Element " << key << " find on the position: " << index << std::endl;
    }
    else {
        std::cout << "Element " << key << " dont find" << std::endl;
    }
}

void menutask3()
{
    Matrix<int> mat1(2, 2);
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    Matrix<int> mat2(2, 2);
    mat2[0][0] = 5;
    mat2[0][1] = 6;
    mat2[1][0] = 7;
    mat2[1][1] = 8;

    // Додавання матриць
    Matrix<int> mat3 = mat1 + mat2;

    // Виведення результату
    for (int i = 0; i < mat3.getRow(); ++i) {
        for (int j = 0; j < mat3.getCol(); ++j) {
            std::cout << mat3[i][j] << " ";
        }
        std::cout << std::endl;
    }
   
}


void menutask4()
{
    List<int> myList;
    myList.add(1);
    myList.add(2);
    myList.add(3);

    // Прохід по списку за допомогою ітератора
    List<int>::ListIterator it = myList.begin();
    while (it.hasNext()) {
        std::cout << it.next() << " ";
    }
    std::cout << std::endl;
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
        case '2': menutask2();   break;
        case '3': menutask3();   break;
        case '4': menutask4();   break;
        case '5': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');

    return 0;
}
