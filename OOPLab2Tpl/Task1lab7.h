
template <typename T>
T findMinimum(T* array, int size) {
    T min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

// Специфікація функції-шаблон для типу char*
template <>
const char* findMinimum<const char*>(const char** array, int size) {
    const char* min = array[0];
    for (int i = 1; i < size; i++) {
        if (strcmp(array[i], min) < 0) {
            min = array[i];
        }
    }
    return min;
}



