#pragma once
#include <iostream>


using namespace std;

template <typename T> class Deque
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
		Node(T data, Node* prv = nullptr, Node* nxt = nullptr);
	};
	int count;
	Node* head;
	Node* tail;
	void clear();// Очищает весь список

public:

	Deque();//создание списка
	Deque(const Deque<T>& rhs);// конструктор копирования
	Deque& operator=(const Deque<T>& rhs);//оператор присваивания
	virtual ~Deque();// Очистка памяти, удаление списка
	int size() const;// Возвращает количество элементов в списке
	void push_front(T newData);// Добавление элемента в начало
	void push_back(T newData);// Добавление элемента в конец
	T pop_back();// Удаление с конца
	T pop_front();// Удаление с начала
	void print_all(bool isPrintReversed = false, ostream& ost = cout) const 
	{
		if (isPrintReversed == false)
		{
			ost << "Список:" << endl;
			for (auto current = head; current != nullptr; current = current->next)
			{
				ost << current->data << '\n';
			}
		}
		else
		{
			ost << "Список reverse:" << endl;
			for (auto current = tail; current != nullptr; current = current->prev)
			{
				ost << current->data << '\n';
			}
		}

	}
	// Выводит список на экран, если передать true выведет список в обратном порядке 
	friend ostream& operator<<(ostream& ost, const Deque<T>& value)
	{
		ost << "Список :\n";
		for (auto current = value.head; current != nullptr; current = current->next)
		{
			ost << current->data << '\n';
		}
		return ost;
	}
	//оператор вывода
};