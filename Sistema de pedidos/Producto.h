#pragma once
#include <string>
using namespace std;	

class Producto {
public: 
	virtual ~Producto() = default;
	virtual string getNombre() const = 0; 
	virtual string getId() const = 0;
	virtual double getPrecio() const = 0; 
};