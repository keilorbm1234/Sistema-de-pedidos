#pragma once 
#include <vector> 
#include "Pedido.h" 
using namespace std;

class Sistema {
private:
	vector<Pedido> pedidos; 
public:
	void nuevoPedido();
	Pedido& getPedidoActual(); 
	void agregarPedido(Pedido pedido); 
	const vector<Pedido>& getPedidos() const; 
	bool hayPedidos() const; 
	void eliminarUltimoPedido();
};

