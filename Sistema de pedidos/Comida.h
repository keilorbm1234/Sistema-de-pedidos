#pragma once
#include "ProductoBase.h"
using namespace std;	

class Comida : public ProductoBase { 
public: 
	Comida(string n, double p, string id); 
	virtual ~Comida() override = default;
};

