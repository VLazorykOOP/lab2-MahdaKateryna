#include <iostream>

// ������� ���������� ����������
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� �������� ������
template <typename T>
int binarySearch(const T arr[], int size, const T& key) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (strcmp(arr[m], key) == 0) {
            return m; // �������� ������� �������
        }
        else if (strcmp(arr[m], key) < 0) {
            l = m + 1; // ������� ������� ����������� � ����� �������
        }
        else {
            r = m - 1; // ������� ������� ����������� � ��� �������
        }
    }

    return -1; // ������� ������� �� ��������
}