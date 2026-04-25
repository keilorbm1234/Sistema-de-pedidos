#pragma once
#include <vector>
#include <memory>
#include "Producto.h"
#include "Descuento.h"
using namespace std;

class CalculoPedido {
private: 
	double iva = 0.13; 
public:
	double calcularSubtotal(const vector<unique_ptr<Producto>>& productos) const;
	double calcularIva(double subtotal) const;
	double calcularTotal(const vector<unique_ptr<Producto>>& productos) const;
	double calcularTotalConDescuento(const vector<unique_ptr<Producto>>& productos, const Descuento& descuento) const;
	double getIva() const;
};

