#pragma once
#include <vector>
#include <memory>
#include "Producto.h"
using namespace std;

class Pedido {
private:
	vector<unique_ptr<Producto>> productos;
public: 
	Pedido(); 
	void agregarProducto(unique_ptr<Producto> producto);
	double calcularTotal() const;
	bool estaVacio() const;
};


