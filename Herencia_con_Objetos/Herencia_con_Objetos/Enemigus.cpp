#include "Personaje.h"
#include <Windows.h>
using namespace std;

//CONSTRUCTOR
Personaje::Personaje() {

}
Personaje::Personaje(string pName, int pHP, int pAttack) {
	name = pName;
	HP = pHP;
	attack = pAttack;
}

// ---------------------------------------------------------------------- \\

class EnemigoFinal : public Personaje {
private: 
	int SuperAttack;
	int CataclismAttack;

public:
	EnemigoFinal(string pName, int pHP, int pAttack, int pSuperAttack, bool pCataclismAttack);

	int getSuperAttack();
	int getCataclismAttack();

	void setSuperAttack();
	void setCataclismAttack();
};

// ---------------------------------------------------------------------- \\

//GETTERS
string Personaje::getName() {
	return name;
}
int Personaje::getHP() {
	return HP;
}
int Personaje::getAttack() {
	return attack;
}

//SETTERS
void Personaje::setName(string pName) {
	name = pName;
}
void Personaje::setHP(int pHP) {
	HP = pHP;
}
void Personaje::setAttack(int pAttack) {
	attack = pAttack;
}

//METHODS
void Personaje::printStats() {
	cout << "El nombre del personaje es " << getName() << "y sus estadisticas son las siguientes " << getHP() << " y " << getAttack() << endl;
}
