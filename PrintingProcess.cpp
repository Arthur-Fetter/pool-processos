#include "PrintingProcess.h"

PrintingProcess::PrintingProcess(fila<Processo*> &filaProcessos, int pid) 
    : filaProcessos(filaProcessos), Processo(pid) {}

PrintingProcess::~PrintingProcess() {}

void PrintingProcess::execute() {
    if (filaProcessos.size() == 0) {
        cout << "A fila esta vazia, nao ha o que imprimir" << endl;
        return;
    }

    for (int i = 0; i < filaProcessos.size(); i++) {
        Processo *processo = filaProcessos.front();
        processo->imprime();
        filaProcessos.push(filaProcessos.pop());
    }
}

void PrintingProcess::imprime() {
    cout << "Printing Process " << pid << endl;
}