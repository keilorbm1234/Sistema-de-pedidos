#pragma once
#include "ProductoBase.h"
using namespace std;
class Postre: public ProductoBase
{
public:
	Postre(string n, double p, string id);
	virtual ~Postre() override = default;
};
