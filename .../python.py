# БИНАРНЫЙ ПОИСК 
# Сложность: O(log n) время, O(1) память
def binary_search(arr, target):
    left, right = 0, len(arr) - 1  # Инициализируем границы поиска
    
    while left <= right:
        mid = left + (right - left) // 2  # Находим середину (без переполнения)
        
        if arr[mid] == target:
            return mid           # Элемент найден
        elif arr[mid] < target:
            left = mid + 1       # Ищем в правой половине
        else:
            right = mid - 1      # Ищем в левой половине
    
    return -1  # Элемент не найден


# ЛИНЕЙНЫЙ ПОИСК 
# Сложность: O(n) время, O(1) память
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Возвращаем индекс при нахождении
    return -1  # Элемент не найден


# СОРТИРОВКА ШЕЛЛА 
# Сложность: O(n log² n) время, O(1) память
def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # Начальный интервал
    
    while gap > 0:
        # Сортируем элементы на расстоянии gap (аналог insertion sort с шагом gap)
        for i in range(gap, n):
            temp = arr[i]  # Сохраняем текущий элемент
            j = i
            
            # Сдвигаем элементы, пока не найдем правильную позицию для temp
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]  # Сдвигаем элемент вправо
                j -= gap
            
            arr[j] = temp  # Вставляем сохраненный элемент
        gap //= 2  # Уменьшаем интервал


# СОРТИРОВКА ОБМЕНОМ (пузырьковая)
# Сложность: O(n²) время, O(1) память
def bubble_sort(arr):
    n = len(arr)
    
    for i in range(n - 1):
        swapped = False  # Флаг для оптимизации (если нет обменов - массив отсортирован)
        
        # Проходим по массиву, сравнивая соседние элементы
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Меняем местами
                swapped = True
        
        if not swapped:
            break  # Выходим раньше, если массив уже отсортирован
