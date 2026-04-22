#include "Comida.h"
#include "Bebida.h"
#include "Postre.h"
#include "Pedido.h"
#include "PedidoVacioException.h"
#include <iostream>

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

double Pedido::calcularTotalConDescuento(double porcentaje) const {
	if (productos.empty()) {
		throw PedidoVacioException();
	}
	return calculo.calcularTotalConDescuento(productos, porcentaje);
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

void Pedido::procesarPagoConDescuento(MetodoPago& metodo, double porcentaje) const {
	if (productos.empty()) {
		throw PedidoVacioException();
	}
	metodo.pagar(calcularTotalConDescuento(porcentaje));
}

const vector<unique_ptr<Producto>>& Pedido::getProductos() const {
	return productos; 
}

void Pedido::mostrarProductos() {
	for (const auto& p : productos) {
		if (dynamic_cast<Comida*>(p.get())) {
			cout << "[Comida]  ";
		}
		else if (dynamic_cast<Bebida*>(p.get())) {
			cout << "[Bebida]  ";
		}
		else if (dynamic_cast<Postre*>(p.get())) {
			cout << "[Postre]  ";
		}
		else {
			cout << "[Personalizado] "; // Para los decoradores del programa
		}
		cout << p->getNombre() << " - C/" << p->getPrecio() << "\n";
	}
}