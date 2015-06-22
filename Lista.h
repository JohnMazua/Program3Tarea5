#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if(inicio != NULL) return false;  // si el inicio no esta vacio retorna false
        else return true; // de lo contrario retorna verdadero (que el inicio de la lista esta vacio, por ende la lista esta vacia)
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        return inicio->valor; // Retorna el valor inicial del nodo.
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        Nodo<Tipo>*sec=inicio;  //Inicializa la variable sec como una variable apuntador con ningun valor
        while(sec->sig!=NULL) // Mientras el apuntador de la variable sig no este vacio
        {
            sec=sec->sig; // que avance a la siguiente posicion
        }
        return sec->valor;  //Retorna el ultimo valor del Nodo apuntador
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        Tipo major=0;
        Nodo<Tipo>*sec=inicio;  //Inicializa la variable sec como una variable apuntador con ningun valor
        while(sec->sig!=NULL) // Mientras el apuntador de la variable sig no este vacio
        {
            sec=sec->sig; // que avance a la siguiente posicion
            if((sec->valor)>major) major=sec->valor; // si el valor de sec es mayor que major, entonces reemplaza major con el valor actual
        }
        return major; // retorna el valor de la variable major.
    }
};
#endif // LISTA_H
