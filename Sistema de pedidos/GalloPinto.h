#pragma once
#include "Comida.h"

class GalloPinto : public Comida {
private:
	string nombre = "Gallo Pinto"; 
	double precio = 3500.00; 
	string identificador = "GALLO_PINTO";
public: 
	GalloPinto(string n, double p, string id);
};

