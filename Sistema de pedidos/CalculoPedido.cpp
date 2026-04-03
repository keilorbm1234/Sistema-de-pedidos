#include "CalculoPedido.h"

double CalculoPedido::getIva() const {
	return iva;
}
double CalculoPedido::getSubtotal() const {
	return subtotal;
}	
double CalculoPedido::getTotal() const {
	return total;
}
double CalculoPedido::getDescuento() const {
	return descuento;
}
double CalculoPedido::calcularTotal() {
	return total = subtotal + (subtotal * iva) - descuento;
}
