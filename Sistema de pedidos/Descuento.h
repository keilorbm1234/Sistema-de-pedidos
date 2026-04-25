#pragma once

class Descuento {
public:
	virtual double aplicar(double subtotal) const = 0; 
	virtual ~Descuento() = default; 
};
