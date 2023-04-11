#include <iostream>
#include "metodo1.h"
#include "metodo2.h"

using namespace std;

int main()
{
    int metodo = 0;
    int n = 0;int p = 0;int i = 0;
    bool lectura = false;

    string fuente;  string salida;
    string original;string binario; string codif;
    string cadena1; string cadena2;

    while (lectura == false)
    {
        cout <<"Ingresa el nombre del archivo fuente para codificar: ";cin>>fuente;
        leer (fuente,original,p,lectura);
        cout<< "------------------------------------------------------------------\n";
    }


    cout << "---------------------------------------------------------------------\n";
    cout <<"Ingresa el nombre del archivo salida codificado: ";cin>>salida;
    cout <<"1. Primer metodo\n2. Segundo metodo\nSelecciona un metodo para codificar: ";cin >> metodo;
    cout <<"Ingresa un número que será la semilla de codificación: ";cin>>n;//numero(n);

    conversor (original,p);

    leerbinario(binario);

    p = binario.size();

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
                    ceromenoruno (cadena2,n);
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
        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();
        cout<< "¡Hecho!\n";

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

        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();
        cout<<"¡Hecho!\n";


    }


    return 0;
}
