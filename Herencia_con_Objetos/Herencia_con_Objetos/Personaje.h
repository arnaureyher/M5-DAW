#pragma once
using namespace std;
#include <iostream>

class Personaje {
private:
	string name;
	int HP;
	int attack;

public:
	//CONSTRUCTOR
	Personaje();
	Personaje(string pName, int pHP, int pAttack);

	//GETTERS
	string getName();
	int getHP();
	int getAttack();

	//SETTERS
	void setName(string pName);
	void setHP(int pHP);
	void setAttack(int pAttack);

	//METHODS
	void printStats();

};

