#include "Processo.h"

bool Processo::parseEquacao(string equacao) {
    char op;
    if (sscanf(equacao.c_str(), "%d%c%d", &operando1, &op, &operando2) != 3) {
        return false;
    }

    switch (op)
    {
    case '+':
        operador = SOMA;
        break;
    case '-':
        operador = SUBTRACAO;
        break;
    case '/':
        operador = DIVISAO;
        break;
    case '*':
        operador = MULTIPLICACAO;
        break;
    default:
        return false;
    }

    return true;
}