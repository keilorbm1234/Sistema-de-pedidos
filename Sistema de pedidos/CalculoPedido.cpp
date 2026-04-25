#include "CalculoPedido.h"
#include <stdexcept>

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

double CalculoPedido::calcularTotalConDescuento(
	const vector<unique_ptr<Producto>>& productos,
	const Descuento& descuento) const {
	double subtotal = calcularSubtotal(productos);
	double conDescuento = descuento.aplicar(subtotal); // Delega al descuento
	return conDescuento + calcularIva(conDescuento);
}

double CalculoPedido::getIva() const {
	return iva;
}
