#pragma once

template <class T>
class Nodo {
public:
    Nodo();
    Nodo(T data);
    ~Nodo();
    T getData(); 
    void setData(T data);
    Nodo<T>* getProximo();
    void setProximo(Nodo<T>* proximo);
    Nodo<T>* getAnterior();
    void setAnterior(Nodo<T>* anterior);
private:
    Nodo<T>* anterior;
    Nodo<T>* proximo;
    T data;
};

template <class T>
Nodo<T>::Nodo() {
    proximo = nullptr;
    anterior = nullptr;
}

template <class T>
Nodo<T>::Nodo(T data) {
    proximo = nullptr;
    anterior = nullptr;
    this->data = data;
}

template <class T>
Nodo<T>::~Nodo() {

}

template<class T>
T Nodo<T>::getData() {
    return data;
}

template <class T>
void Nodo<T>::setData(T data) {
    this->data = data;
}

template <class T>
Nodo<T>* Nodo<T>::getProximo() {
    return proximo;
}

template <class T>
void Nodo<T>::setProximo(Nodo<T>* proximo) {
    this->proximo = proximo;
}

template <class T>
Nodo<T>* Nodo<T>::getAnterior() {
    return anterior;
}

template <class T>
void Nodo<T>::setAnterior(Nodo<T>* anterior) {
    this->anterior = anterior;
}