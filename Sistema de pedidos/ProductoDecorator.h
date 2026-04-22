#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Producto.h"

class ProductoDecorator : public Producto {
protected:
	unique_ptr<Producto> producto;
public:
	ProductoDecorator(unique_ptr<Producto>& prod); 
	string getNombre() const override;
	double getPrecio() const override;
	string getId() const override;
};


