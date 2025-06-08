#include "WritingProcess.h"

WritingProcess::WritingProcess(string expressao, int pid) 
    : Processo(pid) {
    bool eq_valida = parseEquacao(expressao);
    if (!eq_valida) {
        throw invalid_argument("Equacao Invalida");
    }

    this->expressao = expressao;
} 

WritingProcess::~WritingProcess() {}

void WritingProcess::execute() {
    if (!writeToFile(expressao)) {
        cout << "Equacao invalida" << endl;
        return;
    }

    cout << "ComputingProcess criado com sucesso!" << endl;
}

bool WritingProcess::writeToFile(string expressao) {
    if (!parseEquacao(expressao)) {
        return false;
    }

    ofstream file("computation.txt", ios::app);

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
        return false;
    }
    
    file << operando1 << op << operando2 << "\n";

    file.close();
    
    return true;
}

void WritingProcess::setExpressao(string expressao) {
    this->expressao = expressao;
}

string WritingProcess::getExpressao() {
    return expressao;
}

void WritingProcess::imprime() {
    cout << "Writing Process " << pid << endl;
    cout << "Equacao a ser impressa: " << expressao << endl;
}