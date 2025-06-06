#pragma once

#include "Processo.h"
#include "Fila.h"
#include <iostream>

class PrintingProcess : public Processo {
private:
    fila<Processo*> &filaProcessos;
public:
    PrintingProcess(fila<Processo*> &filaProcessos, int pid);
    ~PrintingProcess();
    void execute();
    void imprime();
};
