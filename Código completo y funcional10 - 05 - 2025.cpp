#include <iostream>
#include <vector>
#include <string> // Permite usar la clase string para manejar cadenas de texto
#include <iomanip> // Para formatear la salida
#include <limits>  // Para manejar la entrada del usuario
using namespace std;

// Estructuras
struct Producto {
    string nombre;               // Nombre del producto
    string tipo;                 // Tipo: drogueria, papeleria, supermercado, etc.
    int cantidad;               // Cantidad disponible en inventario
    int minimo;                 // Cantidad mínima antes de necesitar reabastecer
    float precioBase;          // Precio base sin IVA
    float precioFinal;         // Precio con IVA aplicado
    int vendidos;              // Unidades vendidas, para estadísticas
};

struct Venta {
    string nombreProducto;     // Nombre del producto vendido
    int cantidadVendida;       // Cuántas unidades se vendieron
    float totalVenta;          // Valor total de la venta
};

struct Estadisticas {
    float totalVentas;         // Valor total acumulado de ventas
    string productoMasVendido; // Producto con más unidades vendidas
    string productoMenosVendido; // Producto con menos unidades vendidas
};

// Variables Globales
vector<Producto> inventario;
vector<Venta> ventas;
Estadisticas estadisticas = {0.0, "", ""};

// Prototipos de funciones
void mostrarMenu();
void visualizarProductos();
void venderProducto();
void abastecerProducto();
void cambiarProducto();
void calcularEstadisticas();
void asignarDatosConIVA(Producto& producto);
void agregarProducto();
void mostrarMatrizProductos();

// Función para calcular el precio final con IVA
void asignarDatosConIVA(Producto& producto) {
    if (producto.tipo == "papeleria") {
        producto.precioFinal = producto.precioBase * 1.16;
    } else if (producto.tipo == "drogueria") {
        producto.precioFinal = producto.precioBase * 1.12;
    } else if (producto.tipo == "supermercado") {
        producto.precioFinal = producto.precioBase * 1.04;
    } else {
        producto.precioFinal = producto.precioBase; // Sin IVA si no se reconoce el tipo
    }
}

