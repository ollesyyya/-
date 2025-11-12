def greedy_max_cut(edges, num_vertices):
    """
    Жадный алгоритм для задачи о максимальном разрезе
    """
    # Инициализация двух пустых множеств для групп вершин
    groupA = set()
    groupB = set()
    
    # Обрабатываем вершины по порядку (как в Vertex Cover)
    for vertex in range(num_vertices):
        countA = 0  # Счетчик соседей в группе A
        countB = 0  # Счетчик соседей в группе B
        
        # Считаем соседей в каждой группе
        for u, v in edges:
            # Проверяем инцидентность ребра текущей вершине
            if u == vertex:
                if v in groupA: countA += 1
                if v in groupB: countB += 1
            elif v == vertex:
                if u in groupA: countA += 1
                if u in groupB: countB += 1
        
        # Жадный выбор: добавляем в группу с меньшим количеством соседей
        if countA <= countB:
            groupA.add(vertex)
        else:
            groupB.add(vertex)
    
    # Подсчет ребер в разрезе (ребер между группами)
    cut_size = 0
    for u, v in edges:
        # Проверяем, соединяет ли ребро разные группы
        if (u in groupA and v in groupB) or (u in groupB and v in groupA):
            cut_size += 1
    
    # Возвращаем группы вершин и количество ребер в разрезе
    return list(groupA), list(groupB), cut_size

# Тестирование алгоритма
# Входные данные: граф с 8 вершинами и 15 ребрами
edges = [(0,1), (0,2), (0,3), (1,2), (1,4), (2,3), (2,5), 
         (3,6), (4,5), (4,7), (5,6), (5,7), (6,0), (6,7), (3,7)]
num_vertices = 8

# Выполнение алгоритма
groupA, groupB, cut_size = greedy_max_cut(edges, num_vertices)

# Вывод результатов
print("Группа A:", sorted(groupA))
print("Группа B:", sorted(groupB))
print("Количество ребер в разрезе:", cut_size)
