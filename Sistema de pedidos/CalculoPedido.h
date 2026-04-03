#pragma once
#include "Pedido.h"

class CalculoPedido {
private: 
	double iva = 0.13; 
	double subtotal = 0.0; 
	double total = 0.0;
	double descuento = 0.0; 
	int extra; 
public:
	double getIva() const;
	double getSubtotal() const;
	double getTotal() const;
	double getDescuento() const;
	double calcularTotal();
};

