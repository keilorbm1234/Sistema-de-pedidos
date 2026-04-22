#pragma once 
#include <memory>
#include "Producto.h"

class ProductoDecorator : public Producto {
protected:
	unique_ptr<Producto> producto;
public:
	ProductoDecorator(unique_ptr<Producto> prod); 
	string getNombre() const override;
	double getPrecio() const override;
	string getId() const override;
	virtual ~ProductoDecorator() = default;
};


