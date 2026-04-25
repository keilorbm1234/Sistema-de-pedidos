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
        cout << "5. Personalizar producto\n";
        cout << "6. Pagar\n";
        cout << "7. Guardar pedidos\n";
        cout << "8. Cargar pedidos\n";
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

                menu.mostrar();
                cout << "Ingrese el ID del producto (1-9): ";
                int prodId; 
                cin >> prodId; 

                if (cin.fail()) throw EntradaInvalidaException();

                unique_ptr<Producto> producto;

                switch (prodId) {
                case 1: producto = make_unique<Casado>(); break;
                case 2: producto = make_unique<GalloPinto>(); break;
                case 3: producto = make_unique<RiceAndBeans>(); break;
                case 4: producto = make_unique<Cafe>(); break;
                case 5: producto = make_unique<AguaDulce>(); break;
                case 6: producto = make_unique<Cas>(); break;
                case 7: producto = make_unique<Churchill>(); break;
                case 8: producto = make_unique<TamalAsado>(); break;
                case 9: producto = make_unique<TortaChilena>(); break;
                default: throw RestauranteException("Producto no encontrado.");
                }

                sistema.getPedidoActual().agregarProducto(move(producto));
                cout << "Producto agregado correctamente.\n";
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
                cout << "\n--- Personalizar Producto ---\n";

                if (!sistema.hayPedidos())
                    throw RestauranteException("No hay pedidos activos.");

                if (sistema.getPedidoActual().estaVacio())
                    throw PedidoVacioException();

                cout << "Productos en el pedido:\n";
                sistema.getPedidoActual().mostrarProductos();

                cout << "\nTipo de personalizacion:\n";
                cout << "1. Agregar ingrediente extra\n";
                cout << "2. Quitar ingrediente\n";
                cout << "3. Cambiar tamanio\n";
                cout << "Seleccione: ";

                int tipo;
                cin >> tipo;
                if (cin.fail()) throw EntradaInvalidaException();

                string nombre;
                double precio;

                switch (tipo) {
                case 1: {
                    cout << "Nombre del ingrediente: ";
                    cin >> nombre;
                    cout << "Precio extra: C/";
                    cin >> precio;
                    sistema.getPedidoActual().decorarUltimoExtra(nombre, precio);
                    cout << "Ingrediente agregado.\n";
                    break;
                }
                case 2: {
                    cout << "Ingrediente a quitar: ";
                    cin >> nombre;
                    sistema.getPedidoActual().decorarUltimoSin(nombre);
                    cout << "Ingrediente quitado.\n";
                    break;
                }
                case 3: {
                    cout << "Nuevo tamanio: ";
                    cin >> nombre;
                    cout << "Precio extra: C/";
                    cin >> precio;
                    sistema.getPedidoActual().decorarUltimoTamanio(nombre, precio);
                    cout << "Tamanio cambiado.\n";
                    break;
                }
                default:
                    throw EntradaInvalidaException();
                }
                break;
            }

            case 6: {
                cout << "\n--- Pago ---\n";

                if (!sistema.hayPedidos())
                    throw PedidoVacioException();

                double total = sistema.getPedidoActual().calcularTotal();
                cout << "Total a pagar: C/" << total << "\n";

                cout << "Seleccione metodo:\n";
                cout << "1. Efectivo\n2. Tarjeta\n3. Digital\n";

                int metodo;
                cin >> metodo;

                if (cin.fail()) throw EntradaInvalidaException();

                switch (metodo) {
                case 1: {
                    cout << "Monto entregado: C/";
                    double monto;
                    cin >> monto;
                    PagoEfectivo pago(monto);
                    sistema.getPedidoActual().procesarPago(pago);
                    cout << "Cambio: C/" << (monto - total) << "\n";
                    break;
                }
                case 2: {
                    PagoTarjeta pago(true);
                    sistema.getPedidoActual().procesarPago(pago);
                    break;
                }
                case 3: {
                    PagoDigital pago(true);
                    sistema.getPedidoActual().procesarPago(pago);
                    break;
                }
                default:
                    throw EntradaInvalidaException();
                }

                cout << "Pago realizado con exito.\n";
                break;
            }

            case 7:
                cout << "\n--- Guardando ---\n";
                gestor.guardar(sistema.getPedidos());
                cout << "Pedidos guardados.\n";
                break;

            case 8:
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