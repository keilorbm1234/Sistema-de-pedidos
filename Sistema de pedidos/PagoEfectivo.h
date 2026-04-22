#pragma once
#include "MetodoPago.h"

class PagoEfectivo : public MetodoPago {
private:
	double dineroRecibido;
public:
	PagoEfectivo(double monto);
	void pagar(double monto) override;
};

