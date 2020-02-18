#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<class T>
class Arreglo
{
    T *arreglo;
    size_t cont;
    size_t tam;
    const static size_t MAX = 5;

public:
    Arreglo();
    Arreglo(size_t t, const T &v);
    void insertar_final(const T &dato);
    void insertar_inicio(const T &dato);
    void insertar(const T &dato, size_t posicion);

    void eliminar_final();
    void eliminar_inicio();
    void eliminar(size_t p);

    T *buscar(T &dato);
    Arreglo<T*> buscar_todos(T &dato);

    void sort();

    size_t size();
    T& operator[](size_t posicion);

    void operator=(const Arreglo<T> &a);
    void operator=(const Arreglo<T> *a);


private:
    void expandir();
};


template<class T>
Arreglo<T>::Arreglo()
{
    arreglo = new T[MAX];
    cont = 0;
    tam = MAX;
}

template<class T>
Arreglo<T>::Arreglo(size_t t, const T &v)
{
    arreglo = new T[t];

    for (size_t i = 0; i < t; i++) {
        arreglo[i] = v;
    }

    tam = t;
    cont = t;
}

template<class T>
void Arreglo<T>::insertar_final(const T &dato)
{
    if (cont == tam) {
        expandir();
    }
    arreglo[cont] = dato;
    cont++;
}

template<class T>
void Arreglo<T>::insertar_inicio(const T &dato)
{
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > 0; i--) {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[0] = dato;
    cont++;
}

template<class T>
void Arreglo<T>::insertar(const T &dato, size_t posicion)
{
    if (posicion >= cont) {
        throw out_of_range("posicion no valida");
    }
    if (cont == tam) {
        expandir();
    }
    for (size_t i = cont; i > posicion; i--) {
        arreglo[i] = arreglo[i-1];
    }
    arreglo[posicion] = dato;
    cont++;
}

template<class T>
void Arreglo<T>::eliminar_final()
{
    if (cont == 0) {
        throw out_of_range("arreglo vacio");
    }
    cont--;
}

template<class T>
void Arreglo<T>::eliminar_inicio()
{
    if (cont == 0) {
        throw out_of_range("arreglo vacio");
    }
    for (size_t i = 0; i < cont - 1; ++i) {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template<class T>
void Arreglo<T>::eliminar(size_t p)
{
    if (p >= cont) {
        throw out_of_range("Posicion no valida");
    }

    for (size_t i = p; i < cont-1; i++) {
        arreglo[i] = arreglo[i+1];
    }
    cont--;
}

template<class T>
T* Arreglo<T>::buscar(T &dato)
{
    for (size_t i = 0; i < size(); ++i) {
        if (dato == arreglo[i]) {
            return &arreglo[i];
        }
    }

    return nullptr;
}

template<class T>
Arreglo<T *> Arreglo<T>::buscar_todos(T &dato)
{
    Arreglo<T*> a;

    for (size_t i = 0; i < size(); ++i) {
        if (dato == arreglo[i]) {
            a.insertar_final(&arreglo[i]);
        }
    }

    return a;
}

template<class T>
void Arreglo<T>::sort()
{
    for (size_t i = 0; i < cont; ++i) {
        size_t min = i;
        for(size_t j = i+1; j < cont; ++j) {
            if (arreglo[min] > arreglo[j]) {
                min = j;
            }
        }
        T temp = arreglo[i];
        arreglo[i] = arreglo[min];
        arreglo[min] = temp;
    }
}

template<class T>
size_t Arreglo<T>::size()
{
    return cont;
}

template<class T>
T &Arreglo<T>::operator[](size_t posicion)
{
    if (posicion >= cont) {
        throw out_of_range("posicion no valida");
    }

    return arreglo[posicion];
}

template<class T>
void Arreglo<T>::operator=(const Arreglo<T> &a)
{
    delete []arreglo;

    arreglo = new T[a.tam];

    for (size_t i = 0; i < a.cont; i++) {
        arreglo[i] = a.arreglo[i];
    }

    tam = a.tam;
    cont = a.cont;

}

template<class T>
void Arreglo<T>::operator=(const Arreglo<T> *a)
{
    delete [] arreglo;

    arreglo = a->arreglo;
    tam = a->tam;
    cont = a->cont;
}

template<class T>
void Arreglo<T>::expandir()
{
    T *nuevo = new T[tam+MAX];

    for (size_t i = 0; i < cont; ++i) {
        nuevo[i] = arreglo[i];
    }

    delete []arreglo;
    arreglo = nuevo;
    tam = tam + MAX;
}

#endif // ARREGLO_H
