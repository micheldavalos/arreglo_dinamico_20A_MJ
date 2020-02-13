#include <iostream>
#include "Arreglo.h"
#include "personaje.h"
using namespace std;
#define T Personaje

int main()
{
    Arreglo<T> arreglo;
    string op;

    while (true) {
        cout << "1) Agregar final" << endl;
        cout << "2) Agregar inicio" << endl;
        cout << "3) Agregar posicion" << endl;
        cout << "4) Mostrar" << endl;
        cout << "5) Eliminar final" << endl;
        cout << "6) Eliminar inicio" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            T e;
            cin >> e;
            arreglo.insertar_final(e);
        }
        else if (op == "2") {
            T e;
            cin >> e;
            arreglo.insertar_inicio(e);
        }
        else if (op == "3") {
            T e;
            size_t p;
            cin >> e;
            cout << "posicion: ";
            cin >> p;
            arreglo.insertar(e, p);
        }
        else if (op == "4") {
            for (size_t i = 0; i < arreglo.size(); ++i) {
                cout << arreglo[i] << endl;
            }
        }
        else if (op == "5") {
            arreglo.eliminar_final();
        }
        else if (op == "6") {
            arreglo.eliminar_inicio();
        }
        else if (op == "0") {
            break;
        }
    }


    return 0;
}
