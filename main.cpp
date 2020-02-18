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
        cout << "7) Eliminar posicion" << endl;
        cout << "8) Buscar" << endl;
        cout << "9) Buscar todos" << endl;
        cout << "10) Ordenar" << endl;
        cout << "11) Inicializar" << endl;
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
        else if (op == "7") {
            size_t p;

            cout << "posicion: ";
            cin >> p; cin.ignore();

            arreglo.eliminar(p);
        }
        else if (op == "8") {
            T t;
            cin >> t;

            T *ptr = arreglo.buscar(t);

            if(ptr != nullptr) {
                cout << "Encontrado" << endl;
                cout << *ptr << endl;
            }
            else {
                cout << "No se encontró" << endl;
            }
        }
        else if (op == "9") {
            T t;
            cin >> t;

            Arreglo<T*> a = arreglo.buscar_todos(t);

            if (a.size() > 0) {
                for (size_t i = 0; i < a.size(); i++) {
                    cout << *(a[i]) << endl;
                }
            }
            else {
                cout << "No se encontraron" << endl;
            }
        }
        else if (op == "10") {
            arreglo.sort();
        }
        else if (op == "11") {
            size_t tam;
            cout << "tamaño: " << endl;
            cin >> tam; cin.ignore();

            T t;
            cin >> t;

            arreglo = new Arreglo<T>(tam, t);
        }
        else if (op == "0") {
            break;
        }
    }


    return 0;
}
