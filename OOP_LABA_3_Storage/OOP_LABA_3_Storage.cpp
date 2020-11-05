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
	VW_group() {
		this->power = 0;
		this->_next = NULL;
	}

	VW_group(int power) {
		this->power = power;
	}

	void setnext(VW_group* obj) {
		this->_next = obj;
	}

	VW_group* getnext() {
		return this->_next;
	}

	virtual void develope_car() {};
	virtual void outname() {};

	int get_power() {
		return power;
	}

	void set_power(int power) {
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

int main()
{
	
}