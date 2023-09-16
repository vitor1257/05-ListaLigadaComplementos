//Vitor Castro Dias


#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));

	if (novo == NULL)
	{
		return;
	}

	/*while(aux->prox != NULL) { tentativa falha D:(maios ou menos)

		if (aux->valor == novo->valor)
		{
			cout << "Valor duplicado\n";
			return;
		}
		aux = aux->prox;
	}
	aux->prox = novo;*/


	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
	}
	else
	{
		
		NO* aux = primeiro;
		NO * Tanterior = NULL;

		while (aux != NULL && aux->valor < novo->valor)
		{
			Tanterior = aux;
			aux = aux->prox;
		}
		
		if (aux != NULL && aux->valor == novo->valor)
		{
			cout << "Valor duplicado\n";
			free(novo);
			return;
		}	
		
		if (Tanterior == NULL)
		{
			novo->prox = primeiro;
			primeiro = novo;
		}else
		{
			Tanterior->prox = novo;
			novo->prox = aux;
		}
	}
}

void excluirElemento()
{
	NO* aux = NULL;
	NO* delet = primeiro;
	int exclu;

	cout << "Digite o numero que você deseja excluir:";
	cin >> exclu;

	while (delet != NULL) 
	{
		if (delet->valor == exclu)
		{
			if (aux == NULL)
			{
				primeiro = delet->prox;
			}
			else
			{
				aux->prox = delet->prox;
				free(delet);
				cout << "valor deletado\n";
				return;
			}
		}
		aux = delet;
		delet = delet->prox;
	}
	cout << "Valor nao encontrado\n";
}

void buscarElemento()
{
	NO* aux = primeiro;
	bool s;
	int num;

	cout << "Digite o numero que voce deseja buscar:";
	cin >> num;

	while(aux != NULL)
	{
		if(aux->valor == num)
		{
			s = true;
			cout << "Valor encontrado\n";
			return;

		}else if (aux->valor > num)
		{
			s = false;
			cout << "Valor nao encontrado\n";
			return;
		}
		aux = aux->prox;
	}
}


