#pragma once
#include "RestauranteException.h"

class PagoDigitalException : public RestauranteException {
public: 
	PagoDigitalException() : RestauranteException("Error en el pago digital") {}
};