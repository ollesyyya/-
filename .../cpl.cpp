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
