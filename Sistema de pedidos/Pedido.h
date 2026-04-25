#pragma once
#include <vector>
#include <memory>
#include "Producto.h"
#include "CalculoPedido.h"
#include "MetodoPago.h"
#include "Descuento.h"

using namespace std;

class Pedido {
private:
	vector<unique_ptr<Producto>> productos; // Almacena los productos del pedido
	CalculoPedido calculo; // Instancia para realizar cálculos del pedido
public: 
	void agregarProducto(unique_ptr<Producto> producto);
	double calcularTotal() const;
	double calcularSubtotal() const;
	double calcularIva() const;
	bool estaVacio() const;
	void procesarPago(MetodoPago& metodo) const; //Uso de delegate para procesamiento del pago. 
	double calcularTotalConDescuento(const Descuento& descuento) const;
	void procesarPagoConDescuento(MetodoPago& metodo, const Descuento& descuento) const;
	const vector<unique_ptr<Producto>>& getProductos() const; //Importante para el calculo. 
	void mostrarProductos() const; 
};


