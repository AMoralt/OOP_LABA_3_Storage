#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <string>
#define cls system("cls");
using namespace std;
#pragma once

class VW_group {
private:
	int power;
	VW_group* _next;
public:
	VW_group() {//конструктор
		this->power = 0;
		this->_next = NULL;
	}

	VW_group(int power) {//конструктор с параметром
		this->power = power;
	}

	void setnext(VW_group* obj) {//задаем _next
		this->_next = obj;
	}

	VW_group* getnext() {//возвращает _next
		return this->_next;
	}

	virtual void develope_car() {};//виртуальные методы
	virtual void outname() {};

	int get_power() {//возвращаем power
		return power;
	}

	void set_power(int power) {//задаем power
		this->power = power;
	}
};

class Hyundai :public VW_group {
public:
	Hyundai() : VW_group() {}

	Hyundai(int power) : VW_group (power) {}

	void develope_car() {
		cout << "Hyundai develope new car!!\n";
	}

	void outname() {
		cout << "Hyundai obj(" << this->get_power() << ")\n";
	}
};

class Skoda : public VW_group {
public:
	Skoda() : VW_group() {}

	Skoda(int power) : VW_group(power) {}

	void develope_car() {
		cout << "Skoda develope new car!!\n";
	}

	void outname() {
		cout << "Skoda obj(" << this->get_power() << ")\n";
	}
};

class Porsche : public VW_group {
public:
	Porsche() : VW_group() {}

	Porsche(int power) : VW_group(power) {}

	void develope_car() {
		cout << "Porsche develope new car!!\n";
	}

	void outname() {
		cout << "Porsche obj(" << this->get_power() << ")\n";
	}
};

class Genesis : public Hyundai {
public:
	Genesis() : Hyundai() {}

	Genesis(int power) : Hyundai(power) {}

	void develope_car() {
		cout << "Genesis develope new car!!\n";
	}

	void outname() {
		cout << "Genesis obj(" << this->get_power() << ")\n";
	}
};

class mystorage
{
private:
	VW_group* head;//головной узел
	VW_group* next;//следующий узел
	VW_group* end;//последний узел
	int N;//кол-во
public:
	mystorage() {//конструктор
		this->head = NULL;// список пустой
		this->N = 0;//кол-во
	}

	void add(VW_group* obj) {//добавляем новый объект
		this->next = NULL;
		if (head == NULL)//если первый раз добавляем
			this->head = obj;
		else
			this->end->setnext(obj);
		this->end = obj;
		this->N++;
	}

	void addup(VW_group* obj, VW_group*& select) {

		if (select != head)
		{
			VW_group* back = head;
			First();
			while (EOL())
			{
				if (next == select)
					break;
				back = next;
				this->Next();
			}
			back->setnext(obj);
		}
		else
			head = obj;
		obj->setnext(select);
		this->N++;
	}

	void adddown(VW_group* obj, VW_group*& select) {
		VW_group* nex = select->getnext();
		if (nex != NULL)
			obj->setnext(nex);
		select->setnext(obj);
		if (end == select)
			end = obj;
		this->N++;
	}
	void First() {
		this->next = this->head;
	}

	void Next() {
		this->next = this->next->getnext();
	}

	int EOL() {
		if (next == NULL)
			return 0;
		return 1;
	}
	VW_group* getobj() {
		return this->next;
	}

	VW_group* getobj(VW_group* obj) {
		for (First(); EOL(); Next())
			if (next == obj)
				return next;
		return NULL;
	}

	void move(VW_group*& obj, string vector) {
		if (vector == "up")
		{
			if (obj != head)
			{
				VW_group* dyn1 = head;
				VW_group* dyn2 = NULL;

				First();
				while (EOL())
				{
					if (next == obj)
						break;
					dyn1 = next;
					this->Next();
				}
				First();
				while (EOL())
				{
					if (next == dyn1)
						break;
					dyn2 = next;
					this->Next();
				}
				if (dyn2 != NULL)
					dyn2->setnext(obj);
				if (dyn1 == head)
					head = obj;
				if (obj == end)
					end = dyn1;
				dyn1->setnext(obj->getnext());
				obj->setnext(dyn1);
			}
		}
		else
			if (vector == "down")
			{
				if (obj->getnext() != NULL)
				{
					VW_group* dyn1 = obj->getnext();
					if (dyn1 == end)
						end = obj;
					if (obj != head)
					{
						VW_group* dyn2 = head;
						First();
						while (EOL())
						{
							if (next == obj)
								break;
							dyn2 = next;
							this->Next();
						}

						dyn2->setnext(obj->getnext());
					}
					else
						head = obj->getnext();
					obj->setnext(dyn1->getnext());
					dyn1->setnext(obj);


				}
			}

	}

