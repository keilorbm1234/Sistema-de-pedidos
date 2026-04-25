#include <iostream>
#include "Sistema.h"
#include "Menu.h"
#include "GestorArchivos.h" 
#include "Pedido.h"
//pagos
#include "MetodoPago.h"
#include "PagoEfectivo.h" 
#include "PagoTarjeta.h" 
#include "PagoDigital.h" 
//productos
#include "Producto.h"
#include "Bebida.h"
#include "Comida.h"
#include "Postre.h"

#include "Casado.h" 
#include "GalloPinto.h"
#include "RiceAndBeans.h"
#include "Cafe.h"
#include "AguaDulce.h"
#include "Cas.h"
#include "Churchill.h"
#include "TamalAsado.h"
#include "TortaChilena.h"

//excepciones
#include "RestauranteException.h"
#include "PedidoVacioException.h"
//#include "PagoFallidoException.h"
//#include "ProductoNoEncontradoException.h"
//#include "MetodoPagoNoEncontradoException.h"	
//#include "PedidoNoEncontradoException.h"
//#include "ArchivoInvalidoException.h"
#include "ArchivoNoEncontradoException.h"
#include "EntradaInvalidaException.h"
#include "PagoInsuficienteException.h"
#include "PagoDigitalException.h"
#include "PagoNoAutorizadoException.h"
#include <stdexcept>


int main() {
    Sistema sistema;
    Menu menu;
    GestorArchivos gestor("pedidos.txt");

    int opcion = -1;

    do {
		//keilor, no se asuste, es solo un menu bonito jasjjas
        cout << "\n=============================================\n";
        cout << "     BIENVENIDO AL SISTEMA DE PEDIDOS\n";
        cout << "               TicoFeast\n";
        cout << "=============================================\n";
        cout << "1. Nuevo pedido\n";
        cout << "2. Ver menu\n";
        cout << "3. Agregar producto\n";
        cout << "4. Ver pedido actual\n";
        cout << "5. Pagar\n";
        cout << "6. Guardar pedidos\n";
        cout << "7. Cargar pedidos\n";
        cout << "0. Salir\n";
        cout << "=============================================\n";
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        // Para que los cin no se destruyan 
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente de nuevo.\n";
            continue;
        }

        try {
            switch (opcion) {

            case 1: {
                cout << "\n--- Nuevo Pedido ---\n";
                sistema.nuevoPedido();
                cout << "Pedido creado correctamente.\n";
                break;
            }

            case 2:
                cout << "\n--- Menu Disponible ---\n";
                menu.mostrar();
                break;

            case 3: {
                cout << "\n--- Agregar Producto ---\n";

                if (!sistema.hayPedidos())
                    throw RestauranteException("No hay pedidos activos.");

                int prodId;
                cout << "Ingrese ID del producto: ";
                cin >> prodId;

                if (cin.fail())
                    throw EntradaInvalidaException();

                Producto* producto = nullptr;

                switch (prodId) {
                case 1: producto = new Casado(); break;
                case 2: producto = new GalloPinto(); break;
                case 3: producto = new Cafe(); break;
                default:
                    throw RestauranteException("Producto no encontrado.");
                }

               // sistema.getPedidoActual().agregarProducto(producto);

                cout << "Producto agregado.\n";
                break;
            }

            case 4: {
                cout << "\n--- Pedido Actual ---\n";

                if (!sistema.hayPedidos())
                    throw PedidoVacioException();

                const auto& productos = sistema.getPedidoActual().getProductos();

                if (productos.empty())
                    throw PedidoVacioException();

                for (const auto& p : productos) {
                    cout << "- " << p->getNombre()
                        << " | C/" << p->getPrecio() << "\n";
                }

                cout << "Total: C/"
                    << sistema.getPedidoActual().calcularTotal() << "\n";

                break;
            }

            case 5: {
                cout << "\n--- Pago ---\n";

                if (!sistema.hayPedidos())
                    throw PedidoVacioException();   

                double total = sistema.getPedidoActual().calcularTotal();

                if (total <= 0)
                    throw PedidoVacioException();

                cout << "Total a pagar: C/" << total << "\n";

                cout << "Seleccione metodo:\n";
                cout << "1. Efectivo\n2. Tarjeta\n3. Digital\n";

                int metodo;
                cin >> metodo;

                MetodoPago* pago = nullptr;

                switch (metodo) {
                case 1: //pago = new PagoEfectivo(); break;
                case 2: //pago = new PagoTarjeta(); break;
                case 3:// pago = new PagoDigital(); break;
                default:
                    throw PagoNoAutorizadoException();
                }

                pago->pagar(total);

                cout << "Pago realizado con exito.\n";
                delete pago;

                break;
            }

            case 6:
                cout << "\n--- Guardando ---\n";
                gestor.guardar(sistema.getPedidos());
                cout << "Pedidos guardados.\n";
                break;

            case 7:
                cout << "\n--- Cargando ---\n";
                gestor.cargar();
                cout << "Pedidos cargados.\n";
                break;

            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
            }

        }
        catch (const RestauranteException& e) {
            cout << "Error: " << e.what() << "\n";
        }
        catch (const exception& e) {
            cout << "Error inesperado: " << e.what() << "\n";
        }

    } while (opcion != 0);

    return 0;
}