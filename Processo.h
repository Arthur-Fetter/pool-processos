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
    Processo() {};
    virtual ~Processo() {};
    virtual void execute() = 0;
    virtual void imprime() = 0;
    bool parseEquacao(string equacao);
};
