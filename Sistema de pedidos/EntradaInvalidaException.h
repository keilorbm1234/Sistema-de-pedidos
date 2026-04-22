#pragma once
#include "RestauranteException.h"

class EntradaInvalidaException : public RestauranteException {
public:
	EntradaInvalidaException() : RestauranteException("Entrada invalida") {}
};
