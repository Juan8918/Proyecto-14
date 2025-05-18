#include <iostream>
#include <iomanip> // Se usa para formatear la forma de salida de los datos
using namespace std;

int main() 
{
  int i,j;  
    string matriz[3][3]; // 3 filas y 3 columnas

matriz[0][0]="Acetaminofen"; // productos de droguería
matriz[1][0]="Fenilefrina";
matriz[2][0]="Condones";
    
matriz[0][1]="Cuadernos"; // productos de papeleria
matriz[1][1]="Colores";
matriz[2][1]="Carpetas";
                
matriz[0][2]="Arroz"; // productos de supermercado
matriz[1][2]="Leche";
matriz[2][2]="Azúcar";
        
        for (i = 0; i < 3; i++) // para correr en la matriz
        {
            for (j = 0; j < 3; j++)
            {}
            
        }
        
                
         for (i = 0; i < 3; i++)
        {
       
         
            for (j = 0; j < 3 ; j++)
            {
                cout << "| " << left << setw(12) << matriz[i][j] << " "; // muestra los datos sepadardos por "|" para que se pueda ver tipo tabla. Los datos se ven más legibles y se pueda comprender la categoría.
            }
        
        cout << "\n";
        }

    return 0;
}