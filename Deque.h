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
	void clear();// ������� ���� ������

public:

	Deque();//�������� ������
	Deque(const Deque<T>& rhs);// ����������� �����������
	Deque& operator=(const Deque<T>& rhs);//�������� ������������
	virtual ~Deque();// ������� ������, �������� ������
	int size() const;// ���������� ���������� ��������� � ������
	void push_front(T newData);// ���������� �������� � ������
	void push_back(T newData);// ���������� �������� � �����
	T pop_back();// �������� � �����
	T pop_front();// �������� � ������
	void print_all(bool isPrintReversed = false, ostream& ost = cout) const 
	{
		if (isPrintReversed == false)
		{
			ost << "������:" << endl;
			for (auto current = head; current != nullptr; current = current->next)
			{
				ost << current->data << '\n';
			}
		}
		else
		{
			ost << "������ reverse:" << endl;
			for (auto current = tail; current != nullptr; current = current->prev)
			{
				ost << current->data << '\n';
			}
		}

	}
	// ������� ������ �� �����, ���� �������� true ������� ������ � �������� ������� 
	friend ostream& operator<<(ostream& ost, const Deque<T>& value)
	{
		ost << "������ :\n";
		for (auto current = value.head; current != nullptr; current = current->next)
		{
			ost << current->data << '\n';
		}
		return ost;
	}
	//�������� ������
};