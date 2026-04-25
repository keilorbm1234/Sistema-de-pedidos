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

void Sistema::guardarPedidos(const string& archivo) const {
	GestorArchivos gestor(archivo);
	gestor.guardar(pedidos); 
}
 
void Sistema::cargarPedidos(const string& archivo) {
	GestorArchivos gestor(archivo);
	auto lineas = gestor.cargar(); 
	// Aqui se deberia implementar la logica para convertir las lineas en objetos Pedido y agregarlos a la lista de pedidos. 
}	

void Sistema::eliminarUltimoPedido() {
	if (pedidos.empty()) 
		throw runtime_error("No hay pedidos para eliminar"); 
	pedidos.pop_back(); 
}	
