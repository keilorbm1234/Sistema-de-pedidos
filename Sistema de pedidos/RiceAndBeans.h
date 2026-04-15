#pragma once
#include "Comida.h"

class RiceAndBeans : public Comida {
private:
	string nombre = "Rice and Beans"; 
	double precio = 2500.00; 
	string identificador = "RICE_AND_BEANS";
public:
	RiceAndBeans(string n, double p, string id);
};

