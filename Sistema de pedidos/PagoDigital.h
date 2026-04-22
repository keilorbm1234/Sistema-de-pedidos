#pragma once
#include "MetodoPago.h"

class PagoDigital : public MetodoPago {
private:
	bool servicioDisponible;
public:
	PagoDigital(bool servicioDisponible);
	void pagar(double monto) override;
};

