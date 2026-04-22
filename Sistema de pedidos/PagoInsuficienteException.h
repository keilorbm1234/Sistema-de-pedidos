#pragma once
#include "RestauranteException.h"

class PagoInsuficienteException : public RestauranteException {
public:
	PagoInsuficienteException() : RestauranteException("El monto pagado es insuficiente") {}
};
