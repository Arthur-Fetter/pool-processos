#include "Gerenciador.h"

Gerenciador::Gerenciador() {
    this->filaProcessos = new fila<Processo*>();
}

Gerenciador::~Gerenciador() {}

void Gerenciador::run() {
    int escolha;
    bool rodando = true;

    while(rodando) {
        escolha = 0;
        while (escolha < 1 || escolha > 7) {
            cout << string(100, '\n');
            cout << "Gerenciador de processos" << endl;
            cout << "1 - Inserir Processo na Fila" << endl;
            cout << "2 - Executar proximo processo da fila" << endl;
            cout << "3 - Executar processo por pid" << endl;
            cout << "4 - Salvar fila de processos" << endl;
            cout << "5 - Carregar fila de processos" << endl;
            cout << "6 - Sair do programa" << endl;

            cin >> escolha;
            cin.ignore();
        }


        switch (escolha) {
        case 1: {
            escolha = 0;
            while (escolha < 1 || escolha > 4) {
                cout << "Qual processo deseja inserir?" << endl;
                cout << "1 - ComputingProcess" << endl;
                cout << "2 - PrintingProcess" << endl;
                cout << "3 - ReadingProcess" << endl;
                cout << "4 - WritingProcess" << endl;

                cin >> escolha;
                cin.ignore();
            }

            if (criarProcesso(TIPO_PROCESSO(escolha))) {
                cout << "Processo criado" << endl;
            } else {
                cout << "Nao foi possivel criar um novo processo" << endl;
            }
            
            break;
        }
        case 2: {
            if (filaProcessos->size() == 0) {
                cout << "A fila esta vazia" << endl;
                break;
            }

            filaProcessos->pop()->execute();
            break;
        }
        case 3: {
            if (filaProcessos->size() == 0) {
                cout << "A fila esta vazia" << endl;
                break;
            }
            int pid;
            bool executado = false;

            cout << "Insira o pid: ";
            cin >> pid;
            cin.ignore();

            for (int i = 0; i < filaProcessos->size(); i++) {
                Processo *tempProcesso = filaProcessos->pop();
                if (tempProcesso->getPid() == pid && !executado) {
                    filaProcessos->pop()->execute();
                    executado = true;
                } else {
                    filaProcessos->push(filaProcessos->pop());
                }
            }

            if (!executado) {
                cout << "Processo com pid " << pid << " nao foi encontrado" << endl;
            }

            break;
        }
        case 4: {
            ofstream arquivo("fila.txt");

            if (!arquivo) {
                cout << "Erro ao abrir o arquivo." << endl;
                break;
            }

            Processo *tempProcesso;

            for (int i = 0; i < filaProcessos->size(); i++) {
                tempProcesso = filaProcessos->front();

                if (ComputingProcess* computingProcess = dynamic_cast<ComputingProcess*>(tempProcesso)) {
                    arquivo << computingProcess->getOperando1() << computingProcess->getOperador() << computingProcess->getOperando2() << '|' << COMPUTING_PROCESS << '|' << '\n';
                } else if (PrintingProcess* printingProcess = dynamic_cast<PrintingProcess*>(tempProcesso)) {
                    arquivo << ' ' << '|' << PRINTING_PROCESS << '|' << '\n';
                } else if (ReadingProcess* readingProcess = dynamic_cast<ReadingProcess*>(tempProcesso)) {
                    arquivo << ' ' << '|' << READING_PROCESS << '|' << '\n';
                } else if (WritingProcess* writingProcess = dynamic_cast<WritingProcess*>(tempProcesso)) {
                    arquivo << ' ' << '|' << WRITING_PROCESS << '|' << '\n';
                }

                filaProcessos->push(filaProcessos->pop());
            }
            break;
        }
        case 5: {
            ifstream arquivo("fila.txt");
            string linha;

            if (!arquivo) {
                cout << "Erro ao abrir o arquivo." << endl;
                break;
            }
            
            int id = 1;
            while (getline(arquivo, linha)) {
                if (!linha.empty()) {
                    int tipoProcesso;
                    string  expressao;

                    expressao = linha.substr(0, linha.find('|'));
                    tipoProcesso = stoi(linha.substr(linha.find('|')+1));

                    Processo* processo = nullptr;
                    switch (tipoProcesso) {
                    case COMPUTING_PROCESS:
                        processo = new ComputingProcess(expressao, id);
                        break;
                    case PRINTING_PROCESS:
                        processo = new PrintingProcess(*filaProcessos, id); 
                        break;
                    case READING_PROCESS:
                        processo = new ReadingProcess(*filaProcessos, id);
                        break;
                    case WRITING_PROCESS:
                        processo = new WritingProcess(expressao, id);
                    default:
                        break;
                    }

                    filaProcessos->push(processo);
                }
            }

            arquivo.close();
            break;
        }
        case 6: {
            rodando = false;
            break;
        }
        case 7: {
            if (filaProcessos->size() == 0) {
                cout << "A fila esta vazia, nao ha o que imprimir" << endl;
                break;
            }
        
            for (int i = 0; i < filaProcessos->size(); i++) {
                Processo *processo = filaProcessos->front();
                processo->imprime();
                filaProcessos->push(filaProcessos->pop());
            }

            break;
        }

        default:
            break;
        }
        cin.ignore();
    }
}

bool Gerenciador::criarProcesso(TIPO_PROCESSO tipo_processo) {
    int id = maiorPid();
    
    cout << "O PID DO PROCESSO NOVO E " << id << endl;
    Processo* processo = nullptr;
    try {
        switch (tipo_processo) {
        case COMPUTING_PROCESS: {
            string expressao;
            cout << "Insira a expressao a ser computada: ";
            cin >> expressao;
            cin.ignore();
            
            processo = new ComputingProcess(expressao, id);
            break;
        }
        case PRINTING_PROCESS:
            processo = new PrintingProcess(*filaProcessos, id); 
            break;
        case READING_PROCESS:
            processo = new ReadingProcess(*filaProcessos, id);
            break;
        case WRITING_PROCESS: {
            string expressao;
            cout << "Insira a expressao a ser escrita: ";
            cin >> expressao;
            cin.ignore();
    
            processo = new WritingProcess(expressao, id);
            break;
        }
        default:
            return false;
        }
        
        if (processo) {
            cout << "PUSH PROCESSOOOO" << endl;
            filaProcessos->push(processo);
            return true;
        }
    } catch (const exception& e) {
        return false;
    }
    
    return false;
}
 
int Gerenciador::maiorPid() {
    if (filaProcessos->size() == 0) {
        return 0;
    }

    Processo* item = filaProcessos->front();
    for (int i = 0; i < filaProcessos->size(); i++) {
        if (filaProcessos->front()->getPid() > item->getPid()) {
            item = filaProcessos->front();
        }
        filaProcessos->push(filaProcessos->pop());
    }

    return item->getPid() + 1;
}