// Funciones
void mostrarMenu() {
    cout << "\n--- MercaPlus ---" << endl;
    cout << "1. Visualizar Productos" << endl;
    cout << "2. Vender Producto" << endl;
    cout << "3. Abastecer Producto" << endl;
    cout << "4. Cambiar Producto" << endl;
    cout << "5. Calcular Estadisticas" << endl;
    cout << "6. Agregar Producto Nuevo" << endl;
    cout << "7. Ver Matriz de Productos" << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void visualizarProductos() {
    cout << "\n--- Inventario ---" << endl;
    cout << left << setw(20) << "Nombre" << setw(15) << "Tipo" << setw(10) << "Cantidad"
         << setw(10) << "Minimo" << setw(12) << "Precio Base" << setw(12) << "Precio Final" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (const auto& p : inventario) {
        cout << left << setw(20) << p.nombre << setw(15) << p.tipo << setw(10) << p.cantidad
             << setw(10) << p.minimo << setw(12) << fixed << setprecision(2) << p.precioBase
             << setw(12) << fixed << setprecision(2) << p.precioFinal << endl;
    }
}

void venderProducto() {
    string nombreProducto;
    int cantidadAVender;

    cout << "\n--- Vender Producto ---" << endl;
    cout << "Nombre del producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreProducto); //getline se usa para capturar correctamente nombres de productos o tipos que pueden contener espacios
    cout << "Cantidad a vender: ";
    cin >> cantidadAVender;

    for (auto& p : inventario) {
        if (p.nombre == nombreProducto) {
            if (p.cantidad >= cantidadAVender) {
                float totalVenta = p.precioFinal * cantidadAVender;
                p.cantidad -= cantidadAVender;
                p.vendidos += cantidadAVender;
                estadisticas.totalVentas += totalVenta;
                ventas.push_back({nombreProducto, cantidadAVender, totalVenta});

                cout << "Venta realizada. Total: $" << fixed << setprecision(2) << totalVenta << endl;
                return;
            } else {
                cout << "No hay suficiente stock." << endl;
                return;
            }
        }
    }
    cout << "Producto no encontrado." << endl;
}

void abastecerProducto() {
    string nombreProducto;
    int cantidadAgregar;

    cout << "\n--- Abastecer Producto ---" << endl;
    cout << "Nombre del producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreProducto);
    cout << "Cantidad a agregar: ";
    cin >> cantidadAgregar;

    for (auto& p : inventario) {
        if (p.nombre == nombreProducto) {
            p.cantidad += cantidadAgregar;
            cout << "Stock actualizado: " << p.cantidad << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void cambiarProducto() {
    string nombreProducto;
    cout << "\n--- Cambiar Producto ---" << endl;
    cout << "Nombre del producto a cambiar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreProducto);

    for (auto& p : inventario) {
        if (p.nombre == nombreProducto) {
            cout << "Nuevo nombre: ";
            getline(cin, p.nombre);
            cout << "Nuevo tipo: ";
            getline(cin, p.tipo);
            cout << "Nueva cantidad minima: ";
            cin >> p.minimo;
            cout << "Nuevo precio base: ";
            cin >> p.precioBase;
            asignarDatosConIVA(p);
            cout << "Producto actualizado." << endl;
            return;
        }
    }
    cout << "Producto no encontrado." << endl;
}

void calcularEstadisticas() {
    cout << "\n--- Estadisticas de Ventas ---" << endl;
    if (inventario.empty()) {
        cout << "No hay productos en el inventario." << endl;
        return;
    }

    Producto* masVendido = &inventario[0];
    Producto* menosVendido = &inventario[0];
    int totalUnidadesVendidas = 0;

    for (auto& p : inventario) {
        totalUnidadesVendidas += p.vendidos;
        if (p.vendidos > masVendido->vendidos) {
            masVendido = &p;
        }
        if (p.vendidos < menosVendido->vendidos) {
            menosVendido = &p;
        }
    }

    cout << "Producto mas vendido: " << masVendido->nombre << " (" << masVendido->vendidos << " unidades)" << endl;
    cout << "Producto menos vendido: " << menosVendido->nombre << " (" << menosVendido->vendidos << " unidades)" << endl;
    cout << "Total de ventas: $" << fixed << setprecision(2) << estadisticas.totalVentas << endl;
    if (totalUnidadesVendidas > 0) {
        cout << "Promedio venta por unidad: $" << fixed << setprecision(2) << estadisticas.totalVentas / totalUnidadesVendidas << endl;
    } else {
        cout << "No se han realizado ventas." << endl;
    }
}

void agregarProducto() {
    Producto p;
    cout << "\n=== Agregar Producto ===\n";
    cout << "Nombre: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, p.nombre);

    for (const auto& prod : inventario) {
        if (prod.nombre == p.nombre) {
            cout << "Ese producto ya existe.\n";
            return;
        }
    }

    cout << "Tipo: ";
    getline(cin, p.tipo);
    cout << "Cantidad actual: ";
    cin >> p.cantidad;
    cout << "Cantidad mínima: ";
    cin >> p.minimo;
    cout << "Precio base por unidad: ";
    cin >> p.precioBase;

    p.vendidos = 0;
    asignarDatosConIVA(p);
    inventario.push_back(p);

    cout << "\nProducto agregado correctamente.\n";
    cout << "Precio con IVA: $" << p.precioFinal << endl;
}

void mostrarMatrizProductos() {
    string matriz[3][3] = {
        {"Acetaminofen", "Cuadernos", "Arroz"},
        {"Fenilefrina", "Colores",     "Leche"},
        {"Condones",     "Carpetas",    "Azúcar"}
    };

    cout << left << setw(15) << "Droguería" << setw(15) << "Papelería" << setw(15) << "Supermercado" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << left << setw(12) << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int opcion;

    // Cargar productos base
    vector<Producto> base = {
        {"Acetaminofen", "drogueria", 100, 20, 4.50, 0.0, 0},
        {"Fenilefrina", "drogueria", 50, 10, 6.00, 0.0, 0},
        {"Cuadernos", "papeleria", 80, 15, 2.20, 0.0, 0},
        {"Arroz", "supermercado", 200, 50, 1.10, 0.0, 0}
    };
    for (auto& p : base) {
        asignarDatosConIVA(p);
        inventario.push_back(p);
    }

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: visualizarProductos(); break;
            case 2: venderProducto(); break;
            case 3: abastecerProducto(); break;
            case 4: cambiarProducto(); break;
            case 5: calcularEstadisticas(); break;
            case 6: agregarProducto(); break;
            case 7: mostrarMatrizProductos(); break;
            case 8: cout << "Saliendo del programa." << endl; break;
            default: cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 8);

    return 0;
}
