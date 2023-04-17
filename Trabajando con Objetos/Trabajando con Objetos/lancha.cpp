#include "lancha.h"
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <stdlib.h>

//CONSTRUCTOR
lancha::lancha(std::string pName, int pVelocidad, int pDistanciaRecorrida, int pNitro) {
	nombre = pName;
	velocidad = pVelocidad;
	distancia_recorrida = pDistanciaRecorrida;
	nitro = pNitro;
}

//GETTERS
std::string lancha::getNombre() {
	return nombre;
}

int lancha::getVelocidad() {
	return velocidad;
}

int lancha::getDistancia_recorrida() {
	return distancia_recorrida;
}

int lancha::getNitro() {
	return nitro;
}

//SETTERS
void lancha::setVelocidad(int pVelocidad) {
	velocidad = pVelocidad;
}

void lancha::setDistanciaRecorrida(int pDistanciaRecorrida) {
	distancia_recorrida = pDistanciaRecorrida;
}

void lancha::setNitro(int pNitro) {
	nitro = pNitro;
}

//METHODS
void lancha::printStats() {
	if(nitro) {
		std::cout << "La velocidad de la lancha es de " << getVelocidad()
			<< " y la distancia que ha recorrido es de " << getDistancia_recorrida() << " tiene disponible el nitro " << getNitro() << "\n";
	} else {
		std::cout << "La velocidad de la lancha es de " << getVelocidad()
			<< " y la distancia que ha recorrido es de " << getDistancia_recorrida() << " y no tiene disponible el nitro " << getNitro() << "\n";
	}
}

void lancha::usoNitro() {
	srand(time(NULL));
	int aleatorio = rand() % 2;
	if (aleatorio == 0) {
		std::cout << "Por desgracia el nitro no ha funcionado, y tu velocidad se ha reducido.";
		lancha::setVelocidad((velocidad/2));
	}
	else {
		std::cout << "El nitro ha funcionado, y tu velocidad se ha duplicado.";
		lancha::setVelocidad((velocidad*2));
	}
	std::cout << "Ahora tu velocidad es de " << velocidad;
}

void lancha::printDistance() {
	lancha::setDistanciaRecorrida((distancia_recorrida + velocidad * 100));
	std::cout << "La lancha " << nombre << " ha navegado " << distancia_recorrida << "millas de distancia ";
}

