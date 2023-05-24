#include <iostream>

template <typename T>
class Matrix {
private:
    int row; // �-��� �����
    int col; // �-��� ��������
    T** data; // ���������� ����� ��� ���������� �����

public:
    Matrix() : row(0), col(0), data(nullptr) {}
    Matrix(int row, int col) : row(row), col(col) {
        
        data = new T * [row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[col];
        }
    }

    // ����������� ���������
    Matrix(const Matrix& other) : row(other.row), col(other.col) {
        // �������� ���'�� ��� ���������� ����� �� ��������� �������
        data = new T * [row];
        for (int i = 0; i < row; ++i) {
            data[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // ����������
    ~Matrix() {
      
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // �������������� �������� ���������
    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        // ��������� ����� ���'��
        for (int i = 0; i < row; ++i) {
            delete[] data[i];
        }
        delete[] data;

        // �������� ���� ���'�� �� ��������� �������
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

    // �������������� �������� ������� �� �������� �������
    T* operator[](int rowIndex) {
        return data[rowIndex];
    }

    
    int getRow() const {
        return row;
    }

   
    int getCol() const {
        return col;
    }

    // �������������� �������� ��������� ���� �������
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

    // �������������� �������� ��������� �� ���������
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

