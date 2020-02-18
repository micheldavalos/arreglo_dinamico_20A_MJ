#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>

using namespace std;

class Personaje
{
public:
    Personaje();
    void setNombre(string n);
    string getNombre();
    int getSalud() const;
    void setSalud(int value);

    int getFuerza() const;
    void setFuerza(int value);

    string getTipo() const;
    void setTipo(const string &value);

    friend ostream & operator <<(ostream &out,
                                 const Personaje &p)
    {
        out << "Nombre: " << p.nombre << endl;
        out << "Tipo:   " << p.tipo << endl;
        out << "Fuerza: " << p.fuerza << endl;
        out << "Salud:  " << p.salud << endl;

        return out;
    }

    friend istream& operator >>(istream &in,
                                Personaje &p)
    {
        string s;
        int valor;

        cout << "Nombre: ";
        getline(cin, s);
        p.setNombre(s);

        cout << "Tipo: ";
        getline(cin, s);
        p.setTipo(s);

        cout << "Fuerza: ";
        cin >> valor;
        p.setFuerza(valor);

        cout << "Salud: ";
        cin >> valor; cin.ignore();
        p.setSalud(valor);

        return in;
    }

    bool operator==( Personaje &p)
    {
        return nombre == p.nombre;
    }

    bool operator<(Personaje &p)
    {
        return nombre < p.nombre;
    }
    bool operator>(Personaje &p)
    {
        return nombre > p.nombre;
    }

private:
    string nombre;
    int salud;
    int fuerza;
    string tipo;
};

#endif // PERSONAJE_H
