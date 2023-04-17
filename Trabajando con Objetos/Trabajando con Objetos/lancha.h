#pragma once
#include <iostream>
#include <stdlib.h>

class lancha {
private:
	std::string nombre;
	int velocidad;
	int distancia_recorrida;
	int nitro;

public:
	//CONSTRUCTOR
	lancha(std::string pName, int pVelocidad, int pDistanciaRecorrida, int pNitro);
	
	//GETTERS
	std::string getNombre();
	int getVelocidad();
	int getDistancia_recorrida();
	int getNitro();

	//SETTERS
	void setNombre(std::string pName);
	void setVelocidad(int pVelocidad);
	void setDistanciaRecorrida(int pDistanciaRecorrida);
	void setNitro(int pNitro);

	//METHODS
	void printStats();
	void usoNitro();
	void printDistance();

	lancha(std::string pName);
};
