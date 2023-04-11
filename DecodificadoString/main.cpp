#include <iostream>
#include "decomet1.h"
#include "decomet2.h"


using namespace std;

int main()
{
    int metodo = 0;int n = 0;int i = 0;
    int l = 0; int resultado = 0;int c = 0;
    bool lectura = false;


    string cadena1;string cadena2;
    string fuente;string salida;
    string binario;string codif;
    string decodif;

    while (lectura == false)
    {
        cout <<"Ingresa el nombre del archivo fuente para decodificar: ";cin>>fuente;
        leerbinario(binario,fuente,lectura);

    }

    cout <<"Ingresa nombre para el archivo de salida decodificado: ";cin>>salida;
    cout <<"Selecciona un metodo para decodificar: ";cin >> metodo;
    cout <<"Ingresa un número que será la semilla decodificación: ";cin>>n;

    int p = binario.size();

    if (metodo == 1)
    {
        int k = 0;int r = 0;
        int cero = 0; int uno = 0;      

        for (k = 0 ; k < n ; k++)
        {
            if (binario[k] == '0')
            {
                codif += '1';
            }
            else
            {
                codif += '0';
            }

        }


        while (r < p)
        {
            cadenabase(binario,cadena1,n,i);
            r = i;
            cadenamodif(binario,cadena2,n,r);


            if (cadena2.size() == n)
            {
                contador(cadena1,cero,uno,n);

                if (cero == uno)
                {
                    ceroigualuno (cadena2,n);
                    codif += cadena2;

                }
                if (cero > uno)
                {
                    ceromayoruno (cadena2,n);
                    codif += cadena2;

                }
                if (cero < uno)
                {
                    ceromayoruno (cadena2,n);
                    codif += cadena2;

                }

                cadena1 = "";
                cadena2 = "";
            }

            else
            {
                codif += cadena2;
            }
        }

        while (c < p)
        {

            binachar (codif,c,resultado);
            decodif +=  char(resultado);
            l++;

        }

        ofstream texto;
        texto.open(salida);
        texto<<decodif;
        texto.close();
        cout<<"\¡Hecho!\n";

    }


    if (metodo == 2)
    {
        int j=0;

        while( i < p)
        {
            bloque(binario,cadena1,n,i);

            if (cadena1.size() == n)
            {
                invierte(cadena1,cadena2,n);
                codif += cadena2;

                cadena1 = "";
                cadena2 = "";
            }
            else
            {
                codif += cadena1;
            }

        }


        while (c < p-1)
        {

            binachar (codif,c,resultado);
            decodif +=  char(resultado);
            l++;

        }

        ofstream texto;
        texto.open(salida);
        texto<<decodif;
        texto.close();
        cout<<"\¡Hecho!\n";

    }

  return 0;
}
