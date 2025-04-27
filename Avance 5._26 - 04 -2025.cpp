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