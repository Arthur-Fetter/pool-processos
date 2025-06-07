#include "Processo.h"

int Processo::getPid() {
    return pid;
}

int Processo::getOperando1() {
    return operando1;
}

int Processo::getOperando2() {
    return operando2;
}

char Processo::getOperador() {
    char op;

    switch (operador) {
    case SOMA:
        op = '+';
        break;
    case SUBTRACAO:
        op = '-';
        break;
    case DIVISAO:
        op = '/';
        break;
    case MULTIPLICACAO:
        op = '*';
        break;
    default:
        return false;
    }
    return op;
}

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

    if (operador == DIVISAO && operando2 == 0) {
        return false;
    }

    return true;
}

bool operator>(const Processo& processoA, const Processo& processoB) {
    return processoA.pid > processoB.pid;
}