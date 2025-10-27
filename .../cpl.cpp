// БЫСТРАЯ СОРТИРОВКА
// Сложность: O(n log n) время, O(log n) память
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Выбираем последний элемент как опорный
    int i = low - 1;        // Индекс для элемента, который меньше опорного
    
    // Проходим по массиву и перемещаем элементы меньше опорного влево
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Меняем местами меньший элемент
        }
    }
    swap(arr[i + 1], arr[high]);  // Ставим опорный элемент на правильную позицию
    return i + 1;  // Возвращаем индекс опорного элемента
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Разделяем массив и получаем индекс опорного элемента
        int pi = partition(arr, low, high);
        // Рекурсивно сортируем левую и правую части
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


// ПИРАМИДАЛЬНАЯ СОРТИРОВКА 
// Сложность: O(n log n) время, O(1) память
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;        // Инициализируем корень как наибольший
    int left = 2 * i + 1;   // Левый потомок
    int right = 2 * i + 2;  // Правый потомок
    
    // Если левый потомок больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // Если правый потомок больше текущего наибольшего
    if (right < n && arr[right] > arr[largest])
        largest = right;
        
    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Меняем местами
        heapify(arr, n, largest);    // Рекурсивно преобразуем затронутую кучу
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    
    // Построение max-heap (перестраиваем массив в кучу)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        
    // Извлекаем элементы из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Перемещаем текущий корень в конец
        heapify(arr, i, 0);    // Вызываем heapify на уменьшенной куче
    }
}


// СОРТИРОВКА ВСТАВКАМИ 
// Сложность: O(n²) время, O(1) память
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    // Начинаем со второго элемента (индекс 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Текущий элемент для вставки
        int j = i - 1;     // Индекс предыдущего элемента
        
        // Сдвигаем элементы большие key вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // Сдвигаем элемент
            j--;
        }
        arr[j + 1] = key;  // Вставляем key на правильную позицию
    }
}
