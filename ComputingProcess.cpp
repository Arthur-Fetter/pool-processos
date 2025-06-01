#include "ComputingProcess.h"

ComputingProcess::ComputingProcess() {}

ComputingProcess::ComputingProcess(string equacao) {
    bool eq_valida = parseEquacao(equacao);
    if (!eq_valida) {
        cout << "Equacao invalida." << endl;
        return;
    }
    executar();
}

ComputingProcess::~ComputingProcess() {}

void ComputingProcess::executar() {
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
