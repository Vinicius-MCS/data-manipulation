#include <iostream>
#include <fstream>

using namespace std;

struct linguagemDeProgramacao{
    int id;
    string nome;
    string criador;
    int anoLancamento;
    string paradigma;
};

void menu (){
	cout<<"\n===============================\n";
	cout<<"1.Cadastrar uma linguagem de programação\n"; // feito
	cout<<"2. Excluir uma linguagem de programação\n";
	cout<<"3.Ler o arquivo de linguagens de programação\n";  // feito
	cout<<"4.Imprimir lista de linguagens\n";  // feito
	cout<<"5.Pesquisar por nome da linguagem\n";  // feito
	cout<<"6.Pesquisar por nome do criador\n";  // feito
	cout<<"Escolha uma opcao ";
}

void imprime (linguagemDeProgramacao linguagens[], int quantidade){
	cout<<"===============================\n";
	cout<<"ID NOME CRIADOR ANO PARADIGMA \n";
	for (int i=0; i<quantidade; i++){
		cout<<linguagens[i].id<<" ";
		cout<<linguagens[i].nome<<" ";
		cout<<linguagens[i].criador<<" ";
		cout<<linguagens[i].anoLancamento<<" ";
		cout<<linguagens[i].paradigma<<endl;
	}
	cout<<"Total de linguagens "<<quantidade<<endl;
}

void procurarPorNomeLinguagem(linguagemDeProgramacao linguagens[], string nomeLinguagemParaProcura, int quantidade){
    linguagemDeProgramacao linguagemEncontrada;
    linguagemEncontrada.nome = "";
    int i = 0;

    while(i < quantidade){
        if(linguagens[i]. nome == nomeLinguagemParaProcura){
            linguagemEncontrada = linguagens[i];
            i = quantidade;
        }
        i++;
    }

    if(linguagemEncontrada.nome != nomeLinguagemParaProcura){
        cout<<"Linguagem não encontrada";
    } else{
        cout<<linguagemEncontrada.id<<endl;
        cout<<linguagemEncontrada.nome<<endl;
        cout<<linguagemEncontrada.criador<<endl;
        cout<<linguagemEncontrada.anoLancamento<<endl;
        cout<<linguagemEncontrada.paradigma<<endl;
    }
}

void procurarPorNomeCriador(linguagemDeProgramacao linguagens[], string nomeCriadorParaProcura, int quantidade){
    linguagemDeProgramacao linguagemEncontrada;
    linguagemEncontrada.criador = "";
    int i = 0;

    while(i < quantidade){
        if(linguagens[i]. criador == nomeCriadorParaProcura){
            linguagemEncontrada = linguagens[i];
            i = quantidade;
        }
        i++;
    }

    if(linguagemEncontrada.criador != nomeCriadorParaProcura){
        cout<<"Linguagem não encontrada";
    } else{
        cout<<linguagemEncontrada.id<<endl;
        cout<<linguagemEncontrada.nome<<endl;
        cout<<linguagemEncontrada.criador<<endl;
        cout<<linguagemEncontrada.anoLancamento<<endl;
        cout<<linguagemEncontrada.paradigma<<endl;
    }
}


int main(){
    int tamanho=40, opcao=-1;
	int posicao=0; //posicao livre ou total de elementos
	linguagemDeProgramacao linguagens[tamanho];

	do {
		menu();
		cin>>opcao;
		cin.ignore();
		if (opcao==1) {//ler do teclado
			cout<<"Digite o id, nome da linguagem, nome do criador, ano de lançamento e paradigma\n";
			cin>>linguagens[posicao].id;
			cin.ignore();
			getline(cin, linguagens[posicao].nome);
			getline(cin, linguagens[posicao].criador);
			cin>>linguagens[posicao].anoLancamento;
			cin>>linguagens[posicao].paradigma;
			posicao++;

		} else if (opcao==3){//ler do arquivo
			 	//lendo do arquivo
			ifstream entrada ("lista");//nomeDoArquivo
			if (!entrada)
				cout<<"Arquivo não encontrado";
			else {
				char lixo;
				//ler todo o conteúdo do arquivo
				while (posicao<tamanho and entrada>>linguagens[posicao].id) {
					entrada>>lixo;	//lê a vírgula;
					entrada>>linguagens[posicao].id;
					entrada >> lixo;
					getline(entrada,linguagens[posicao].nome, ',');
					getline(entrada,linguagens[posicao].criador, ',');//lê até a virgula, mas a descarta
					entrada >> linguagens[posicao].anoLancamento;
					entrada >> lixo;
					entrada >> linguagens[posicao].paradigma;
					posicao++;
				}//fecha o laço
				cout<<"Fim de leitura\n";
			}//fecha else
		} else if (opcao==4){
			 imprime(linguagens, posicao);
		} else if (opcao == 5) {
			string nomeLinguagemParaProcura;
			cout<<"Digite um nome da linguagem para procurar ";
			getline(cin, nomeLinguagemParaProcura);
			procurarPorNomeLinguagem(linguagens, nomeLinguagemParaProcura, posicao);
		} else if (opcao == 6) {
			string nomeCriadorParaProcura;
			cout<<"Digite um nome do criador para procurar ";
			getline(cin, nomeCriadorParaProcura);
			procurarPorNomeCriador(linguagens, nomeCriadorParaProcura, posicao);
		}

	}while (opcao != -1);

}
