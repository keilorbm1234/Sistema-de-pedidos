#pragma once
#include "ProductoBase.h"
using namespace std;

class Bebida : public ProductoBase {
public:
	Bebida(string n, double p, string id);
	virtual ~Bebida() override = default;
};