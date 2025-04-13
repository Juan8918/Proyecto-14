#include <iostream>
using namespace std;

/*
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

    - Estructura Estadísticas:
        - totalVentas: El total de dinero obtenido por todas las ventas.
        - productoMasVendido: El nombre del producto más vendido.
        - productoMenosVendido: El nombre del producto menos vendido.
*/


struct Producto {
    string nombre;    // Nombre del producto
    string tipo;      // Tipo de producto (papelería, droguería, supermercado)
    int cantidad;     // Cantidad disponible en bodega
    int minimo;       // Cantidad mínima para abastecer
    float precioBase; // Precio base del producto
    float precioFinal; // Precio final con IVA

    // Asignar los datos del producto y calcular el precio final con IVA
    void asignarDatosConIVA(); 
    
    // Función para mostrar los datos del producto
    void mostrar(); 
};

// Estructura para manejar las ventas
struct Venta {
    string nombreProducto;  // Nombre del producto vendido
    int cantidadVendida;    // Cantidad de productos vendidos
    float totalVenta;       // Total de dinero recibido por la venta (precio * cantidad)
};

// Estructura para manejar las estadísticas
struct Estadisticas {
    float totalVentas;            // Total de dinero recibido por todas las ventas
    string productoMasVendido;    // Nombre del producto más vendido
    string productoMenosVendido;  // Nombre del producto menos vendido
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

    // Calculamos el precio final según el tipo de producto (con IVA)
    if (tipo == "papeleria") {
        precioFinal = precioBase + (precioBase * 0.16);  // 16% IVA para papelería
    }
    else if (tipo == "drogueria") {
        precioFinal = precioBase + (precioBase * 0.12);  // 12% IVA para droguería
    }
    else if (tipo == "supermercado") {
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
    cout << "---------------------------\n";
}

int main() {
    Producto producto;  // Creamos una instancia de la estructura Producto
    Venta venta;        // Creamos una instancia de la estructura Venta
    Estadisticas estadisticas;  // Creamos una instancia de la estructura Estadísticas
    int opcionProducto; // Variable para elegir el producto dentro de la categoría
    string categoria;   // Variable para guardar la categoría del producto

    // Pedimos al usuario que ingrese la categoría del producto
    cout << "¿A qué categoría pertenece el producto? (papeleria, drogueria, supermercado): ";
    cin >> categoria;

    producto.tipo = categoria;  // Asignamos la categoría al producto

    // Según la categoría, mostramos los productos disponibles
    if (categoria == "drogueria") {
        cout << "Selecciona el numero del producto:\n";
        cout << "1. Acetaminofen\n";
        cout << "2. Fenilefrina\n";
        cout << "3. Condones\n";
        cin >> opcionProducto;  // Elegimos un producto de la categoría Droguería

        // Asignamos el nombre del producto según la elección del usuario
        if (opcionProducto == 1) {
            producto.nombre = "Acetaminofen";
        }
        else if (opcionProducto == 2) {
            producto.nombre = "Fenilefrina";
        }
        else if (opcionProducto == 3) {
            producto.nombre = "Condones";
        }
    }

    else if (categoria == "papeleria") {
        cout << "Selecciona el numero del producto:\n";
        cout << "1. Cuadernos\n";
        cout << "2. Colores\n";
        cout << "3. Carpetas\n";
        cin >> opcionProducto;  // Elegimos un producto de la categoría Papelería

        // Asignamos el nombre del producto según la elección del usuario
        if (opcionProducto == 1) {
            producto.nombre = "Cuadernos";
        }
        else if (opcionProducto == 2) {
            producto.nombre = "Colores";
        }
        else if (opcionProducto == 3) {
            producto.nombre = "Carpetas";
        }
    }

    else if (categoria == "supermercado") {
        cout << "Selecciona el numero del producto:\n";
        cout << "1. Arroz\n";
        cout << "2. Leche\n";
        cout << "3. Azucar\n";
        cin >> opcionProducto;  // Elegimos un producto de la categoría Supermercado

        // Asignamos el nombre del producto según la elección del usuario
        if (opcionProducto == 1) {
            producto.nombre = "Arroz";
        }
        else if (opcionProducto == 2) {
            producto.nombre = "Leche";
        }
        else if (opcionProducto == 3) {
            producto.nombre = "Azucar";
        }
    }

    else {
        cout << "Categoría no válida.\n";  // Si la categoría no es válida
        return 0;  // Salimos del programa
    }

    // Llamamos a la función para pedir los datos del producto y calcular el precio final con IVA
    producto.asignarDatosConIVA();

    // Llamamos a la función para mostrar los datos del producto
    producto.mostrar();

    // Aquí puedes agregar la lógica de ventas y estadísticas más adelante si lo deseas.

    return 0;  // Fin del programa
}
