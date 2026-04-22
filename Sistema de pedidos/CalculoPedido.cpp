#include "CalculoPedido.h"

double CalculoPedido::calcularSubtotal(const vector<unique_ptr<Producto>>& productos) const {
	double subtotal = 0.0;
	for (const auto& p : productos) {
		subtotal += p->getPrecio();
	}
	return subtotal;
}

double CalculoPedido::calcularIva(double subtotal) const {
	return subtotal * iva;
}

double CalculoPedido::calcularTotal(const vector<unique_ptr<Producto>>& productos) const {
	double subtotal = calcularSubtotal(productos);
	double impuesto = calcularIva(subtotal);
	return subtotal + impuesto;
}

double CalculoPedido::getIva() const {
	return iva;
}
