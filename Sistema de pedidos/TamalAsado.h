#pragma once
#include <string>
#include "Postre.h"

class TamalAsado : public Postre {
private: 
	string nombre = "Tamal Asado";
	double precio = 3500.00; 
	string identificador = "TAMAL_ASADO";
public:
	TamalAsado(string n, double p, string id);
};

