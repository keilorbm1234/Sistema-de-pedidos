#include "Pedido.h"
#include "PedidoVacioException.h"

void Pedido::agregarProducto(unique_ptr<Producto> producto) {
	productos.push_back(move(producto)); 
}

double Pedido::calcularSubtotal() const {
	if (productos.empty()) {
		throw PedidoVacioException();
	}
	return calculo.calcularSubtotal(productos); //Delegación al objeto CalculoPedido para calcular el subtotal.
}

double Pedido::calcularIva() const {
	if (productos.empty()) {
		throw PedidoVacioException();
	}
	return calculo.calcularIva(calcularSubtotal()); //Delegación al objeto para calcular el iva.
}

double Pedido::calcularTotal() const {
	if (productos.empty()) {
		throw PedidoVacioException();
	}
	return calculo.calcularTotal(productos); //Delegación al objeto para calcular el total.
}

bool Pedido::estaVacio() const {
	return productos.empty();
}

void Pedido::procesarPago(MetodoPago& metodo) const {
	if (productos.empty()) {
		throw PedidoVacioException();
	}
	metodo.pagar(calcularTotal()); //Delegación al método de pago para procesar el pago.
}

const vector<unique_ptr<Producto>>& Pedido::getProductos() const {
	return productos; 
}