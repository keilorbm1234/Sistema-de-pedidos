#pragma once
#include <vector>
#include <memory>
#include "ProductoBase.h"
#include "CalculoPedido.h"
#include "Cliente.h"
using namespace std;

class Pedido {
private:
	vector<unique_ptr<Producto>> productos;
	unique_ptr<CalculoPedido> calculo; 
	shared_ptr<Cliente> cliente;
public: 
	Pedido(); 
	void agregarProducto(unique_ptr<Producto> producto);
	void eliminarProducto(const string& id);
	bool isEmpty() const;
	double getSubtotal() const;
	double getTotal() const;
	void setDescuento(double porcentaje);


};


