#ifndef DECOMET2_H
#define DECOMET2_H

#include <string>

using namespace std;

void bloque(string binario,string &cadena1,int n,int &i)
{
    int k;
    for (k = 0; k < n; k++)
    {
        if (i < binario.size())
        {
            cadena1 += binario[i];
            i++;
        }
    }
}

void invierte (string cadena1,string &cadena2,int n)
{
    int k,j = 0;

    for(k = 1; k < n; k++)
    {
       cadena2 +=  cadena1 [k];
    }
    cadena2 += cadena1[j];
}


#endif // DECOMET2_H
