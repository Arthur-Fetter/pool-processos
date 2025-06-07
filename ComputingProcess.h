#pragma once

#include "Processo.h"
#include <string>
#include <iostream>

using namespace std;

class ComputingProcess : public Processo {
private:

public:
    ComputingProcess(string equacao, int pid);
    ~ComputingProcess();
    void execute();
    void imprime();
};
