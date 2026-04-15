#pragma once
#include <vector>
#include <memory>
#include "ProductoBase.h"
#include "CalculoPedido.h"
using namespace std;

class Pedido {
private:
	shared_ptr<CalculoPedido*> calculador; // Agregamos un puntero inteligente para manejar la memoria del objeto CalculoPedido	
	vector<ProductoBase*> productos; 
public: 

};


