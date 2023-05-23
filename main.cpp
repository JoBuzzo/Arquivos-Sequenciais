#include <iostream>
#include <string.h>

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
    char nome[30];
};

struct Genero
{
    int id;
    char descricao[40];
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
    struct Data
    {
        int dia;
        int mes;
        int ano;
    } data_ultimo_emprestimo;
};



/*
 * Funções de inserção
 */
void lerPessoa(Pessoa p[], int &index, int quantidade);
void lerEditora(Editora e[], int &index, int quantidade);
void lerAutor(Autor a[], int &index, int quantidade);
void lerGenero(Genero g[], int &index, int quantidade);
void lerLivro(Livro l[], int &index, int quantidade);


/*
 * Funções de inclusão
 */
void incluirPessoa(Pessoa p[], int &index, int quantidade);




void lerData(int &dia, int &mes, int &ano){
    cout << "\nInforme o dia: ";
    cin >> dia;
    cout << "Informe o mes: ";
    cin >> mes;
    cout << "Informe o ano: ";
    cin >> ano;
}

void imprimirData(int &dia, int &mes, int &ano)
{

    if(dia < 10){
        cout << 0 << dia << "/";
    }else{
        cout << dia << "/";
    }
    if (mes < 10){
        cout << 0 << mes << "/";
    }else {
        cout << mes << "/";
    }
    cout << ano << endl;
}

int main()
{

    const int QUANTIDADE = 1000;

    Pessoa pessoas[QUANTIDADE];
    int indexPessoas;
    
    Editora editoras[QUANTIDADE];
    int indexEditoras;

    Autor autores[QUANTIDADE];
    int indexAutores;

    Genero generos[QUANTIDADE];
    int indexGeneros;
    
    Livro livros[QUANTIDADE];
    int indexLivros;

    char op = 'x';
    while (op != '0')
    {
        system("cls");

        cout << "Menu de opcoes\n\n";
        cout << "[0] - [Sair]\n";
        cout << "[1] - [Adicionar Pessoas]\n";
        cout << "[2] - [Adicionar Editoras]\n";
        cout << "[3] - [Adicionar Autores]\n";
        cout << "[4] - [Adicionar Generos]\n";
        cout << "[5] - [Adicionar Livros]\n";
        cout << "[6] - [Incluir Pessoas]\n";

        fflush(stdin);
        cout << "\n\nInforme a sua escolha: ";
        op = getchar();

        system("cls");
        switch (op)
        {
        case '0':
        {
            cout << "Saindo...\n";
            break;
        }
        case '1':
        {
            lerPessoa(pessoas, indexPessoas, QUANTIDADE);
            break;
        }
        case '2':
        {
            lerEditora(editoras, indexEditoras, QUANTIDADE);
            break;
        }
        case '3':
        {
            lerAutor(autores, indexAutores, QUANTIDADE);
            break;
        }
        case '4':
        {
            lerGenero(generos, indexGeneros, QUANTIDADE);
            break;
        }
        case '5':
        {
            lerLivro(livros, indexLivros, QUANTIDADE);
            break;
        }
        case '6':
        {
            incluirPessoa(pessoas, indexPessoas, QUANTIDADE);
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

void lerPessoa(Pessoa p[], int &index, int quantidade)
{

    cout << "Inserindo Pessoas\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: ";
        cin >> p[i].id;
        fflush(stdin);
        if (p[i].id > 0)
        {
            cout << "Nome: ";
            gets(p[i].nome);
            cout << "Endereco: ";
            gets(p[i].endereco);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void lerEditora(Editora e[], int &index, int quantidade)
{
    cout << "Inserindo Editoras\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: ";
        cin >> e[i].id;
        fflush(stdin);
        if (e[i].id > 0)
        {
            cout << "Nome: ";
            gets(e[i].nome);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void lerAutor(Autor a[], int &index, int quantidade)
{
    cout << "Inserindo Autores\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: ";
        cin >> a[i].id;
        fflush(stdin);
        if (a[i].id > 0)
        {
            cout << "Nome: ";
            gets(a[i].nome);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void lerGenero(Genero g[], int &index, int quantidade)
{
    cout << "Inserindo Genero\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: ";
        cin >> g[i].id;
        fflush(stdin);
        if (g[i].id > 0)
        {
            cout << "Nome: ";
            gets(g[i].descricao);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void lerLivro(Livro l[], int &index, int quantidade)
{
    cout << "Inserindo Livros\n";
    int i = 0;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: ";
        cin >> l[i].id;
        fflush(stdin);
        if (l[i].id > 0)
        {
            cout << "Nome: ";
            gets(l[i].nome);
            cout << "Id Editora: ";
            cin >> l[i].id_editora;
            cout << "Id Autor: ";
            cin >> l[i].id_autor;
            cout << "Id Genero: ";
            cin >> l[i].id_genero;
            cout << "Id Pessoa emprestado: ";
            cin >> l[i].id_pessoa_emprestado;
            cout << "Quantidade de vezes emprestado: ";
            cin >> l[i].quantidade_emprestada;

            cout << "Data do ultimo emprestimo";
            lerData(l[i].data_ultimo_emprestimo.dia, l[i].data_ultimo_emprestimo.mes, l[i].data_ultimo_emprestimo.ano);
            imprimirData(l[i].data_ultimo_emprestimo.dia, l[i].data_ultimo_emprestimo.mes, l[i].data_ultimo_emprestimo.ano);
        }
        else
            saida = 0;
    }
    index = i - 1;
}

void incluirPessoa(Pessoa p[], int & index, int quantidade)  //testar
{
    Pessoa pNova[quantidade];
    int indexNova;
    lerPessoa(pNova, indexNova, quantidade);


    Pessoa a[quantidade];

    int i = 0, j = 0, k = 0;
    for (; i < index && j < indexNova; k++){
        if(p[i].id < pNova[i].id){
            a[i].id = p[i].id;
            strcpy(a[i].nome, p[i].nome);
            strcpy(a[i].endereco, p[i].endereco);
        }else{
            a[i].id = pNova[i].id;
            strcpy(a[i].nome, pNova[i].nome);
            strcpy(a[i].endereco, pNova[i].endereco);
        }
    }

    while (i < index){
        a[i].id = p[i].id;
        strcpy(a[i].nome, p[i].nome);
        strcpy(a[i].endereco, p[i].endereco);

        i++;
        k++;
    }

    while(j < indexNova){
        a[i].id = pNova[j].id;
        strcpy(a[i].nome, pNova[j].nome);
        strcpy(a[i].endereco, pNova[j].endereco);

        j++;
        k++;
    }
    


    for (int i = 0; i < k; i++){
        p[i].id = a[i].id;
        strcpy(p[i].nome, a[i].nome);
        strcpy(p[i].endereco, a[i].endereco);
    }
    index = k;




}
