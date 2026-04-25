#include "GestorArchivos.h"
#include "ArchivoNoEncontradoException.h" 
#include <fstream> 
#include <stdexcept> 

GestorArchivos::GestorArchivos(const string& archivo) : nombreArchivo(archivo) {} 

void GestorArchivos::guardar(const vector<Pedido>& pedidos) const { 
	ofstream archivo(nombreArchivo);

	if (!archivo.is_open()) 
		throw runtime_error("No se pudo abrir el archivo para guardar"); 

	for (const auto& pedido : pedidos) { 
		if (pedido.estaVacio()) continue;
		archivo << "--- PEDIDO ---\n"; 

		for (const auto& p : pedido.getProductos()) { 
			archivo << p->getNombre() << "|" << p->getPrecio() << "\n";
		} 

		archivo << "Total: " << pedido.calcularTotal() << "\n"; 
	} 
	archivo.close(); 
} 

vector<string> GestorArchivos::cargar() const { 
	ifstream archivo(nombreArchivo);

	if (!archivo.is_open()) 
		throw ArchivoNoEncontradoException(); 

	vector<string> lineas; 
	string linea;
	while (getline(archivo, linea)) lineas.push_back(linea);
	archivo.close(); 
	return lineas; 
}
