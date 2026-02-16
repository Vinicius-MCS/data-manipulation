#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

struct linguagemDeProgramacao{
    int id;
    string nome;
    string criador;
    int anoLancamento;
    string paradigma;
};

bool modificacoesPendentes = false;

void menu (){
    cout<<"\n===================================================\n";
    cout<<"1. Cadastrar uma linguagem de programação\n";
    cout<<"2. Excluir uma linguagem de programação\n";
    cout<<"3. Ler o arquivo de linguagens de programação\n";
    cout<<"4. Imprimir lista de linguagens\n";
    cout<<"5. Imprimir trecho do arquivo\n";
    cout<<"6. Pesquisar por nome da linguagem\n";
    cout<<"7. Pesquisar por nome do criador\n";
    cout<<"8. Salvar alterações em arquivo\n";
    cout<<"9. Sair\n";
    cout<<"Escolha uma opcao: ";
}

void imprime (linguagemDeProgramacao linguagens[], int quantidade){
    cout << "\n================================================================================================================\n";
    cout << "| ID | NOME DA LINGUAGEM             | CRIADOR                      | ANO | PARADIGMA                     |\n";
    cout << "================================================================================================================\n";

    for (int i = 0; i < quantidade; i++){
        cout << "| " << left << setw(3) << linguagens[i].id << " | ";
        cout << left << setw(30) << linguagens[i].nome.substr(0, 28) << " | ";
        cout << left << setw(28) << linguagens[i].criador.substr(0, 26) << " | ";
        cout << left << setw(4) << linguagens[i].anoLancamento << " | ";
        cout << left << setw(28) << linguagens[i].paradigma.substr(0, 26) << " |\n";
    }

    cout << "================================================================================================================\n";
    cout << "Total de linguagens: " << quantidade << endl;
}

void procurarPorNomeLinguagem(linguagemDeProgramacao linguagens[], string nomeLinguagemParaProcura, int quantidade){
    bool encontrou = false;

    cout << "\nResultado da busca por linguagem \"" << nomeLinguagemParaProcura << "\":\n";
    cout << "================================================================================================================\n";
    cout << "| ID | NOME DA LINGUAGEM             | CRIADOR                      | ANO | PARADIGMA                     |\n";
    cout << "================================================================================================================\n";

    for(int i = 0; i < quantidade; i++){
        if(linguagens[i].nome == nomeLinguagemParaProcura){
            cout << "| " << left << setw(3) << linguagens[i].id << " | ";
            cout << left << setw(30) << linguagens[i].nome.substr(0, 28) << " | ";
            cout << left << setw(28) << linguagens[i].criador.substr(0, 26) << " | ";
            cout << left << setw(4) << linguagens[i].anoLancamento << " | ";
            cout << left << setw(28) << linguagens[i].paradigma.substr(0, 26) << " |\n";
            encontrou = true;
        }
    }

    if(!encontrou){
        cout << "Nenhuma linguagem encontrada com o nome \"" << nomeLinguagemParaProcura << "\"\n";
    } else {
        cout << "================================================================================================================\n";
    }
}

void procurarPorNomeCriador(linguagemDeProgramacao linguagens[], string nomeCriadorParaProcura, int quantidade){
    bool encontrou = false;

    cout << "\nResultado da busca por criador \"" << nomeCriadorParaProcura << "\":\n";
    cout << "================================================================================================================\n";
    cout << "| ID | NOME DA LINGUAGEM             | CRIADOR                      | ANO | PARADIGMA                     |\n";
    cout << "================================================================================================================\n";

    for(int i = 0; i < quantidade; i++){
        if(linguagens[i].criador == nomeCriadorParaProcura){
            cout << "| " << left << setw(3) << linguagens[i].id << " | ";
            cout << left << setw(30) << linguagens[i].nome.substr(0, 28) << " | ";
            cout << left << setw(28) << linguagens[i].criador.substr(0, 26) << " | ";
            cout << left << setw(4) << linguagens[i].anoLancamento << " | ";
            cout << left << setw(28) << linguagens[i].paradigma.substr(0, 26) << " |\n";
            encontrou = true;
        }
    }

    if(!encontrou){
        cout << "Nenhuma linguagem encontrada com o criador \"" << nomeCriadorParaProcura << "\"\n";
    } else {
        cout << "================================================================================================================\n";
    }
}

linguagemDeProgramacao* realocarMemoria(linguagemDeProgramacao* vetorAntigo, int& tamanhoAtual) {
    const int POSICOES_ADICIONAR = 5;
    int novoTamanho = tamanhoAtual + POSICOES_ADICIONAR;
    linguagemDeProgramacao* novoVetor = new linguagemDeProgramacao[novoTamanho];

    for(int i = 0; i < tamanhoAtual; i++) {
        novoVetor[i] = vetorAntigo[i];
    }

    delete[] vetorAntigo;
    tamanhoAtual = novoTamanho;

    cout << "Memória realocada! Novo tamanho: " << novoTamanho
         << " (foram adicionadas " << POSICOES_ADICIONAR << " posições)" << endl;

    return novoVetor;
}

