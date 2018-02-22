//S00279821
//Jan 30 2018
//Alexander Casanas
//Programa que imprime las tablas de multiplicar

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

void output(int tablasQty);
int welcome();

int main()
{
    output(welcome());

    return 0;
}

//
int welcome() 
{
    int tablasQty;
    cout << "\nEste programa le mostrará las tablas de multiplicar desde el cero hasta el número que usted escoja.\n" << endl;
    do 
    {
        cout << "Entre hasta que número quiere ver las tablas: (Máximo 25)" << endl;
        cin >> tablasQty;
    }
    while (tablasQty < 0 || tablasQty > 25);

    return tablasQty;
}

void output(int tablasQty) 
{
    string numbers[31] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve", "veinte", "veintiuno", "veintidos", "veintitres", "veinticuatro", "veinticinco"};
    string tabla;
    string linea;
    ostringstream heading;

    // Salvamos el string a imprimir en heading para poder medirlo.
    // La razón de medir esta línea es para poder trazar una línea divisora.
    // Si sólo es por estética...
    heading << setw(25) << left << "| Multiplicado por";
    for (int multiplos = 0; multiplos <= tablasQty; multiplos++)
    {
        heading << setw(5) << right << multiplos;
    }
    for (int lines = 0; lines < heading.str().size(); lines++)
    {
        linea += "-";
    }

    // Aquí comienza el output
    cout << "\n\n";
    cout << " " << linea << endl;
    cout << heading.str() << " |\n";
    cout << " " << linea << endl;

    // Aquí imprimimos la tabla de multiplicar según el número solicitado por el usuario...
    for (int i = 0; i <= tablasQty; i++)
    {
        tabla = "| Tabla del " + numbers[i];
        cout << setw(25) << left << tabla;
        for (int j = 0; j <= tablasQty; j++)
        {
            cout << setw(5) << right << i * j;
        }
        cout << " |" << endl;
    }
    cout << " " << linea << endl;
}