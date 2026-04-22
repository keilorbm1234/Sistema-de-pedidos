#pragma once
#include "RestauranteException.h"

class ArchivoNoEncontradoException : public RestauranteException {
public:
	ArchivoNoEncontradoException() : RestauranteException("Archivo no encontrado") {}
};