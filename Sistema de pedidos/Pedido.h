#pragma once
#include <vector>
#include <memory>
#include "Producto.h"
using namespace std;

class Pedido {
private:
	vector<unique_ptr<Producto>> productos; // Almacena los productos del pedido
public: 
	void agregarProducto(unique_ptr<Producto> producto);
	double calcularTotal() const;
	bool estaVacio() const;
};


