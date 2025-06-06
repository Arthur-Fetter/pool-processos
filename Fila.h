#pragma once
#include "Nodo.h"
#include <stdexcept>

template <class T>
class fila {
public:
    fila();
    ~fila();
    void push(T data);
    T pop();
    T front();
    bool find(T data);
    T remove(T data);
    int size();
    T largest();
protected:
    int tamanho;
    Nodo<T>* base;
    Nodo<T>* topo;
};

template <class T>
fila<T>::fila() {
    tamanho = 0;
    base = nullptr;
    topo = nullptr;
}

template <class T>
fila<T>::~fila() {

}

template <class T>
void fila<T>::push(T data) {
    if (base == nullptr) {
        base = new Nodo<T>(data);
        topo = base;
        tamanho++;
        return;
    }
    if (base == topo) {
        base = new Nodo<T>(data);
        base->setProximo(topo);
        topo->setAnterior(base);
        tamanho++;
        return; 
    }

    Nodo<T>* temp_nodo = base;
    base = new Nodo<T>(data);
    base->setProximo(temp_nodo);
    temp_nodo->setAnterior(base);
    tamanho++;
}

template <class T>
T fila<T>::pop() {
    if (topo == nullptr) {
        throw std::runtime_error("Nao e possivel deletar de uma fila vazia");
    }
    if (base == topo) {
        T data_nodo = topo->getData();
        delete topo;
        topo = nullptr;
        base = nullptr;
        tamanho--;
        return data_nodo;
    }

    Nodo<T>* temp_nodo = topo;
    T data_nodo = topo->getData();
    topo = topo->getAnterior();
    topo->setProximo(nullptr);
    delete temp_nodo;
    tamanho--;
    return data_nodo;
}

template <class T>
T fila<T>::front() {
    if (topo == nullptr) {
        throw std::runtime_error("Nao e possivel retornar o valor de uma fila vazia");
    }
    
    return topo->getData();
}

template <class T>
bool fila<T>::find(T data) {
    if (tamanho == 0) {
        return false;
    }

    bool existe;
    existe = false;
    for (int i = 0; i < tamanho; i++) {
        if (topo == nullptr) {
            break;
        }
        
        if (topo->getData() == data) {
            existe = true;
        }

        this->push(this->pop());
    }

    return existe;
}

template <class T>
T fila<T>::remove(T data) {
    bool deletado = false;
    T data_deletado{};
    for (int i = 0; i < tamanho; i++) {
        if (topo == nullptr) {
            break;
        }

        if (deletado == false && topo->getData() == data) {
            data_deletado = this->pop();
            deletado = true;
        }

        this->push(this->pop());
    }

    return data_deletado;
}

template <class T>
int fila<T>::size() {
    return tamanho;
}

template <class T>
T fila<T>::largest() {
    if (tamanho == 0) {
        throw std::runtime_error("Nao e possivel retornar o valor de uma fila vazia");
    }

    T item = front();
    for (int i = 0; i < size(); i++) {
        if (front() > item) {
            item = front();
        }
    }

    return item;
}