// Resumen de todos los avances juntos(códigos)
// Avance #2
#include<iostream>
using namespace std;
int main()
{ 
int Servicio;
cout<<"Bienvenido a MercaPlus.";
cout<<"\nLos servicios que tenemos son: ";
cout<<"\n1.Visualizar la información de los productos. \n2.Vender un producto. \n3.Abastecer la tienda con un producto. \n4.Cambiar un producto. \n5.Calcular estadísticas de ventas:";
cout<<"\n Digita el numero del servicio que deseas: "; cin>>Servicio;
switch(Servicio){
    case 1: cout<<"Has elegido la opción de visualizar la información de los productos."; break;
    case 2: cout<<"Has elegido la opción de vender un producto."; break;
    case 3: cout<<"Has elegido la opción de abastecer la tienda con un producto."; break;
    case 4: cout<<"Has elegido la opción de cambiar un producto."; break;
    case 5: cout<<"Has elegido la opción de calcular estadísticas de ventas."; break;
    default: cout<<"No ofrecemos dicho servicio.";
}
    return 0;
}
// Avance #3
#include <iostream>
using namespace std;

main()
{
    cout<<"Bienvenido a mi app \n";
    cout<<"Selecciona una opción"<<endl;
    int opcion;
    
    
    
    
    do
    {
        cout<<"\n1.xx 2.xx 3.Salir";
        cin>>opcion;
        switch(opcion)
        {
            case 1:
            {
                cout<<"hola desde la opcion 1";
            }break;
            case 2:
            {
                cout<<"hola desde la opcion 2";
            }break;
            case 3:
            {
                cout<<"Salir";
            }break;
            default:
            {
                cout<<"Intenta nuevamente";
            }
            
        }
    }while(opcion != 3);    
    
    cout<<"Gracias por usar mi app";
    

}
// Avance #4
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
// Avance #5
#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    string categoria;
    int precio;
    int cantidad;
};

int main() {
    Producto listaProductos[9];

    listaProductos[0] = {"Acetaminofen", "drogueria", 500, 100};
    listaProductos[1] = {"Fenilefrina", "drogueria", 800, 50};
    listaProductos[2] = {"Condones", "drogueria", 1200, 20};
    listaProductos[3] = {"Cuadernos", "papeleria", 2500, 30};
    listaProductos[4] = {"Colores", "papeleria", 1800, 60};
    listaProductos[5] = {"Carpetas", "papeleria", 3000, 25};
    listaProductos[6] = {"Arroz", "mercado", 1500, 15};
    listaProductos[7] = {"Leche", "mercado", 1000, 10};
    listaProductos[8] = {"Azúcar", "mercado", 900, 20};

    string categoria;
    cout << "Ingrese la categoria (drogueria, papeleria, mercado): ";
    cin >> categoria;

    cout << "\nProductos en la categoria " << categoria << ":\n";
    for(int i = 0; i < 9; i++) {
        if(listaProductos[i].categoria == categoria) {
            cout << "- " << listaProductos[i].nombre
                 << ", Precio: " << listaProductos[i].precio
                 << ", Cantidad: " << listaProductos[i].cantidad << "\n";
        }
    }

    return 0;
}
// Avance #6
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
// Avance #7
#include <iostream>   
#include <vector>     // Para usar la estructura vector
#include <string>     
using namespace std;  

// Estructura que define un producto con sus propiedades
struct Producto {
    string nombre;     // Nombre del producto (ej: "pan")
    string tipo;       // Categoría (ej: "supermercado")
    int cantidad;      // Unidades disponibles en inventario
    float precio_base; // Precio sin IVA
    int vendidos;      // Unidades vendidas
};

// Inventario inicial con algunos productos precargados
vector<Producto> inventario = {
    {"pan", "supermercado", 100, 1500.0f, 0}  // Producto inicial: pan
};

// Variable global para acumular el total de ventas
float total_ventas = 0.0f;

// Función que calcula el precio final aplicando el IVA correspondiente
float calcularPrecioFinal(const Producto& p) {
    float iva = 0.0f;  // Por defecto 0% de IVA
    
    // Asigna porcentaje de IVA según el tipo de producto
    if (p.tipo == "papeleria") iva = 0.16f;      // 16% IVA
    else if (p.tipo == "supermercado") iva = 0.04f; // 4% IVA
    else if (p.tipo == "drogueria") iva = 0.12f;    // 12% IVA
    
    // Retorna precio base + IVA
    return p.precio_base * (1 + iva);
}

// Función para procesar la venta de un producto
void venderProducto() {
    string nombre;  // Almacenará el nombre del producto a vender
    int cantidad;   // Almacenará la cantidad a vender
    
    // Solicita datos al usuario
    cout << "Nombre del producto: ";
    cin >> nombre;
    cout << "Cantidad a vender: ";
    cin >> cantidad;

    // Busca el producto en el inventario
    for (auto& p : inventario) {
        // Si encuentra el producto y hay suficiente stock
        if (p.nombre == nombre && p.cantidad >= cantidad) {
            // Calcula el total de la venta (precio final * cantidad)
            float venta = calcularPrecioFinal(p) * cantidad;
            
            // Actualiza inventario
            p.cantidad -= cantidad;    // Reduce el stock
            p.vendidos += cantidad;    // Aumenta unidades vendidas
            total_ventas += venta;     // Acumula a ventas totales
            
            // Muestra resultado al usuario
            cout << "Venta realizada: $" << venta << endl;
            return;
        }
    }
    // Si no encontró el producto o no hay stock suficiente
    cout << "Producto no encontrado o sin stock.\n";
}

