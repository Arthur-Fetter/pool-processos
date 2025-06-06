#pragma once
#include <string>

using namespace std;

class Processo {
protected:
    enum OPERADORES {
        SOMA,
        SUBTRACAO,
        DIVISAO,
        MULTIPLICACAO
    };
    int operando1;
    int operando2;
    OPERADORES operador;
    int pid;
public:
    Processo(int pid) : pid(pid) {};
    virtual ~Processo() {};
    int getPid();
    int getOperando1();
    int getOperando2();
    char getOperador();
    virtual void execute() = 0;
    virtual void imprime() = 0;
    bool parseEquacao(string equacao);
    friend bool operator>(const Processo& processoA, const Processo& processoB); 
};
