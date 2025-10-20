#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Проходим по всем элементам массива
    for (int i = 0; i < n - 1; i++) {
        // Предполагаем, что текущий элемент - минимальный
        int minIndex = i;
        
        // Ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            // Если находим элемент меньше текущего минимального
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Обновляем индекс минимального элемента
            }
        }
        
        // Меняем местами текущий элемент с найденным минимальным
        swap(arr[i], arr[minIndex]);
    }
}

int main() {// Тестовый массив
    vector<int> testArray = {64, 25, 12, 22, 11};
    
    cout << "Исходный массив: ";
    for (int num : testArray) cout << num << " ";
    cout << endl;
    
    // Сортируем массив
    selectionSort(testArray);
    
    cout << "Отсортированный массив: ";
    for (int num : testArray) cout << num << " ";
    cout << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Функция для слияния двух отсортированных массивов
void merge(vector<int>& arr, int left, int mid, int right) {
    // Размеры левого и правого подмассивов
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Создаем временные массивы
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    // Индексы для левого, правого и основного массивов
    int i = 0, j = 0, k = left;
    
    // Слияние временных массивов обратно в arr[left..right]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Копируем оставшиеся элементы leftArr
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Копируем оставшиеся элементы rightArr
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
// Рекурсивная функция сортировки слиянием
void mergeSort(vector<int>& arr, int left, int right) {
    // Базовый случай: если в массиве 1 элемент или меньше
    if (left >= right) return;
    
    // Находим середину массива
    int mid = left + (right - left) / 2;
    
    // Рекурсивно сортируем левую и правую части
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    
    // Сливаем отсортированные части
    merge(arr, left, mid, right);
}

// Обертка для вызова сортировки
void mergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    
    cout << "Исходный массив: ";
    for (int num : array) cout << num << " ";
    cout << endl;
    
    mergeSort(array);
    
    cout << "Отсортированный массив: ";
    for (int num : array) cout << num << " ";
    cout << endl;
    
    return 0;
}
