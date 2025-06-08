#pragma once

#include "Processo.h"
#include "Fila.h"
#include "ComputingProcess.h"
#include "PrintingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Gerenciador {
private:
    fila<Processo*> *filaProcessos;
    enum TIPO_PROCESSO {
        COMPUTING_PROCESS = 1,
        PRINTING_PROCESS,
        READING_PROCESS,
        WRITING_PROCESS
    };
public:
    Gerenciador();
    ~Gerenciador();
    void run();
    bool criarProcesso(TIPO_PROCESSO tipo_processo);
    int maiorPid();
};
