#pragma once
#include "Postre.h"

class TortaChilena : public Postre {
private:
	string nombre = "Torta Chilena"; 
	double precio = 2000.00; 
	string identificador = "TORTA_CHILENA";
public:
	TortaChilena(string n, double p, string id);
};

