#include "PagoTarjeta.h"
#include "PagoNoAutorizadoException.h"
#include <iostream>
using namespace std;

PagoTarjeta::PagoTarjeta(bool autorizado) : autorizado(autorizado) {
}

void PagoTarjeta::pagar(double monto) {
	if (!autorizado) {
		throw PagoNoAutorizadoException(); 
	}
	cout << "Pago con tarjeta realizado por ₡" << monto << endl;
}
