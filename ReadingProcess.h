#include "Processo.h"
#include "Fila.h"
#include <fstream>

class ReadingProcess : public Processo {
private:
    fila<Processo*> &filaProcessos;
public:
    ReadingProcess(fila<Processo*> &filaProcessos, int pid);
    ~ReadingProcess();
    void execute();
    void imprime();
};
