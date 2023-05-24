#include <iostream>

template <typename T>
class Matrix {
private:
    int row; // К-сть рядків
    int col; // К-сть стовпців
    T** data; // Двовимірний масив для збереження даних

public:
    Matrix() : row(0), col(0), data(nullptr) {}
    Matrix(int row, int col) : row(row), col(col) {
        
        data = new T * [row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[col];
        }
    }

    // Конструктор копіювання
    Matrix(const Matrix& other) : row(other.row), col(other.col) {
        // Виділення пам'яті для збереження даних та копіювання значень
        data = new T * [row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Деструктор
    ~Matrix() {
      
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Перевантажений оператор присвоєння
    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        // Звільнення старої пам'яті
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // Виділення нової пам'яті та копіювання значень
        row = other.row;
        col = other.col;
        data = new T * [row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    // Перевантажений оператор доступу до елементів матриці
    T* operator[](int rowIndex) {
        return data[rowIndex];
    }

    
    int getRow() const {
        return row;
    }

   
    int getCol() const {
        return col;
    }

    // Перевантажений оператор додавання двох матриць
    Matrix operator+(const Matrix& other) {
        if (row != other.row || col != other.col) {
            throw std::runtime_error("Rozmiri matriz ne spivpadaut.");
        }

        Matrix result(row, col);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // Перевантажений оператор додавання та присвоєння
    Matrix& operator+=(const Matrix& other) {
        if (row != other.row || col != other.col) {
            throw std::runtime_error("Rozmiri matriz ne spivpadaut.");
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                data[i][j] += other.data[i][j];
            }
        }

        return *this;
    }
};

