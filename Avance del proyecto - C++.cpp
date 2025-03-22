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