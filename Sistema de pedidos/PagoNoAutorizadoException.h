#pragma once
#include "RestauranteException.h"

class PagoNoAutorizadoException : public RestauranteException {
public:
    PagoNoAutorizadoException() : RestauranteException("Pago con tarjeta no autorizado") {}
};