#include "lancha.h"
#include <iostream>
#include <windows.h>
#include <iostream>
#include <stdlib.h>

void inicio(lancha& lancha1, lancha& lancha2) {
	std::cout << "Estos son los corredores de hoy " << lancha1 << " y " << lancha2;
	Sleep(1250);
	lancha1.printStats();
	Sleep(1250);
	lancha2.printStats();
	Sleep(1500);
}

void turnos(lancha& lancha1, lancha& lancha2) {
	
}

int main() {

	lancha lancha_1("Armando", 0, 0, 1), lancha_2("Majumio", 0, 0, 1);

	inicio(lancha_1, lancha_2);



	
}

