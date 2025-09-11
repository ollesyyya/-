// представление массива данных на C++
#include <iostream> #include <list>  
int main() {  
    std::list<int> myList = {1, 2, 3, 4, 5};  
    myList.push_back(6); // Добавить 6 в конец списка  
    for (int i : myList) {  
        std::cout << i << " "; // Вывод элементов списка  
    }  
    return 0;  
}  
// пример кода организации стека
#include <iostream>  
using namespace std; [6](https://tr-page.yandex.ru/translate?lang=en-ru&url=https%3A%2F%2Fwww.geeksforgeeks.org%2Fcpp%2Fstack-implementation-in-cpp%2F)  

class Stack {  
private:  
// Индекс верхнего элемента в стеке  
int top;  
// Массив для хранения элементов стека ёмкостью 100 элементов  
int arr[100];  
public:  
// Конструктор для инициализации пустого стека  
Stack() { top = -1; }  
// Функция для добавления элемента x в верхнюю часть стека  
void push(int x) {  
// Если стек заполнен, вывести «Stack overflow» и вернуть  
if (top >= 99) { cout << "Stack overflow" << endl; return; }  
// Добавить элемент в начало стека и увеличить top  
arr[++top] = x;  
cout << "pushed" << x << " to stack\n";  
}  
// Функция для удаления верхнего элемента из стека  
int pop() {  
// Если стек пуст, вывести «Stack underflow» и вернуть 0  
if (top < 0) { cout << "Stack underflow" << endl; return 0; }  
// Удалить верхний элемент из стека и уменьшить top  
return arr[top--];  
}  
// Функция для возврата верхнего элемента стека  
int peek() {  
// Если стек пуст, вывести «Стек пуст» и вернуть 0  
if (top < 0) { cout << "Стек пуст" << endl; return 0; }  
// Вернуть верхний элемент стека, вернуть arr[top];  
}  
// Функция для проверки, пуст ли стек  
bool isEmpty() {  
// Вернуть true, если стек пуст (т. е. верхний элемент — -1)  
return (top < 0);  
}  
};  
