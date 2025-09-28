# Бинарная куча
import heapq
heap = []
heapq.heappush(heap, 5)

# Собственная реализация
class BinaryHeap:
    def __init__(self):
        self.heap = []

# Встроенная хэш-таблица
hash_table = {}
hash_table["key"] = "value"

# Собственная реализация
class HashTable:
    def __init__(self, size):
        self.table = [None] * size
