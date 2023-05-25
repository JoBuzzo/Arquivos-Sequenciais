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
void lerLivro(Livro l[], int &indexLivro, int quantidade, Pessoa p[], int indexPessoa, Autor a[], int indexAutor, Editora e[], int indexEditora,  Genero g[], int indexGenero);


/*
 * Funções de inclusão
 */
void incluirPessoa(Pessoa p[], int &index, int quantidade);


/*
 * Funções de impressão
 */
void imprimirPessoa(Pessoa p[], int index, int quantidade);


/*
 * Funções de busca
 */

bool buscarPessoa(Pessoa p[], int id, int index);
bool buscarAutor(Autor a[], int id, int index);
bool buscarEditora(Editora e[], int id, int index);
bool buscarGenero(Genero g[], int id, int index);

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
    int indexPessoas = 0;
    
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
        cout << "[7] - [imprimir Pessoas]\n";

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
            lerLivro(livros, indexLivros, QUANTIDADE, pessoas, indexPessoas, autores, indexAutores, editoras, indexEditoras, generos, indexGeneros);
            break;
        }
        case '6':
        {
            incluirPessoa(pessoas, indexPessoas, QUANTIDADE);
            break;
        }
        case '7':
        {
            imprimirPessoa(pessoas, indexPessoas, QUANTIDADE);
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

void lerLivro(Livro l[], int &indexLivro, int quantidade, Pessoa p[], int indexPessoa, Autor a[], int indexAutor, Editora e[], int indexEditora,  Genero g[], int indexGenero)
{
    cout << "Inserindo Livros\n";
    int i = 0;
    int id;
    for (int saida = 1; i < quantidade && saida != 0; i++)
    {
        cout << "\n\nId: ";
        cin >> l[i].id;
        fflush(stdin);

        if (l[i].id > 0)
        {

            cout << "Nome: ";
            gets(l[i].nome);

            cout << "Quantidade emprestado: ";
            cin >> l[i].quantidade_emprestada;

            lerData(l[i].data_ultimo_emprestimo.dia, l[i].data_ultimo_emprestimo.mes, l[i].data_ultimo_emprestimo.ano);
            imprimirData(l[i].data_ultimo_emprestimo.dia, l[i].data_ultimo_emprestimo.mes, l[i].data_ultimo_emprestimo.ano);

            cout << "Id Pessoa emprestado: ";
            cin >> id;
            while(!buscarPessoa(p, id, indexPessoa) && id != 0){
                cout << "Id Pessoa emprestado: ";
                cin >> id; 
            }
            l[i].id_pessoa_emprestado = id;

            cout << "Id Autor: ";
            cin >> id;
            while(!buscarAutor(a, id, indexAutor)){
                cout << "Id Autor: ";
                cin >> id;
            }
            l[i].id_autor = id;

            cout << "Id Editora: ";
            cin >> id;
            while(!buscarEditora(e, id, indexEditora)){
                cout << "Id Editora: ";
                cin >> id;
            }
            l[i].id_editora = id;

            cout << "Id Genero: ";
            cin >> id;
            while(!buscarGenero(g, id, indexGenero)){
                cout << "Id Genero: ";
                cin >> id;
            }
            l[i].id_genero = id;

        }
        else
            saida = 0;

    }
    indexLivro = i - 1;

}

void incluirPessoa(Pessoa p[], int & index, int quantidade)
{
    Pessoa pNova[quantidade];
    int indexNova;
    lerPessoa(pNova, indexNova, quantidade);


    Pessoa a[quantidade];

    int i = 0, j = 0, k = 0;
    for (; i < index && j < indexNova; k++){
        if(p[i].id < pNova[j].id){
            a[k].id = p[i].id;
            strcpy(a[k].nome, p[i].nome);
            strcpy(a[k].endereco, p[i].endereco);
            i++;
        }else{
            a[k].id = pNova[j].id;
            strcpy(a[k].nome, pNova[j].nome);
            strcpy(a[k].endereco, pNova[j].endereco);
            j++;
        }
    }

    while (i < index){
        a[k].id = p[i].id;
        strcpy(a[k].nome, p[i].nome);
        strcpy(a[k].endereco, p[i].endereco);

        i++;
        k++;
    }

    while(j < indexNova){
        a[k].id = pNova[j].id;
        strcpy(a[k].nome, pNova[j].nome);
        strcpy(a[k].endereco, pNova[j].endereco);

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

void imprimirPessoa(Pessoa p[], int index ,int quantidade)
{
    for (int i = 0; i < index && i < quantidade; i++)
    {
        cout << p[i].id << " " << p[i].nome << " - " << p[i].endereco <<endl;
    }
    
}

bool buscarPessoa(Pessoa p[], int id, int index)
{
    if(id == 0){
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (;p[m].id != id && i <= f; m = (i + f) / 2){
        
        if (p[m].id > id){
            f = m - 1;
        }

        else{
            i = m + 1;
        }

    }

    if(id == p[m].id){
        cout << p[m].id << " " << p[m].nome << " - " << p[m].endereco <<endl;
        return true;
    }else{
        cout << "Pessoa nao encontrada" << endl;
        return false;
    }
}

bool buscarAutor(Autor a[], int id, int index)
{
    if(id == 0){
        return false;
    }
   int i = 0, f = index;

    int m = (i + f) / 2;
    for (;a[m].id != id && i <= f; m = (i + f) / 2){
        
        if (a[m].id > id){
            f = m - 1;
        }

        else{
            i = m + 1;
        }

    }

    if(id == a[m].id){
        cout << a[m].id << " " << a[m].nome << endl;
        return true;
    }else{
        cout << "Autor nao encontrada" << endl;
        return false;
    }
}

bool buscarEditora(Editora e[], int id, int index)
{
    if(id == 0){
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (;e[m].id != id && i <= f; m = (i + f) / 2){
        
        if (e[m].id > id){
            f = m - 1;
        }

        else{
            i = m + 1;
        }

    }

    if(id == e[m].id){
        cout << e[m].id << " " << e[m].nome << endl;
        return true;
    }else{
        cout << "Editora nao encontrada" << endl;
        return false;
    }
}

bool buscarGenero(Genero g[], int id, int index)
{
    if(id == 0){
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (;g[m].id != id && i <= f; m = (i + f) / 2){
        
        if (g[m].id > id){
            f = m - 1;
        }

        else{
            i = m + 1;
        }

    }

    if(id == g[m].id){
        cout << g[m].id << " " << g[m].descricao  << endl;
        return true;
    }else{
        cout << "Genero nao encontrada" << endl;
        return false;
    }
}
