#pragma once
#include "Processo.h"
#include <string>
#include <iostream>

using namespace std;

class ComputingProcess : public Processo {
private:

public:
    ComputingProcess();
    ComputingProcess(string equacao);
    ~ComputingProcess();
    void execute();
    void imprime();
};
