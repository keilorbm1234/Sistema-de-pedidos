#include "SinIngrediente.h"

SinIngrediente::SinIngrediente(unique_ptr<Producto> prod, const string& nombre) 
	: ProductoDecorator(move(prod)), nombreIngrediente(nombre) {
}

string SinIngrediente::getNombre() const {
	return producto->getNombre() + " sin " + nombreIngrediente;
}