#pragma once
#include "RestauranteException.h"

class PedidoVacioException : public RestauranteException {
public:
	PedidoVacioException() : RestauranteException("El pedido esta vacío") {}
};