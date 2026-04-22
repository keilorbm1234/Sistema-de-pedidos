#include "PagoEfectivo.h"
#include "PagoInsuficienteException.h"
using namespace std;

PagoEfectivo::PagoEfectivo(double monto) : dineroRecibido(monto) {
}

void PagoEfectivo::pagar(double monto) {
	if (dineroRecibido < monto) {
		throw PagoInsuficienteException(); 
	}
}