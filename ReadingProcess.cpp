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
    if (filaProcessos.size() == 0) {
        maior_pid = 0;
    } else {
        Processo* item = filaProcessos.front();
        for (int i = 0; i < filaProcessos.size(); i++) {
            if (filaProcessos.front()->getPid() > item->getPid()) {
                item = filaProcessos.front();
            }
            filaProcessos.push(filaProcessos.pop());
        }
        maior_pid = item->getPid() + 1;
    }

    for (int i = 0; getline(arquivo, linha); i++) {
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