void salvarEmArquivo(linguagemDeProgramacao linguagens[], int quantidade) {
    ofstream arquivo("linguagens.txt");

    if(!arquivo) {
        cout << "Erro ao abrir arquivo para salvar!\n";
        return;
    }

    for(int i = 0; i < quantidade; i++) {
        arquivo << linguagens[i].id << ","
                << linguagens[i].nome << ","
                << linguagens[i].criador << ","
                << linguagens[i].anoLancamento << ","
                << linguagens[i].paradigma << endl;
    }

    arquivo.close();
    modificacoesPendentes = false;
    cout << "Dados salvos com sucesso em 'linguagens.txt'!\n";
}

void removerLinguagem(linguagemDeProgramacao linguagens[], int& quantidade) {
    if(quantidade == 0) {
        cout << "Não há linguagens cadastradas para remover.\n";
        return;
    }

    cout << "\n--- Remoção de Linguagem ---\n";
    cout << "Digite o ID da linguagem que deseja remover: ";
    int idRemover;
    cin >> idRemover;

    int posicaoRemover = -1;
    for(int i = 0; i < quantidade; i++) {
        if(linguagens[i].id == idRemover) {
            posicaoRemover = i;
            break;
        }
    }

    if(posicaoRemover == -1) {
        cout << "ID não encontrado!\n";
        return;
    }

    cout << "\nLinguagem encontrada:\n";
    cout << "================================================================================================================\n";
    cout << "| ID | NOME DA LINGUAGEM             | CRIADOR                      | ANO | PARADIGMA                     |\n";
    cout << "================================================================================================================\n";
    cout << "| " << left << setw(3) << linguagens[posicaoRemover].id << " | ";
    cout << left << setw(30) << linguagens[posicaoRemover].nome.substr(0, 28) << " | ";
    cout << left << setw(28) << linguagens[posicaoRemover].criador.substr(0, 26) << " | ";
    cout << left << setw(4) << linguagens[posicaoRemover].anoLancamento << " | ";
    cout << left << setw(28) << linguagens[posicaoRemover].paradigma.substr(0, 26) << " |\n";
    cout << "================================================================================================================\n";

    cout << "\nConfirma a remoção? (1-Sim / 0-Não): ";
    int confirmacao;
    cin >> confirmacao;

    if(confirmacao != 1) {
        cout << "Remoção cancelada.\n";
        return;
    }

    for(int i = posicaoRemover; i < quantidade - 1; i++) {
        linguagens[i] = linguagens[i + 1];
    }

    quantidade--;
    modificacoesPendentes = true;

    cout << "Linguagem removida com sucesso!\n";
    cout << "Atenção: As alterações ainda não foram salvas em arquivo.\n";
}

void verificarSalvarAntesSair(linguagemDeProgramacao linguagens[], int quantidade) {
    if(modificacoesPendentes) {
        cout << "\nExistem modificações não salvas!\n";
        cout << "Deseja salvar antes de sair? (1-Sim / 0-Não): ";
        int opcao;
        cin >> opcao;

        if(opcao == 1) {
            salvarEmArquivo(linguagens, quantidade);
        }
    }
    cout << "Encerrando programa...\n";
}

void imprimirTrechoArquivo() {
    ifstream arquivo("linguagens.txt");

    if (!arquivo) {
        cout << "Arquivo 'linguagens.txt' não encontrado.\n";
        return;
    }

    vector<linguagemDeProgramacao> linguagensArquivo;
    linguagemDeProgramacao temp;

    while (arquivo >> temp.id) {
        arquivo.ignore();
        getline(arquivo, temp.nome, ',');
        getline(arquivo, temp.criador, ',');
        arquivo >> temp.anoLancamento;
        arquivo.ignore();
        getline(arquivo, temp.paradigma);
        linguagensArquivo.push_back(temp);
    }

    arquivo.close();

    int totalLinguagens = linguagensArquivo.size();

    if (totalLinguagens == 0) {
        cout << "O arquivo está vazio.\n";
        return;
    }

    cout << "\nTotal de linguagens no arquivo: " << totalLinguagens << endl;

    int inicio, fim;
    cout << "Digite a posição inicial (1 a " << totalLinguagens << "): ";
    cin >> inicio;
    cout << "Digite a posição final (1 a " << totalLinguagens << "): ";
    cin >> fim;

    if (inicio < 1 || fim > totalLinguagens || inicio > fim) {
        cout << "Intervalo inválido! Certifique-se de que:\n";
        cout << "- Posição inicial >= 1\n";
        cout << "- Posição final <= " << totalLinguagens << "\n";
        cout << "- Posição inicial <= Posição final\n";
        return;
    }

    cout << "\n================================================================================================================\n";
    cout << "Trecho do arquivo (posições " << inicio << " a " << fim << "):\n";
    cout << "================================================================================================================\n";
    cout << "| POS | ID  | NOME DA LINGUAGEM              | CRIADOR                      | ANO  | PARADIGMA                     |\n";
    cout << "================================================================================================================\n";

    for (int i = inicio - 1; i <= fim - 1; i++) {
        cout << "| " << left << setw(3) << (i + 1) << " | ";
        cout << left << setw(3) << linguagensArquivo[i].id << " | ";
        cout << left << setw(30) << linguagensArquivo[i].nome.substr(0, 28) << " | ";
        cout << left << setw(28) << linguagensArquivo[i].criador.substr(0, 26) << " | ";
        cout << left << setw(4) << linguagensArquivo[i].anoLancamento << " | ";
        cout << left << setw(28) << linguagensArquivo[i].paradigma.substr(0, 26) << " |\n";
    }

    cout << "================================================================================================================\n";
}

