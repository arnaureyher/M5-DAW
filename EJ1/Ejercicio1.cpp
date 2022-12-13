// Ejercicio1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#pragma comment(lib, "winmm")

using namespace std;

//Atributos del enemigo
int enemyHP = 300;
int enemyDamage;
string enemyName = "Kalegos";
bool enemyIsAlive = true;

//Atributos del enemigo 2
int enemyHP2 = 200;
int enemyDamage2;
string enemyName2 = "Neltharion";
bool enemyIsAlive2 = true;

//Atributos del heroe
int heroHP = 500;
string heroName = "Arnau";
bool heroIsAlive = true;

//Ataques del heroe
int punyo = 20;
int bolaDeFuego = 75;
int cataclismo = 200;

//Pociones
int salud = 100;

int danyorealizado;
int opcionWhoAttack;

//Inicio
void gameStart() {
	cout << "Atravesando las montanyas del abismo te encuentras a " << enemyName << " junto a " << enemyName2 << " estos te retan a un combate\n";
	cout << heroName << " se encuentra solo en esta batalla, sera capaz de batir a sus enemigos\n";
	cout << enemyName << " tiene " << enemyHP << " de vida\n";
	cout << enemyName2 << " tiene " << enemyHP2 << " de vida\n";
}

int enemyDPS() {
	srand(time(NULL));
	enemyDamage = rand() % 51 + 1;
	return enemyDamage;
}
int enemyDPS2() {
	enemyDamage2 = rand() % 71 + 11;
	return enemyDamage2;
}

void opcionATK(){
	int opcionAtaque;
	cout << "Seleciona el ataque que deseas realizar " << "\n";
	cout << "[1] Punyetazo " << "\n";
	cout << "[2] Bola de fuego " << "\n";
	cout << "[3] Cataclismo " << "\n";
	cout << "[4] Pocion de salud " << "\n";
	cout << "Opcion: ";
	cin >> opcionAtaque;

	if (opcionAtaque == 1) {
		cout << "Elegiste punyo, hace " << punyo << " de danyo\n";
		danyorealizado = punyo;
	}
	else if (opcionAtaque == 2) {
		cout << "Elegiste bola de fuego, hace " << bolaDeFuego << " de danyo\n";
		danyorealizado = bolaDeFuego;
	}
	else if (opcionAtaque == 3) {
		cout << "Elegiste cataclismo, hace " << cataclismo << " de danyo\n";
		danyorealizado = cataclismo;
	}
	else if (opcionAtaque == 4) {
		cout << "Elegiste salud, obtienes " << salud << " de vida\n";
		heroHP + salud;
	}

}

int whoAttack() {
	cout << "A quien deseas atacar? \n[1] Kalegos \n[2] Neltharion\n";
	cout << "Opcion: ";
	cin >> opcionWhoAttack;
	if (opcionWhoAttack == 1) {
		if (enemyIsAlive == true) {
			enemyHP = enemyHP - danyorealizado;
		}
		else {
			enemyHP2 = enemyHP2 - danyorealizado;
		}
	}
	else if (opcionWhoAttack == 2) {
		if (enemyIsAlive2 == true) {
			enemyHP2 = enemyHP2 - danyorealizado;
		}
		else {
			enemyHP = enemyHP - danyorealizado;
		}
	}
	return opcionWhoAttack;
}

bool enemyStatus() {
	if (enemyHP <= 0) {
		cout << "El enemigo " << enemyName << " ha muerto \n";
		return false;
	}

	else {
		cout << "El enemigo " << enemyName << " le quedan " << enemyHP << "\n";
		return true;
	}	
}
bool enemyStatus2() {
	if (enemyHP2 <= 0) {
		cout << "El enemigo " << enemyName2 << " ha muerto \n";
		return false;
	}

	else {
		cout << "El enemigo " << enemyName2 << " le quedan " << enemyHP2 << "\n";
		return true;
	}
}

int enemyATK() {
	heroHP = heroHP - enemyDamage;
	return heroHP;
}
int enemyATK2() {
	heroHP = heroHP - enemyDamage2;
	return heroHP;
}

bool heroStatus() {
	if (heroHP <= 0) {
		cout << enemyName << " te ha matado\n";
		return false;
	}
	else {
		cout << enemyName << " te ha hecho " << enemyDamage << " de danyo y te quedan " << heroHP << " puntos de vida\n";
		return true;
	}

}

bool heroStatus2() {
	if (heroHP <= 0) {
		cout << enemyName2 << " te ha matado\n";
		return false;
	}
	else {
		cout << enemyName2 << " te ha hecho " << enemyDamage2 << " de danyo y te quedan " << heroHP << " puntos de vida\n";
		return true;
	}

}

int main() {
	PlaySound(TEXT("doom.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

	gameStart();

	while ((enemyIsAlive == true || enemyIsAlive2 == true) && heroIsAlive == true)	{
		enemyDPS();
		enemyDPS2();
		opcionATK();
		whoAttack();
		enemyIsAlive = enemyStatus();
		if (enemyIsAlive == true) {
			enemyATK();
			heroIsAlive = heroStatus();
		}	
		enemyIsAlive2 = enemyStatus2();
		if (enemyIsAlive2 == true) {
			enemyATK();
			heroIsAlive = heroStatus2();
		}

	}
}