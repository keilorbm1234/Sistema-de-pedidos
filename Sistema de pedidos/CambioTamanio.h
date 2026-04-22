#pragma once
#include <memory>
#include <string>
#include "ProductoDecorator.h"
using namespace std;

class CambioTamanio : public ProductoDecorator {
private:
	string nuevoTamanio;
	double precioAdicional;
public:
	CambioTamanio(unique_ptr<Producto> prod, const string& tamanio, double precioAdicional);
	string getNombre() const override;
	double getPrecio() const override;
};