int main(){
    int tamanho = 5;
    int opcao = -1;
    int posicao = 0;

    linguagemDeProgramacao* linguagens = new linguagemDeProgramacao[tamanho];

    cout << "Sistema de Gerenciamento de Linguagens de Programação\n";
    cout << "===================================================\n";
    cout << "Capacidade inicial: " << tamanho << " linguagens\n";

    do {
        menu();
        cin >> opcao;
        cin.ignore();

        switch(opcao) {
            case 1: {
                if(posicao >= tamanho) {
                    linguagens = realocarMemoria(linguagens, tamanho);
                }

                cout << "\n--- Cadastro de Nova Linguagem ---\n";
                cout << "ID: ";
                cin >> linguagens[posicao].id;
                cin.ignore();

                cout << "Nome da linguagem: ";
                getline(cin, linguagens[posicao].nome);

                cout << "Nome do criador: ";
                getline(cin, linguagens[posicao].criador);

                cout << "Ano de lançamento: ";
                cin >> linguagens[posicao].anoLancamento;
                cin.ignore();

                cout << "Paradigma: ";
                getline(cin, linguagens[posicao].paradigma);

                posicao++;
                modificacoesPendentes = true;

                cout << "\nLinguagem cadastrada com sucesso!\n";
                cout << "Total de linguagens: " << posicao << "/" << tamanho << endl;
                cout << "Atenção: As alterações ainda não foram salvas em arquivo.\n";
                break;
            }

            case 2: {
                removerLinguagem(linguagens, posicao);
                break;
            }

            case 3: {
                ifstream entrada("linguagens.txt");
                if (!entrada) {
                    cout << "Arquivo 'linguagens.txt' não encontrado. Nenhuma linguagem carregada.\n";
                } else {
                    posicao = 0;

                    while (entrada >> linguagens[posicao].id) {
                        if(posicao >= tamanho) {
                            linguagens = realocarMemoria(linguagens, tamanho);
                        }

                        entrada.ignore();
                        getline(entrada, linguagens[posicao].nome, ',');
                        getline(entrada, linguagens[posicao].criador, ',');
                        entrada >> linguagens[posicao].anoLancamento;
                        entrada.ignore();
                        getline(entrada, linguagens[posicao].paradigma);

                        posicao++;
                    }
                    entrada.close();
                    cout << "Arquivo carregado com sucesso!\n";
                    cout << "Total de linguagens lidas: " << posicao << endl;
                    modificacoesPendentes = false;
                }
                break;
            }

            case 4: {
                imprime(linguagens, posicao);
                break;
            }

            case 5: {
                imprimirTrechoArquivo();
                break;
            }

            case 6: {
                if(posicao == 0) {
                    cout << "Não há linguagens cadastradas para pesquisar.\n";
                    break;
                }
                string nomeLinguagemParaProcura;
                cout << "Digite o nome da linguagem para procurar: ";
                getline(cin, nomeLinguagemParaProcura);
                procurarPorNomeLinguagem(linguagens, nomeLinguagemParaProcura, posicao);
                break;
            }

            case 7: {
                if(posicao == 0) {
                    cout << "Não há linguagens cadastradas para pesquisar.\n";
                    break;
                }
                string nomeCriadorParaProcura;
                cout << "Digite o nome do criador para procurar: ";
                getline(cin, nomeCriadorParaProcura);
                procurarPorNomeCriador(linguagens, nomeCriadorParaProcura, posicao);
                break;
            }

            case 8: {
                if(posicao == 0) {
                    cout << "Não há linguagens para salvar.\n";
                    break;
                }
                salvarEmArquivo(linguagens, posicao);
                break;
            }

            case 9: {
                verificarSalvarAntesSair(linguagens, posicao);
                break;
            }

            default:
                cout << "Opção inválida! Tente novamente.\n";
        }

    } while (opcao != 9);

    delete[] linguagens;
}
