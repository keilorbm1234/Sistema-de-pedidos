#pragma once
#include "Producto.h"
#include <string>

class ProductoBase : public Producto {
protected: 
	string nombre; 
	const double precio; 
	string identificador;
public: 
	ProductoBase(string n, double p, string id);
	string getNombre() const override;
	double getPrecio() const override;
	string getId() const override;
	virtual ~ProductoBase() override = default;    
};

