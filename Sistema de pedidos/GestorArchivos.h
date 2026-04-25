#pragma once 
#include <string> 
#include <vector> 
#include "Pedido.h" 
using namespace std; 

class GestorArchivos {
private:
	string nombreArchivo; 
public: 
	GestorArchivos(const string& archivo);
	void guardar(const vector<Pedido>& pedidos) const; 
	vector<string> cargar() const; 
};
