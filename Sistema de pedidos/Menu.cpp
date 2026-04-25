#include "Menu.h"

void Menu::mostrar() const { 
	cout << "\n===== MENU DEL RESTAURANTE =====\n";
	cout << "\n-- COMIDAS --\n"; 
	cout << "1. Casado C/3750\n";
	cout << "2. Gallo Pinto C/2500\n";
	cout << "3. Rice and Beans C/3000\n"; 
	cout << "\n-- BEBIDAS --\n"; 
	cout << "4. Cafe C/1000\n"; 
	cout << "5. Agua Dulce C/650\n";
	cout << "6. Cas C/500\n";
	cout << "\n-- POSTRES --\n"; 
	cout << "7. Churchill C/1850\n"; 
	cout << "8. Tamal Asado C/1200\n"; 
	cout << "9. Torta Chilena C/2500\n"; 
	cout << "================================\n";
}
