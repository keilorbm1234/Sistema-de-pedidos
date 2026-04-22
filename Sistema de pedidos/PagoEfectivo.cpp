#include "PagoEfectivo.h"
#include "PagoInsuficienteException.h"
#include <iostream>
using namespace std;

PagoEfectivo::PagoEfectivo(double monto) : dineroRecibido(monto) {
}

void PagoEfectivo::pagar(double monto) {
	if (dineroRecibido < monto) {
		throw PagoInsuficienteException(); // Lanza una excepción si el dinero recibido es insuficiente
	}
	double cambio = dineroRecibido - monto;
	cout << "Pago en efectivo realizado. Cambio: ₡" << cambio << endl;
}