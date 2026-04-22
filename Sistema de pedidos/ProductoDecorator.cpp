#include "ProductoDecorator.h"

ProductoDecorator::ProductoDecorator(unique_ptr<Producto> prod) : producto(move(prod)) {} 

string ProductoDecorator::getNombre() const {
    return producto->getNombre();
}

double ProductoDecorator::getPrecio() const {
    return producto->getPrecio();
}

string ProductoDecorator::getId() const {
    return producto->getId();
}