#include "DescuentoPorcentaje.h"
#include <stdexcept> 

DescuentoPorcentaje::DescuentoPorcentaje(double porcentaje)
    : porcentaje(porcentaje) {
    if (porcentaje < 0.0 || porcentaje > 100.0)
        throw std::invalid_argument("Porcentaje debe estar entre 0 y 100");
}

double DescuentoPorcentaje::aplicar(double subtotal) const {
    return subtotal * (1.0 - porcentaje / 100.0);
}


