// ИНТЕРПОЛИРУЮЩИЙ ПОИСК 
// Сложность: O(log log n) время, O(1) память
public class InterpolationSearch {
    public static int interpolationSearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        
        // Проверяем, что target в пределах массива и границы валидны
        while (low <= high && target >= arr[low] && target <= arr[high]) {
            // Если остался один элемент
            if (low == high) {
                if (arr[low] == target) return low;
                return -1;
            }
            
            // Вычисляем позицию с помощью интерполяционной формулы
            int pos = low + (((high - low) * (target - arr[low])) / (arr[high] - arr[low]));
            
            if (arr[pos] == target)
                return pos;           // Элемент найден
            else if (arr[pos] < target)
                low = pos + 1;        // Ищем в правой части
            else
                high = pos - 1;       // Ищем в левой части
        }
        return -1;  // Элемент не найден
    }
}


// ПОИСК ФИБОНАЧЧИ
// Сложность: O(log n) время, O(1) память
public class FibonacciSearch {
    public static int fibonacciSearch(int[] arr, int target) {
        int n = arr.length;
        int fibMMm2 = 0;     // F(k-2)
        int fibMMm1 = 1;     // F(k-1)
        int fibM = fibMMm2 + fibMMm1;  // F(k)
        
        // Находим наименьшее число Фибоначчи, большее или равное n
        while (fibM < n) {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM = fibMMm2 + fibMMm1;
        }
        
        int offset = -1;  // Индекс начала текущего диапазона
        
        while (fibM > 1) {
            // Проверяем элемент на позиции i
            int i = Math.min(offset + fibMMm2, n - 1);
            
            if (arr[i] < target) {
                // Сдвигаемся вправо, уменьшаем числа Фибоначчи
                fibM = fibMMm1;
                fibMMm1 = fibMMm2;
                fibMMm2 = fibM - fibMMm1;
                offset = i;
            } else if (arr[i] > target) {
                // Сдвигаемся влево, уменьшаем числа Фибоначчи
                fibM = fibMMm2;
                fibMMm1 = fibMMm1 - fibMMm2;
                fibMMm2 = fibM - fibMMm1;
            } else {
                return i;  // Элемент найден
            }
        }
        
        // Проверяем последний элемент
        if (fibMMm1 == 1 && offset + 1 < n && arr[offset + 1] == target)
            return offset + 1;
            
        return -1;  // Элемент не найден
    }
}


// СОРТИРОВКА ВЫБОРОМ 
// Сложность: O(n²) время, O(1) память
public class SelectionSort {
    public static void selectionSort(int[] arr) {
        int n = arr.length;
        
        // Проходим по всем элементам массива
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;  // Предполагаем, что текущий элемент минимальный
            
            // Ищем минимальный элемент в оставшейся части массива
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;  // Нашли новый минимальный элемент
                }
            }
            
            // Меняем местами найденный минимальный элемент с текущим
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}


// СОРТИРОВКА СЛИЯНИЕМ 
// Сложность: O(n log n) время, O(n) память
public class MergeSort {
    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            // Находим середину массива
            int mid = left + (right - left) / 2;
            
            // Рекурсивно сортируем левую и правую половины
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Сливаем отсортированные половины
            merge(arr, left, mid, right);
        }
    }
    
    private static void merge(int[] arr, int left, int mid, int right) {
        // Размеры временных массивов
        int n1 = mid - left + 1;  // Левый подмассив
        int n2 = right - mid;     // Правый подмассив
        
        // Создаем временные массивы
        int[] leftArr = new int[n1];
        int[] rightArr = new int[n2];
        
        // Копируем данные во временные массивы
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];
            
        // Сливаем временные массивы обратно в arr[]
        int i = 0, j = 0, k = left;  // i - индекс leftArr, j - rightArr, k - arr
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];  // Берем элемент из левого массива
                i++;
            } else {
                arr[k] = rightArr[j];  // Берем элемент из правого массива
                j++;
            }
            k++;
        }
        
        // Копируем оставшиеся элементы leftArr (если есть)
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        
        // Копируем оставшиеся элементы rightArr (если есть)
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
}
