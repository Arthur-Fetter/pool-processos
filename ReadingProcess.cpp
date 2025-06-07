#include "ReadingProcess.h"
#include "ComputingProcess.h"

ReadingProcess::ReadingProcess(fila<Processo*> &filaProcessos, int pid) 
    : filaProcessos(filaProcessos), Processo(pid) {}

ReadingProcess::~ReadingProcess(){}

void ReadingProcess::execute() {
    ifstream arquivo("computation.txt");

    if (!arquivo) {
        return;
    }

    string linha;
    int maior_pid;
    
    try {
        filaProcessos.largest()->getPid();
    } catch (const exception& e) {
        maior_pid = 0;
    }
    
    for (int i = 1; getline(arquivo, linha); i++) {
        ComputingProcess* novo_processo = new ComputingProcess(linha, maior_pid + i);
        filaProcessos.push(novo_processo);
    }

    arquivo.close();

    ofstream fechar_arquivo("computation.txt");
    fechar_arquivo.close();
}

void ReadingProcess::imprime() {
    cout << "Reading Process " << pid << endl;
}