#include "ProductoBase.h"

ProductoBase::ProductoBase(string n, double p, string id) : nombre(n), precio(p), identificador(id) {
}

string ProductoBase::getNombre() const {
	return nombre;
}

double ProductoBase::getPrecio() const {
	return precio;
}

string ProductoBase::getId() const {
	return identificador;
}



