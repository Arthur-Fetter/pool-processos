#include "Processo.h"
#include <iostream>
#include <fstream>

class WritingProcess : public Processo {
private:
    string expressao;
public:
    WritingProcess(string expressao);
    ~WritingProcess();
    void execute();
    bool writeToFile(string expressao);
    void setExpressao(string expressao);
    string getExpressao();
    void imprime();
};
