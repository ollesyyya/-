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

int main() {
