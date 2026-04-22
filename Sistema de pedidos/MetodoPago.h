#pragma once

class MetodoPago {
public:
	virtual ~MetodoPago() = default;
	virtual void pagar(double monto) = 0; 
};
