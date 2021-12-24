#include <iostream>
#include "Deque.cpp"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	try
	{
		cout << "Тип int" << endl;
		Deque<int> deq_int;
		deq_int.push_back(1);
		deq_int.push_back(2);
		deq_int.push_back(3);
		deq_int.push_back(4);
		deq_int.push_front(0);
		deq_int.print_all();
		deq_int.print_all(true);//обратная печать
		cout << "Работа скопированного списка:" << endl;
		auto tmp = deq_int;
		cout << tmp;//вывод через оператор вывода
		cout << "Достали из головы:" << tmp.pop_front() << endl;
		cout << "Достали из хвоста:" << tmp.pop_back() << endl;
		cout << "В деке сейчас:" << tmp.size() << " штук" << endl;
		tmp.print_all();
		tmp.print_all(true);
		cout << "Прежний список остался таким же:" << endl;
		deq_int.print_all();
		deq_int.print_all(true);
		deq_int.~Deque();
		tmp.~Deque();

		cout << "Тип float" << endl;
		Deque<float> deq_float;
		deq_float.push_front(1.1);
		deq_float.push_front(2.1);
		deq_float.push_front(3.1);
		deq_float.push_front(4.1);
		deq_float.push_back(555);
		deq_float.print_all();
		deq_float.print_all(true);//обратная печать
		cout << "В деке сейчас:" << deq_float.size() << " штук" << endl;
		cout << "Достали из головы:" << deq_float.pop_front() << endl;
		cout << "Достали из хвоста:" << deq_float.pop_back() << endl;
		cout << "В деке сейчас:" << deq_float.size() << " штук" << endl;
		deq_float.print_all();
		deq_float.~Deque();

		cout << "Тип const char*" << endl;
		Deque<const char*> deq_char;
		deq_char.push_back("aa,");
		deq_char.push_back("bb9l");
		deq_char.push_back("cc=");
		deq_char.push_front("dd1");
		char aaa[] = "Ворохобко";
		deq_char.push_front(aaa);
		deq_char.print_all();
		deq_char.print_all(true);//обратная печать
		aaa[0] = 'Б';
		cout <<"Моя новая фамилия: "<< aaa << '\n';//новая фамилия
		cout << "В списке моя старая фамилия!!! ";
		deq_char.print_all();//тут осталась старая!!!!!!!!!!!!!!!
		cout << "В деке сейчас:" << deq_char.size() << " штук" << endl;
		cout << "Достали из головы:" << deq_char.pop_front() << endl;
		cout << "Достали из хвоста:" << deq_char.pop_back() << endl;
		cout << "В деке сейчас:" << deq_char.size() << " штук" << endl;
		deq_char.print_all();
		deq_char.~Deque();
		cout << "после удаления ";
		deq_char.print_all();

		Deque<int> deq_int1;
		deq_int1.pop_back();
	}
	catch (exception& e)
	{
		cout << "я словил исключение: " << e.what();
	}
}
