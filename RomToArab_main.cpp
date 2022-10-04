#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string newRomtoArab;

void stringToUpper(string& s);


int main()
{       
        do
        {
            int valor[] = { 1000, 500, 100, 50, 10, 5, 1 };
            string simbolo = "MDCLXVI", cadena;
            char c;
            int resultado = 0, i = 0, j = 0, ultimovalor = 0;
            bool valido = true;
            //i servira para la posicion de cada letra
            //j servira para la posicion del rango de valores

            cout << "Ingrese el numero Romano: ";
            cin >> cadena;
            stringToUpper(cadena);
            while (valido && (i < cadena.length()))
            {
                c = cadena[i];
                j = simbolo.find(c);
                if (j >= 0)
                {
                    resultado += valor[j];
                    //si el valor es mayor que el de la
                    //vuelta anterior del bucle, entonces
                    //el anterior debíamos haberlo restado
                    if (valor[j] > ultimovalor)
                    {
                        resultado -= 2 * ultimovalor;
                    }
                    //preparamos el ultimo valor para
                    //la siguiente vuelta del bucle
                    ultimovalor = valor[j];
                }
                else
                {
                    valido = false;
                    resultado = -1;
                }
                i++;
            }
            cout << "El numero en Arabigo es: " << resultado << endl;

            cout << "\nDeseas hacer otra conversion? (S/N o pulse cualquier tecla para finalizar)\n";
            cin >> newRomtoArab;
        } while (newRomtoArab == "S" || newRomtoArab == "s" || newRomtoArab == "Si" || newRomtoArab == "SI" || newRomtoArab == "si");

    cout << "*-* Hasta la proxima *-*\n";
    return 0;
}

void stringToUpper(string& s)
{
    for (int i = 0; i < s.length(); i++)
        s[i] = toupper(s[i]);
}