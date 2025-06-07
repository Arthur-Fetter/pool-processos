#include "ComputingProcess.h"

ComputingProcess::ComputingProcess(string equacao, int pid) : Processo(pid) {
    bool eq_valida = parseEquacao(equacao);
    if (!eq_valida) {
        throw invalid_argument("Equacao Invalida");
    }
}

ComputingProcess::~ComputingProcess() {}

void ComputingProcess::execute() {
    // É necessário que a operação e os operandos sejam populados antes de executar o processo.
    float resultado = 0;
    switch (operador)
    {
    case SOMA: {
        resultado = operando1 + operando2;
        break;
    }
    case SUBTRACAO: {
        resultado = operando1 - operando2;
        break;
    }
    case MULTIPLICACAO: {
        resultado = operando1 * operando2;
        break;
    }
    case DIVISAO: {
        resultado = operando1 / operando2;
        break;
    }
    default:
        break;
    }

    cout << "Resultado da operação: " << resultado << endl;
}

void ComputingProcess::imprime() {
    char op;

    switch (operador)
    {
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
        break;
    }

    cout << "Computing Process" << pid << endl;
    cout << "Equacao a ser executada: " << operando1 << op << operando2 << endl;
}