#include "CambioTamanio.h"

CambioTamanio::CambioTamanio(unique_ptr<Producto> prod, const string& nuevoTamanio, double precioExtra) 
	: ProductoDecorator(move(prod)), nuevoTamanio(nuevoTamanio), precioAdicional(precioExtra) {
}

string CambioTamanio::getNombre() const {
	return producto->getNombre() + " (" + nuevoTamanio + ")";
}

double CambioTamanio::getPrecio() const {
	return producto->getPrecio() + precioAdicional;
}