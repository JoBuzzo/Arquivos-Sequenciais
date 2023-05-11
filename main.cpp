#include <iostream>

#include <string>

using namespace std;

struct Pessoa
{
    int id;
    char nome[30];
    char endereco[60];
};

struct Editora
{
    int id;
    char nome[30];
};

struct Autor
{
    int id;
    char descricao[30];
};

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Livro
{
    int id;
    char nome[30];
    int id_editora;
    int id_autor;
    int id_genero;
    int id_pessoa_emprestado;
    int quantidade_emprestada;
    Data data_ultimo_emprestimo;
};


/*
 * Funções de inserção
 */
void inserirPessoa(Pessoa p[], int &index, int quantidade);
void inserirEditora(Editora e[], int &index, int quantidade);
void inserirAutor(Autor a[], int &index, int quantidade);




int main()
{

    const int QUANTIDADE = 1000;

    Pessoa pessoas[QUANTIDADE]; int indexPessoas;
    Editora editoras[QUANTIDADE]; int indexEditoras;
    Autor autores[QUANTIDADE]; int indexAutores;

    char op = 'x';
    while (op != '0')
    {
        system("cls");

        cout << "Menu de opcoes\n\n";
        cout << "[0] - [Sair]\n";
        cout << "[1] - [Adicionar Pessoas]\n";
        cout << "[2] - [Adicionar Editoras]\n";
        cout << "[3] - [Adicionar Autores]\n";

        fflush(stdin);
        cout << "\n\nInforme a sua escolha: ";
        op = getchar();

        system("cls");
        switch (op)
        {
        case '0':
        {
            cout << "Saindo...";
            break;
        }
        case '1':
        {
            inserirPessoa(pessoas, indexPessoas, QUANTIDADE);
            break;
        }
        case '2':
        {
            inserirEditora(editoras, indexEditoras, QUANTIDADE);
            break;
        }
        case '3':
        {
            inserirAutor(autores, indexAutores, QUANTIDADE);
            break;
        }
        default:
        {
            cout << "Opcao invalida";
            break;
        }
        }
        system("pause");
    }

}

void inserirPessoa(Pessoa p[], int &index, int quantidade)
{

    cout << "Inserindo Pessoas\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: "; cin >> p[i].id;
        fflush(stdin);
        if (p[i].id > 0)
        {
            cout << "Nome: "; gets(p[i].nome);
            cout << "Endereco: "; gets(p[i].endereco);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void inserirEditora(Editora e[], int &index, int quantidade)
{
    cout << "Inserindo Editoras\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: "; cin >> e[i].id;
        fflush(stdin);
        if (e[i].id > 0)
        {
            cout << "Nome: "; gets(e[i].nome);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void inserirAutor(Autor a[], int &index, int quantidade)
{
    cout << "Inserindo Autores\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: "; cin >> a[i].id;
        fflush(stdin);
        if (a[i].id > 0)
        {
            cout << "Descricao: "; gets(a[i].descricao);
        }
        else
            saida = 0;
    }
    index = i - 1;
}
