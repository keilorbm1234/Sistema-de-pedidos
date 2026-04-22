#pragma once
#include <memory>
#include "ProductoDecorator.h"
using namespace std;

class SinIngrediente : public ProductoDecorator {
private:
	string nombreIngrediente;
public: 
	SinIngrediente(unique_ptr<Producto> prod, const string& nombre);
	string getNombre() const override;
};

