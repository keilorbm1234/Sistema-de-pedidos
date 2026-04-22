#include "PagoTarjeta.h"
#include "PagoNoAutorizadoException.h"
using namespace std;

PagoTarjeta::PagoTarjeta(bool autorizado) : autorizado(autorizado) {
}

void PagoTarjeta::pagar(double monto) {
	if (!autorizado) {
		throw PagoNoAutorizadoException(); 
	}
}
