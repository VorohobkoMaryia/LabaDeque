#include <iostream>
#include "Deque.h"
#pragma warning(disable : 4996)

using namespace std;

template <typename T>
Deque<T>::Node::Node(T data, Node* prv, Node* nxt) :data(data), next(nxt), prev(prv)
{
	if (prev != nullptr)
	{
		prv->next = this;
	}

	if (next != nullptr)
	{
		nxt->prev = this;
	}
}

template <typename T>
void Deque<T>::clear()
{
	count = 0;
	while (head)
	{
		auto tmp = head->next;
		delete head;
		head = tmp;
	}
}

template <typename T>
Deque<T>::Deque()
{
	count = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
Deque<T>::Deque(const Deque<T>& rhs)
{
	count = 0;
	for (auto current = rhs.head; current != nullptr; current = current->next)
	{
		push_back(current->data);
	}
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& rhs)
{
	count = 0;
	for (auto current = rhs.head; current != nullptr; current = current->next)
	{
		push_back(current->data);
	}

	return *this;
}

template <typename T>
Deque<T>::~Deque()
{
	clear();
}

template <typename T>
int Deque<T>::size() const
{
	return count;
}

template <typename T>
void Deque<T>::push_front(T newData)
{
	if (count == 0)
	{
		head = new Node(newData);
		tail = head;
	}
	else
	{
		head = new Node(newData, nullptr, head);//prev=nullptr,next=head
	}
	count++;
}

template <typename T>
void Deque<T>::push_back(T newData)
{
	if (count == 0)
	{
		head = new Node(newData);
		tail = head;
	}
	else
	{
		tail = new Node(newData, tail, nullptr);//prev=tail,next=nullptr
	}
	count++;
}

template <typename T>
T Deque<T>::pop_back()
{
	if (count == 0)
	{
		throw exception("Пустой дек. Не могу извлечь последний элемент.");
	}
	auto tmp = tail; //запомнили адрес хвоста, чтоб потом осовбодить память
	auto datum = tail->data; //запомнили данные. которые там лежали
	if (count == 1) 
	{
		tail = head = nullptr;
		delete tmp;
	}
	else 
	{
		tail = tmp->prev;
		tail->next = nullptr;
		delete tmp;
	}
	count--;
	return datum;
}

template <typename T>
T Deque<T>::pop_front()
{
	if (count == 0)
	{
		throw exception("Пустой дек. Не могу извлечь последний элемент.");
	}
	auto tmp = head; //запомнили адрес начала, чтоб потом осовбодить память
	auto datum = head->data; //запомнили данные. которые там лежали
	if (count == 1)
	{
		tail = head = nullptr;
		delete tmp;
	}
	else
	{
		head = tmp->next;
		head->prev = nullptr;
		delete tmp;
	}
	count--;
	return datum;
}
//для const char*
template <>
Deque<const char*>::Node::Node(const char* newData, Node* prv, Node* nxt) :data(newData), next(nxt), prev(prv)
{
	data = new char[strlen(newData) + 1];
	strcpy((char*)data, newData);
	if (prev != nullptr)
	{
		prv->next = this;
	}

	if (next != nullptr)
	{
		nxt->prev = this;
	}
}