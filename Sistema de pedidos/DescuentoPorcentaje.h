#pragma once
#include "Descuento.h"

class DescuentoPorcentaje : public Descuento {
private:
    double porcentaje;
public:
    DescuentoPorcentaje(double porcentaje);
    double aplicar(double subtotal) const override;
};

