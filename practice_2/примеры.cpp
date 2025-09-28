// Бинарная куча
#include <queue>
std::priority_queue<int> maxHeap;

// Куча Фибоначчи (каркас)
template<class T>
class FibonacciHeap {
    Element<T>* min;
};

// Стандартная хэш-таблица
#include <unordered_map>
std::unordered_map<std::string, int> hash_map;

// Ручная реализация
template<typename K, typename V>
class HashTable {
    std::list<HashNode<K, V>>* table;
};
