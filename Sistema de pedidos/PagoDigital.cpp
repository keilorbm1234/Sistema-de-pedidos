#include "PagoDigital.h"
#include "PagoDigitalException.h"
#include <iostream>
using namespace std;

PagoDigital::PagoDigital(bool servicioDisponible) : servicioDisponible(servicioDisponible) {
}

void PagoDigital::pagar(double monto) {
	if (!servicioDisponible) {
		throw PagoDigitalException(); //Si el servicio no está disponible, lanza una excepción a la hora de procesar el pago. 
	}
	cout << "Pago digital realizado por ₡" << monto << endl;
}
