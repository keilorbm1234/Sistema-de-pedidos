#pragma once
#include <vector>
#include "ProductoBase.h"
#include "CalculoPedido.h"

class Pedido {
private:
	std::vector<CalculoPedido*> calculador;
public: 
	void enviarExtra(); 

};


