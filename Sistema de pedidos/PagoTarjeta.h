#pragma once
#include <string>
#include "MetodoPago.h"
using namespace std;

class PagoTarjeta : public MetodoPago {
private:
	bool autorizado; 
public:
	PagoTarjeta(bool autorizado);
	void pagar(double monto) override;
};

