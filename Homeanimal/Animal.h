#pragma once
#include<iostream>

using namespace std;


class Animal
{
protected:
	string _Name;
public:
	Animal(string n) : _Name(n) {}
	
	void Showname() { cout << _Name << endl;; }
		
};

class Dog :public Animal
{
public:
	Dog(string name) : Animal(name) {}
	void show() {
		cout << _Name << "\tГоворит гав - гав";
	}
};

class Cat:public Animal
{
public:
	Cat(string name) : Animal(name) {}
	void show() {
		cout << _Name << "\tГоворит мяу - мяу";
	}
};

class Aparrot:public Animal
{
public:
	Aparrot(string name) : Animal(name) {}
	void show() {
		cout << _Name << "\tГоворит угу - кря";
	}
};