// Función principal
int main() {
    venderProducto();  // Llama a la función de venta
    return 0;          // Indica que el programa terminó correctamente
}
#include <iostream>       
#include <vector>          
#include <string>        
using namespace std;      

// Definición de la estructura Producto
struct Producto {
    string nombre;        // Nombre del producto (ej: "lapicero")
    int cantidad;         // Cantidad disponible en inventario
};

// Vector que almacena los productos en inventario (inicializado con un producto)
vector<Producto> inventario = {
    {"lapicero", 10}      // Producto inicial: lapicero con 10 unidades
};

// Función para aumentar el stock de un producto existente
void abastecerProducto() {
    string nombre;        // Variable para almacenar el nombre del producto a buscar
    int cantidad;         // Variable para almacenar la cantidad a agregar
    
    // Solicita datos al usuario
    cout << "Producto a abastecer: ";
    cin >> nombre;
    cout << "Cantidad a agregar: ";
    cin >> cantidad;

    // Recorre todos los productos en el inventario
    for (auto& p : inventario) {
        // Si encuentra el producto buscado
        if (p.nombre == nombre) {
            p.cantidad += cantidad;  // Aumenta la cantidad disponible
            cout << "Nuevo stock: " << p.cantidad << endl;  // Muestra el nuevo stock
            return;        // Termina la función después de actualizar
        }
    }
    // Si no encontró el producto
    cout << "Producto no encontrado.\n";
}

// Función principal
int main() {
    abastecerProducto();  // Llama a la función de abastecimiento
    return 0;             // Indica que el programa terminó correctamente
}

#include <iostream>       
#include <vector>       
#include <string>       
using namespace std;     

// Definición de la estructura Producto que almacena información de un producto
struct Producto {
    string nombre;       // Nombre del producto
    string tipo;         // Tipo/categoría del producto
    int cantidad_minima; // Cantidad mínima en inventario
    float precio_base;   // Precio base del producto
};

// Vector global que actúa como inventario, inicializado con un producto por defecto
vector<Producto> inventario = {
    {"pan", "supermercado", 20, 1500.0f}  // Producto inicial: nombre, tipo, cantidad, precio
};

// Función para modificar un producto existente en el inventario
void cambiarProducto() {
    string nombre;  // Variable para almacenar el nombre del producto a buscar
    
    // Solicita al usuario el nombre del producto a modificar
    cout << "Nombre del producto a cambiar: ";
    cin >> nombre;

    // Recorre todos los productos en el inventario (usando referencia para modificarlos)
    for (auto& p : inventario) {
        // Si encuentra el producto con el nombre buscado
        if (p.nombre == nombre) {
            // Solicita y actualiza cada campo del producto:
            cout << "Nuevo nombre: ";
            cin >> p.nombre;
            
            cout << "Nuevo tipo: ";
            cin >> p.tipo;
            
            cout << "Nueva cantidad mínima: ";
            cin >> p.cantidad_minima;
            
            cout << "Nuevo precio base: ";
            cin >> p.precio_base;
            
            cout << "Producto actualizado.\n";
            return;  // Termina la función después de actualizar
        }
    }
    // Mensaje si no se encontró el producto
    cout << "Producto no encontrado.\n";
}

// Función principal del programa
int main() {
    cambiarProducto();  // Llama a la función para modificar un producto
    return 0;          // Indica que el programa terminó correctamente
}

#include <iostream>   
#include <vector>     
#include <string>    
using namespace std; 

// Estructura que representa un producto con nombre y cantidad vendida
struct Producto {
    string nombre;    // Nombre del producto
    int vendidos;     // Unidades vendidas
};

// Vector global que contiene el inventario de productos con sus ventas iniciales
vector<Producto> inventario = {
    {"pan", 10}, {"lapicero", 5}, {"aspirina", 0}
};

// Variable global que almacena el total de dinero obtenido por ventas
float total_ventas = 30000.0f;

// Función que calcula y muestra estadísticas de ventas
void estadisticasVentas() {
    // Verifica si el inventario está vacío
    if (inventario.empty()) {
        cout << "No hay productos.\n";
        return;
    }

    // Punteros para almacenar productos más y menos vendidos (inicialmente el primero)
    Producto* mas = &inventario[0];
    Producto* menos = &inventario[0];
    int total_unidades = 0;  // Acumulador para total de unidades vendidas

    // Recorre todos los productos del inventario
    for (auto& p : inventario) {
        // Actualiza el producto más vendido si encuentra uno con mayores ventas
        if (p.vendidos > mas->vendidos) mas = &p;
        // Actualiza el producto menos vendido si encuentra uno con menores ventas
        if (p.vendidos < menos->vendidos) menos = &p;
        // Suma las unidades vendidas al total
        total_unidades += p.vendidos;
    }

    // Muestra los resultados
    cout << "\n--- Estadísticas ---\n";
    cout << "Más vendido: " << mas->nombre << " (" << mas->vendidos << ")\n";
    cout << "Menos vendido: " << menos->nombre << " (" << menos->vendidos << ")\n";
    cout << "Ingresos: $" << total_ventas << endl;

    // Calcula y muestra el promedio por unidad si hay ventas
    if (total_unidades > 0)
        cout << "Promedio por unidad: $" << total_ventas / total_unidades << endl;
    else
        cout << "No se han vendido productos.\n";
}

// Función principal
int main() {
    estadisticasVentas();  // Llama a la función de estadísticas
    return 0;              // Retorna 0 indicando ejecución exitosa
}