#include "ExtraIngrediente.h"

ExtraIngrediente::ExtraIngrediente(unique_ptr<Producto> prod, const string& nombre, double precio) 
	: ProductoDecorator(move(prod)), nombreExtra(nombre), precioExtra(precio) {
}

string ExtraIngrediente::getNombre() const {
	return producto->getNombre() + " + " + nombreExtra;
}

double ExtraIngrediente::getPrecio() const {
	return producto->getPrecio() + precioExtra;
}