#pragma once 
#include <vector> 
#include "GestorArchivos.h"
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
	void guardarPedidos(const string& archivo) const;
	void cargarPedidos(const string& archivo);
	void eliminarUltimoPedido();
};

