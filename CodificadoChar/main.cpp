#include <iostream>
#include "metodo1.h"
#include "metodo2.h"

using namespace std;


int main()
{
    int metodo = 0;
    int n = 0;int p = 0;int i = 0;int f = 0;
    bool lectura = false;

    char fuente  [20]={};
    char salida  [20]={};
    char original[30]={};

    while (lectura == false)
    {
        cout <<"Ingresa el nombre del archivo fuente para codificar: ";cin>>fuente;

        leer (fuente,original,p,lectura);

        cout<< "------------------------------------------------------------------\n";
    }

    cout <<"Ingresa el nombre del archivo salida codificado: ";cin>>salida;
    cout <<"1. Primer metodo\n2. Segundo metodo\nSelecciona un metodo para codificar: ";cin >> metodo;
    cout <<"Ingresa un número que será la semilla de codificación: ";cin>>n;

    conversor (original,p);       // Convierte el texto a binario

    p = (p*8);

    char binario[p+1] = {};
    char codif  [p+1] = {};


    leerbinario(binario);


    if (metodo == 1)
    {
        int k = 0;int r = 0;
        int cero = 0; int uno = 0;

        for (k = 0 ; k < n ; k++)          //Invierte el primer grupo de caracteres
        {
            if (binario[k] == '0')
            {
                codif[k] = '1';
            }
            else
            {
                codif[k] = '0';
            }

        }

        while (r < p)
        {
            char cadena1 [n+1] = {};
            char cadena2 [n+1] = {};

            cadenabase(binario,cadena1,n,i);    //Toma el bloque para contar unos y ceros en ella
            r = i;
            cadenamodif(binario,cadena2,n,r,p);   //Toma el bloque a la que se va a modificar
            longitud (cadena2,f);

            if (f == n)
            {
                contador(cadena1,cero,uno,n);       // Cuenta unos y ceros en la cadena base

                if (cero == uno)
                {
                    ceroigualuno (cadena2,n);
                    agregar(cadena2,codif,k,n);     //Va agregando a la línea codificada
                    k += n;
                }
                if (cero > uno)
                {
                    ceromayoruno (cadena2,n);
                    agregar(cadena2,codif,k,n);
                    k += n;
                }
                if (cero < uno)
                {
                    ceromenoruno (cadena2,n);
                    agregar(cadena2,codif,k,n);
                    k += n;
                }

            }
            else
            {
                agregar(cadena2,codif,k,n);
            }
        }

        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();
        cout<<"\n¡Hecho!\n";
    }


    if (metodo == 2)
    {
        int j=0;

        while( i < p)
        {
            char cadena1 [n+1] = {};
            char cadena2 [n+1] = {};

            bloque(binario,cadena1,n,i,p);
            longitud (cadena1,f);

            if (f == n)
            {
                invierte(cadena1,cadena2,n);
                agrega(cadena2,codif,j,n);

            }

            else
            {
                agrega(cadena1,codif,j,n);
            }

        }

        ofstream archivocodif;
        archivocodif.open(salida);
        archivocodif << codif;
        archivocodif.close();
        cout<<"¡Hecho\n!";

    }

    return 0;
}
