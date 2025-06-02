#include "ReadingProcess.h"
#include "ComputingProcess.h"

ReadingProcess::ReadingProcess(fila<Processo> &filaProcessos) 
    : filaProcessos(filaProcessos) {}

ReadingProcess::~ReadingProcess(){}

void ReadingProcess::execute() {
    ifstream arquivo("computation.txt");

    if (!arquivo) {
        return;
    }

    string linha;
    while (getline(arquivo, linha)) {
        ComputingProcess novo_processo = ComputingProcess(linha);
    }

    arquivo.close();

    ofstream arquivo("computation.txt");
    arquivo.close();
}