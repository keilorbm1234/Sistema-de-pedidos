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

double CalculoPedido::aplicarDescuento(double subtotal, double porcentaje) const {
	if (porcentaje < 0.0 || porcentaje > 100.0) {
		throw invalid_argument("El porcentaje de descuento debe estar entre 0 y 100");
	}
	return subtotal * (1.0 - porcentaje / 100.0); 
}

double CalculoPedido::calcularTotalConDescuento(const vector<unique_ptr<Producto>>& productos, double porcentaje) const {
	double subtotal = calcularSubtotal(productos); 
	double conDescuento = aplicarDescuento(subtotal, porcentaje); 
	return conDescuento + calcularIva(conDescuento); 
}

double CalculoPedido::getIva() const {
	return iva;
}
