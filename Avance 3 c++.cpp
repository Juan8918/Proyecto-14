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