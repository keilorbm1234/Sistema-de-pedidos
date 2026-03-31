#pragma once
#define IPRODUCTO_H
#include <string>
using namespace std;	

class IProducto {
public: 
	~IProducto() = default;
	virtual string getNombre() const = 0; 
	virtual string getPrecio() const = 0; 
};