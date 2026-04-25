#include "Sistema.h" 
#include <stdexcept> 
void Sistema::nuevoPedido() { 
	pedidos.push_back(Pedido()); 
} 

Pedido& Sistema::getPedidoActual(){
	if (pedidos.empty()) 
		throw runtime_error("No hay pedidos activos"); 
	return pedidos.back(); 
} 

void Sistema::agregarPedido(Pedido pedido) {
	pedidos.push_back(move(pedido)); 
} 

const vector<Pedido>& Sistema::getPedidos() const {
	return pedidos; 
} 

bool Sistema::hayPedidos() const {
	return !pedidos.empty(); 
}

void Sistema::eliminarUltimoPedido() {
	if (pedidos.empty()) 
		throw runtime_error("No hay pedidos para eliminar"); 
	pedidos.pop_back(); 
}	
