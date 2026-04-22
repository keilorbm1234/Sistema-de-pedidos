#pragma once
#include <memory>
#include <string>
#include "ProductoDecorator.h"
using namespace std;

class ExtraIngrediente : public ProductoDecorator {
private:
	string nombreExtra;
	double precioExtra;
public:
	ExtraIngrediente(unique_ptr<Producto> prod, const string& nombre, double precio);
	string getNombre() const override;
	double getPrecio() const override;	
};

