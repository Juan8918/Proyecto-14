#include <iostream>
#include <string>
using namespace std;

/* Requerimiento funcional 1 de 4:
    Productos por categoría:
    -------------------------
    Droguería:
        - Acetaminofen
        - Fenilefrina
        - Condones

    Papelería:
        - Cuadernos
        - Colores
        - Carpetas

    Supermercado:
        - Arroz
        - Leche
        - Azúcar

    Atributos de las estructuras:
    ----------------------------
    - Estructura Producto:
        - nombre: El nombre del producto (string).
        - tipo: La categoría del producto (papelería, droguería, supermercado).
        - cantidad: La cantidad disponible en bodega (int).
        - minimo: La cantidad mínima para abastecer el producto (int).
        - precioBase: El precio base del producto (float).
        - precioFinal: El precio final con IVA correspondiente (float).

    - Estructura Venta:
        - nombreProducto: El nombre del producto vendido.
        - cantidadVendida: La cantidad de productos vendidos.
        - totalVenta: El total de dinero recibido por la venta (precio final * cantidad).

    - Estructura Estadisticas:
        - totalVentas: El total de dinero obtenido por todas las ventas.
        - productoMasVendido: El nombre del producto más vendido.
        - productoMenosVendido: El nombre del producto menos vendido.
*/

struct Producto {
    string nombre;      
    string tipo;        
    int cantidad;      
    int minimo;         
    float precioBase;   
    float precioFinal;  

    
    void asignarDatosConIVA();

    
    void mostrar();
};


struct Venta {
    string nombreProducto;  
    int cantidadVendida;    
    float totalVenta;       
};


struct Estadisticas {
    float totalVentas;          
    string productoMasVendido;    
    string productoMenosVendido;  
};

// Definición de las funciones de la estructura Producto

// Función para pedir los datos del producto y calcular el precio final con IVA
void Producto::asignarDatosConIVA() {
    cout << "Ingresa la cantidad disponible: ";
    cin >> cantidad;
    cout << "Ingresa la cantidad mínima para abastecer: ";
    cin >> minimo;
    cout << "Ingresa el precio base del producto: ";
    cin >> precioBase;

   
    if (tipo == "papeleria") {
        precioFinal = precioBase + (precioBase * 0.16);  // 16% IVA para papelería
    } else if (tipo == "drogueria") {
        precioFinal = precioBase + (precioBase * 0.12);  // 12% IVA para droguería
    } else if (tipo == "supermercado") {
        precioFinal = precioBase + (precioBase * 0.04);  // 4% IVA para supermercado
    }
}

// Función para mostrar los datos del producto
void Producto::mostrar() {
    cout << "\n--- DATOS DEL PRODUCTO ---\n";
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Cantidad en bodega: " << cantidad << endl;
    cout << "Cantidad mínima: " << minimo << endl;
    cout << "Precio base: $" << precioBase << endl;
    cout << "Precio final con IVA: $" << precioFinal << endl;
    cout << "\n";
}

/**
 * Requerimiento Funcional 1: Visualizar la información de los productos.
 *
 * El sistema debe permitir al usuario visualizar la información detallada de todos
 * los productos disponibles en el inventario, como su nombre, tipo, cantidad
 * actual, cantidad mínima para abastecimiento, precio base y precio final (con
 * impuestos).
 *
 * Entradas: Solicitud del usuario para visualizar la información de los productos.
 *
 * Salidas: Lista de productos con su información detallada (nombre, tipo, cantidad
 * actual, cantidad mínima para abastecimiento, precio base y precio final).
 */

int main() {
    Producto productos[9]; 
    int opcionProducto;     
    string categoria;       

   

    // Productos de Droguería
    productos[0].tipo = "drogueria";
    productos[0].nombre = "Acetaminofen";
    productos[0].asignarDatosConIVA();

    productos[1].tipo = "drogueria";
    productos[1].nombre = "Fenilefrina";
    productos[1].asignarDatosConIVA();

    productos[2].tipo = "drogueria";
    productos[2].nombre = "Condones";
    productos[2].asignarDatosConIVA();

    // Productos de Papelería
    productos[3].tipo = "papeleria";
    productos[3].nombre = "Cuadernos";
    productos[3].asignarDatosConIVA();

    productos[4].tipo = "papeleria";
    productos[4].nombre = "Colores";
    productos[4].asignarDatosConIVA();

    productos[5].tipo = "papeleria";
    productos[5].nombre = "Carpetas";
    productos[5].asignarDatosConIVA();

    // Productos de Supermercado
    productos[6].tipo = "supermercado";
    productos[6].nombre = "Arroz";
    productos[6].asignarDatosConIVA();

    productos[7].tipo = "supermercado";
    productos[7].nombre = "Leche";
    productos[7].asignarDatosConIVA();

    productos[8].tipo = "supermercado";
    productos[8].nombre = "Azucar";
    productos[8].asignarDatosConIVA();

    // Mostramos la información de todos los productos
    for (int i = 0; i < 9; i++) {
        productos[i].mostrar();
    }

    return 0;
}