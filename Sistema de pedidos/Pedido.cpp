#include "Pedido.h"
#include <stdexcept>

void Pedido::agregarProducto(unique_ptr<Producto> producto) {
	productos.push_back(move(producto)); 
}

double Pedido::calcularTotal() const {
	if (productos.empty()) {
		throw runtime_error("Pedido vacio");
	}

	double total = 0.0;
	for (const auto& p : productos) {
		total += p->getPrecio();
	}
	return total;
}

bool Pedido::estaVacio() const {
	return productos.empty();
}