	void delobj(int n) {
		if (n <= N && n > 0)
		{
			First();
			VW_group* selobj;
			if (n > 1)
			{
				for (int i = 0; i < n - 2; i++)
					Next();
				selobj = next->getnext();
			}
			else
				selobj = next;
			VW_group* back = next;
			if (selobj == head || selobj == end)
			{
				if (selobj == head)
				{
					head = head->getnext();
					back = head;
				}
				if (selobj == end)
				{
					end = back;
					if (end != NULL)
						end->setnext(NULL);
				}
			}
			else
				back->setnext(selobj->getnext());
			this->N--;
			delete selobj;
		}
	}

	void delobj(VW_group*& selobj) {
		First();
		VW_group* back = head;
		while (EOL())
		{
			if (next == selobj)
				break;
			back = next;
			this->Next();
		}
		if (selobj == head || selobj == end)
		{
			if (selobj == head)
			{
				head = head->getnext();
				back = head;
			}
			if (selobj == end)
			{
				end = back;
				if (end != NULL)
					end->setnext(NULL);
			}
		}
		else
			back->setnext(selobj->getnext());

		delete selobj;
		this->N--;
		selobj = NULL;
	}

	int getN() {
		return this->N;
	}
};

void list_out(mystorage& storage, int ch, VW_group*& chVW_group)
{
	int i = 0;
	for (storage.First(); storage.EOL(); storage.Next())
	{
		if (ch == i)
		{
			cout << "\t->";
			chVW_group = storage.getobj();
		}
		storage.getobj()->outname();
		i++;
	}

}

void list_add(mystorage& storage, int n)
{
	for (int i = 0; i < n; i++)
	{
		int n = rand() % 200 + 150;
		switch (1 + rand() % 4) {
		case 1: {
			storage.add(new Hyundai(n));
			break;
		}
		case 2: {
			storage.add(new Skoda(n));
			break;
		}
		case 3: {
			storage.add(new Porsche(n));
			break;
		}
		case 4: {
			storage.add(new Genesis(n));
			break;
		}
		};
	}
}

void bot1(mystorage& storage)
{
	cls;
	int n;
	do {
		cout << "Введите количество элементов:\n";
		cin >> n;
	} while (!cin);
	list_add(storage, n);
} 

void bot2(mystorage& storage, VW_group* chVW_group)
{
	if (chVW_group != NULL)
	{
		cls;
		int n;
		do {
			cout << "Введите номер объекта:\n";
			cin >> n;
		} while (!cin);
		storage.delobj(n);
	}
}

void bot3(mystorage& storage, int& i, VW_group*& chVW_group)
{
	char ch;
	while (1)
	{

		cls;
		if (chVW_group == NULL)
			break;
		cout << "Объект: ";
		chVW_group->outname();
		cout << "\n1.Develope car\n2.Изменить мощность\n3.Удалить\n\n0.Назад";
		ch = _getch();
		switch (ch)
		{
		case '1': {
			cout << endl << endl;
			storage.getobj(chVW_group)->develope_car();
			Sleep(600);
			break;
		}
		case '2': {
			int n;
			cout << "\nВведите мощность: ";
			cin >> n;
			storage.getobj(chVW_group)->set_power(n);
			cout << "\nid = " << storage.getobj(chVW_group)->get_power();
			break;
		}
		case '3': {
			storage.delobj(chVW_group);
			i--;
			break;
		}
		case '0': {
			ch = 0;
			break;
		}
		}
		if (ch == 0)
			break;
	}

}

void menu_out()
{
	cout << endl;
	cout << "1.Добавить выбранное количество объектов\n";
	cout << "2.Удалить определенный объект\n";
	cout << "3.Работа с объектом\n";
	cout << "4.Добавить объект снизу\n";
	cout << "5.Добавить объект сверху\n";
	cout << "6.Переместить текущий объект вверх\n";
	cout << "7.Переместить текущий объект вниз\n";
	cout << "8.Удалить текущий объект\n";

	cout << "\nESC. ВЫХОД\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	mystorage storage;
	VW_group* chVW_group= NULL;
	int i = 0;
	char n;
	do {
		cls;
		list_out(storage, i, chVW_group);
		menu_out();
		n = _getch();
		switch (n)
		{
		case '1': {
			bot1(storage);
			break;
		}
		case '2': {
			bot2(storage, chVW_group);
			break;
		}
		case '3': {
			if (chVW_group != NULL)
				bot3(storage, i, chVW_group);
			break;
		}
		case '4': {
			
			break;
		}
		case '5': {
			
			break;
		}
		case '6': {
			
			break;
		}
		case '7': {
			
			break;
		}
		case '8': {
			
			break;
		}
		case 72: {
			if (i != 0)
				i--;
			break;
		}
		case 80: {
			if (i != storage.getN())
				i++;
			break;
		}
		}

	} while (n != 27);// esc

}