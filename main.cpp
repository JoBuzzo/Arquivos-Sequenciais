#include <iostream>
#include <ctime>
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
void lerPessoa(Pessoa p[], int &index, int quantidade);
void lerEditora(Editora e[], int &index, int quantidade);
void lerAutor(Autor a[], int &index, int quantidade);
void lerGenero(Genero g[], int &index, int quantidade);
void lerLivro(Livro l[], int &indexLivro, int quantidade, Pessoa p[], int indexPessoa, Autor a[], int indexAutor, Editora e[], int indexEditora, Genero g[], int indexGenero);

/*
 * Funções de inclusão
 */
void incluirPessoa(Pessoa p[], int &index, int quantidade);
void incluirLivro(Livro l[], int &index, int quantidade, Pessoa p[], int indexPessoa, Autor au[], int indexAutor, Editora e[], int indexEditora, Genero g[], int indexGenero);

/*
 * Funções de impressão
 */
void imprimirPessoa(Pessoa p[], int index, int quantidade);
void imprimirLivro(Livro l[], int index, int quantidade);

/*
 * Funções de busca
 */
bool buscarPessoa(Pessoa p[], int id, int index);
bool buscarAutor(Autor a[], int id, int index);
bool buscarEditora(Editora e[], int id, int index);
bool buscarGenero(Genero g[], int id, int index);
bool buscarLivro(Livro l[], int id, int indexLivro, Autor a[], int indexAutor, Editora e[], int indexEditora, int &emprestado);

void emprestarLivro(Livro l[], int indexLivro, Autor a[], int indexAutor, Editora e[], int indexEditora, Pessoa p[], int indexPessoa);


/*
 * Funções de Data
*/
void dataAtual(Data &data)
{
    time_t timer;
    struct tm *horarioLocal;

    time(&timer);
    horarioLocal = localtime(&timer);

    data.dia = horarioLocal->tm_mday;
    data.mes = horarioLocal->tm_mon + 1;
    data.ano = horarioLocal->tm_year + 1900;

}
void imprimirData(Data data)
{

    if (data.dia < 10)
    {
        cout << 0 << data.dia << "/";
    }
    else
    {
        cout << data.dia << "/";
    }
    if (data.mes < 10)
    {
        cout << 0 << data.mes << "/";
    }
    else
    {
        cout << data.mes << "/";
    }
    cout << data.ano << endl;
}
bool anoBissexto(int ano) 
{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}
void lerData(Data& data) {
    bool dataValida = false;

    while (!dataValida) {
        cout << "\nInforme o dia: ";
        cin >> data.dia;
        cout << "Informe o mes: ";
        cin >> data.mes;
        cout << "Informe o ano: ";
        cin >> data.ano;

        // Verifica se a data é válida
        if (data.mes >= 1 && data.mes <= 12 && data.dia >= 1) {
            int diasNoMes;

            if (data.mes == 2) {
                if (anoBissexto(data.ano))
                    diasNoMes = 29;
                else
                    diasNoMes = 28;
            } else if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
                diasNoMes = 30;
            } else {
                diasNoMes = 31;
            }

            if (data.dia <= diasNoMes)
                dataValida = true;
        }

        if (!dataValida) {
            cout << "Data invalida. Por favor, insira novamente.\n";
        }
    }
}
void dataDisponivel(Data data, Data& dataDisponivel)
{
    dataDisponivel.dia = data.dia + 5;
    dataDisponivel.mes = data.mes;
    dataDisponivel.ano = data.ano;

    int diasNoMes;

    if (dataDisponivel.mes == 2) {
        if (anoBissexto(dataDisponivel.ano))
            diasNoMes = 29;
        else
            diasNoMes = 28;
    } else if (dataDisponivel.mes == 4 || dataDisponivel.mes == 6 || dataDisponivel.mes == 9 || dataDisponivel.mes == 11) {
        diasNoMes = 30;
    } else {
        diasNoMes = 31;
    }

    if (dataDisponivel.dia > diasNoMes) {
        dataDisponivel.dia -= diasNoMes;
        dataDisponivel.mes++;
    }

    if (dataDisponivel.mes > 12) {
        dataDisponivel.mes = 1;
        dataDisponivel.ano++;
    }
}


int main()
{

    const int QUANTIDADE = 1000;

    Pessoa pessoas[QUANTIDADE];
    int indexPessoas = 0;

    Editora editoras[QUANTIDADE];
    int indexEditoras = 0;

    Autor autores[QUANTIDADE];
    int indexAutores = 0;

    Genero generos[QUANTIDADE];
    int indexGeneros = 0;

    Livro livros[QUANTIDADE];
    int indexLivros = 0;

    char op = 'x';
    while (op != '0')
    {
        system("cls");

        cout << "Menu de opcoes\n\n";
        cout << "[0] - [Sair]\n";
        cout << "[a] - [Adicionar Pessoas]\n";
        cout << "[b] - [Adicionar Editoras]\n";
        cout << "[c] - [Adicionar Autores]\n";
        cout << "[d] - [Adicionar Generos]\n";
        cout << "[e] - [Adicionar Livros]\n";
        cout << "[f] - [Incluir Pessoas]\n";
        cout << "[g] - [Incluir Livros]\n";
        cout << "[h] - [imprimir Pessoas]\n";
        cout << "[i] - [imprimir Livros]\n";
        cout << "[j] - [Emprestar Livros]\n";

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
        case 'a':
        {
            lerPessoa(pessoas, indexPessoas, QUANTIDADE);
            break;
        }
        case 'b':
        {
            lerEditora(editoras, indexEditoras, QUANTIDADE);
            break;
        }
        case 'c':
        {
            lerAutor(autores, indexAutores, QUANTIDADE);
            break;
        }
        case 'd':
        {
            lerGenero(generos, indexGeneros, QUANTIDADE);
            break;
        }
        case 'e':
        {
            lerLivro(livros, indexLivros, QUANTIDADE, pessoas, indexPessoas, autores, indexAutores, editoras, indexEditoras, generos, indexGeneros);
            break;
        }
        case 'f':
        {
            incluirPessoa(pessoas, indexPessoas, QUANTIDADE);
            break;
        }
        case 'g':
        {

            incluirLivro(livros, indexLivros, QUANTIDADE, pessoas, indexPessoas, autores, indexAutores, editoras, indexEditoras, generos, indexGeneros);
            break;
        }
        case 'h':
        {
            imprimirPessoa(pessoas, indexPessoas, QUANTIDADE);
            break;
        }
        case 'i':
        {
            imprimirLivro(livros, indexLivros, QUANTIDADE);
            break;
        }
        case 'j':
        {
            emprestarLivro(livros, indexLivros, autores, indexAutores, editoras, indexEditoras, pessoas, indexPessoas);
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
    int i = index;
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
    int i = index;
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
    int i = index;
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
    int i = index;
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

void lerLivro(Livro l[], int &indexLivro, int quantidade, Pessoa p[], int indexPessoa, Autor a[], int indexAutor, Editora e[], int indexEditora, Genero g[], int indexGenero)
{
    cout << "Inserindo Livros\n";
    int i = indexLivro;
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

            lerData(l[i].data_ultimo_emprestimo);
            imprimirData(l[i].data_ultimo_emprestimo);

            cout << "Id Pessoa emprestado: ";
            cin >> id;
            while (!buscarPessoa(p, id, indexPessoa) && id != 0)
            {
                cout << "Id Pessoa emprestado: ";
                cin >> id;
            }
            l[i].id_pessoa_emprestado = id;

            cout << "Id Autor: ";
            cin >> id;
            while (!buscarAutor(a, id, indexAutor))
            {
                cout << "Id Autor: ";
                cin >> id;
            }
            l[i].id_autor = id;

            cout << "Id Editora: ";
            cin >> id;
            while (!buscarEditora(e, id, indexEditora))
            {
                cout << "Id Editora: ";
                cin >> id;
            }
            l[i].id_editora = id;

            cout << "Id Genero: ";
            cin >> id;
            while (!buscarGenero(g, id, indexGenero))
            {
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

void incluirPessoa(Pessoa p[], int &index, int quantidade)
{
    Pessoa pNova[quantidade];
    int indexNova = 0;
    lerPessoa(pNova, indexNova, quantidade);

    Pessoa a[quantidade];

    int i = 0, j = 0, k = 0;
    for (; i < index && j < indexNova; k++)
    {
        if (p[i].id < pNova[j].id)
        {
            a[k].id = p[i].id;
            strcpy(a[k].nome, p[i].nome);
            strcpy(a[k].endereco, p[i].endereco);
            i++;
        }
        else
        {
            a[k].id = pNova[j].id;
            strcpy(a[k].nome, pNova[j].nome);
            strcpy(a[k].endereco, pNova[j].endereco);
            j++;
        }
    }

    while (i < index)
    {
        a[k].id = p[i].id;
        strcpy(a[k].nome, p[i].nome);
        strcpy(a[k].endereco, p[i].endereco);

        i++;
        k++;
    }

    while (j < indexNova)
    {
        a[k].id = pNova[j].id;
        strcpy(a[k].nome, pNova[j].nome);
        strcpy(a[k].endereco, pNova[j].endereco);

        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        p[i].id = a[i].id;
        strcpy(p[i].nome, a[i].nome);
        strcpy(p[i].endereco, a[i].endereco);
    }
    index = k;
}

void incluirLivro(Livro l[], int &index, int quantidade, Pessoa p[], int indexPessoa, Autor au[], int indexAutor, Editora e[], int indexEditora, Genero g[], int indexGenero)
{
    Livro lNova[quantidade];
    int indexNova = 0;
    lerLivro(lNova, indexNova, quantidade, p, indexPessoa, au, indexAutor, e, indexEditora, g, indexGenero);

    Livro a[quantidade];

    int i = 0, j = 0, k = 0;
    for (; i < index && j < indexNova; k++)
    {
        if (l[i].id < lNova[j].id)
        {
            a[k].id = l[i].id;
            strcpy(a[k].nome, l[i].nome);
            a[k].id_editora = l[k].id_editora;
            a[k].id_autor = l[k].id_autor;
            a[k].id_genero = l[k].id_genero;
            a[k].quantidade_emprestada = l[k].quantidade_emprestada;
            a[k].id_pessoa_emprestado = l[k].id_pessoa_emprestado;
            a[k].data_ultimo_emprestimo.dia = l[k].data_ultimo_emprestimo.dia;
            a[k].data_ultimo_emprestimo.mes = l[k].data_ultimo_emprestimo.mes;
            a[k].data_ultimo_emprestimo.ano = l[k].data_ultimo_emprestimo.ano;
            i++;
        }
        else
        {
            a[k].id = lNova[j].id;
            strcpy(a[k].nome, lNova[j].nome);
            a[k].id_editora = lNova[j].id_editora;
            a[k].id_autor = lNova[j].id_autor;
            a[k].id_genero = lNova[j].id_genero;
            a[k].quantidade_emprestada = lNova[j].quantidade_emprestada;
            a[k].id_pessoa_emprestado = lNova[j].id_pessoa_emprestado;
            a[k].data_ultimo_emprestimo.dia = lNova[j].data_ultimo_emprestimo.dia;
            a[k].data_ultimo_emprestimo.mes = lNova[j].data_ultimo_emprestimo.mes;
            a[k].data_ultimo_emprestimo.ano = lNova[j].data_ultimo_emprestimo.ano;
            j++;
        }
    }

    while (i < index)
    {
        a[k].id = l[i].id;
        strcpy(a[k].nome, l[i].nome);
        a[k].id_editora = l[k].id_editora;
        a[k].id_autor = l[k].id_autor;
        a[k].id_genero = l[k].id_genero;
        a[k].quantidade_emprestada = l[k].quantidade_emprestada;
        a[k].id_pessoa_emprestado = l[k].id_pessoa_emprestado;
        a[k].data_ultimo_emprestimo.dia = l[k].data_ultimo_emprestimo.dia;
        a[k].data_ultimo_emprestimo.mes = l[k].data_ultimo_emprestimo.mes;
        a[k].data_ultimo_emprestimo.ano = l[k].data_ultimo_emprestimo.ano;

        i++;
        k++;
    }

    while (j < indexNova)
    {
        a[k].id = lNova[j].id;
        strcpy(a[k].nome, lNova[j].nome);
        a[k].id_editora = lNova[j].id_editora;
        a[k].id_autor = lNova[j].id_autor;
        a[k].id_genero = lNova[j].id_genero;
        a[k].quantidade_emprestada = lNova[j].quantidade_emprestada;
        a[k].id_pessoa_emprestado = lNova[j].id_pessoa_emprestado;
        a[k].data_ultimo_emprestimo.dia = lNova[j].data_ultimo_emprestimo.dia;
        a[k].data_ultimo_emprestimo.mes = lNova[j].data_ultimo_emprestimo.mes;
        a[k].data_ultimo_emprestimo.ano = lNova[j].data_ultimo_emprestimo.ano;

        j++;
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        l[i].id = a[i].id;
        strcpy(l[i].nome, a[i].nome);
        l[i].id_editora = a[i].id_editora;
        l[i].id_autor = a[i].id_autor;
        l[i].id_genero = a[i].id_genero;
        l[i].quantidade_emprestada = a[i].quantidade_emprestada;
        l[i].id_pessoa_emprestado = a[i].id_pessoa_emprestado;
        l[i].data_ultimo_emprestimo.dia = a[i].data_ultimo_emprestimo.dia;
        l[i].data_ultimo_emprestimo.mes = a[i].data_ultimo_emprestimo.mes;
        l[i].data_ultimo_emprestimo.ano = a[i].data_ultimo_emprestimo.ano;
    }
    index = k;
}

void imprimirPessoa(Pessoa p[], int index, int quantidade)
{
    for (int i = 0; i < index && i < quantidade; i++)
    {
        cout << p[i].id << " " << p[i].nome << " - " << p[i].endereco << endl;
    }
}

void imprimirLivro(Livro l[], int index, int quantidade)
{
    for (int i = 0; i < index && i < quantidade; i++)
    {
        cout << "Id: " << l[i].id << endl
             << endl;
        cout << "Nome: " << l[i].nome << endl;
        cout << "Qauntidade de vezes emprestado: " << l[i].quantidade_emprestada << endl;
        imprimirData(l[i].data_ultimo_emprestimo);
    }
}

bool buscarPessoa(Pessoa p[], int id, int index)
{
    if (id == 0)
    {
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (; p[m].id != id && i <= f; m = (i + f) / 2)
    {

        if (p[m].id > id)
        {
            f = m - 1;
        }

        else
        {
            i = m + 1;
        }
    }

    if (id == p[m].id)
    {
        cout << p[m].id << " " << p[m].nome << " - " << p[m].endereco << endl;
        return true;
    }
    else
    {
        cout << "Pessoa nao encontrada" << endl;
        return false;
    }
}

bool buscarAutor(Autor a[], int id, int index)
{
    if (id == 0)
    {
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (; a[m].id != id && i <= f; m = (i + f) / 2)
    {

        if (a[m].id > id)
        {
            f = m - 1;
        }

        else
        {
            i = m + 1;
        }
    }

    if (id == a[m].id)
    {
        cout << a[m].id << " " << a[m].nome << endl;
        return true;
    }
    else
    {
        cout << "Autor nao encontrada" << endl;
        return false;
    }
}

bool buscarEditora(Editora e[], int id, int index)
{
    if (id == 0)
    {
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (; e[m].id != id && i <= f; m = (i + f) / 2)
    {

        if (e[m].id > id)
        {
            f = m - 1;
        }

        else
        {
            i = m + 1;
        }
    }

    if (id == e[m].id)
    {
        cout << e[m].id << " " << e[m].nome << endl;
        return true;
    }
    else
    {
        cout << "Editora nao encontrada" << endl;
        return false;
    }
}

bool buscarGenero(Genero g[], int id, int index)
{
    if (id == 0)
    {
        return false;
    }
    int i = 0, f = index;

    int m = (i + f) / 2;
    for (; g[m].id != id && i <= f; m = (i + f) / 2)
    {

        if (g[m].id > id)
        {
            f = m - 1;
        }

        else
        {
            i = m + 1;
        }
    }

    if (id == g[m].id)
    {
        cout << g[m].id << " " << g[m].descricao << endl;
        return true;
    }
    else
    {
        cout << "Genero nao encontrada" << endl;
        return false;
    }
}

bool buscarLivro(Livro l[], int id, int indexLivro, Autor a[], int indexAutor, Editora e[], int indexEditora, int &index)
{
    if (id == 0)
    {
        return false;
    }
    int i = 0, f = indexLivro;

    int m = (i + f) / 2;
    for (; l[m].id != id && i <= f; m = (i + f) / 2)
    {

        if (l[m].id > id)
        {
            f = m - 1;
        }

        else
        {
            i = m + 1;
        }
    }
    if (id == l[m].id)
    {
        index = m;
        cout << l[m].nome << endl;

        buscarAutor(a, l[m].id_autor, indexAutor);
        buscarEditora(e, l[m].id_editora, indexEditora);
        return true;
    }
    else
    {
        index = -1;
        cout << "livro nao encontrado" << endl;
        return false;
    }
}

void emprestarLivro(Livro l[], int indexLivro, Autor a[], int indexAutor, Editora e[], int indexEditora, Pessoa p[], int indexPessoa)
{
    int id;
    cout << "Informe o id de um livro: ";
    cin >> id;
    int index;
    buscarLivro(l, id, indexLivro, a, indexAutor, e, indexEditora, index);

    if (index != -1)
    {

        if (l[index].id_pessoa_emprestado > 0)
        {
            cout << "Livro ja emprestado" << endl;
            Data disponivel;

            dataDisponivel(l[index].data_ultimo_emprestimo, disponivel);
            cout << "A data ficara disponivel: " ; imprimirData(disponivel); 
        }
        else
        {
            cout << "Informe o id da Pessoa que deseja emprestar o livro: ";
            cin >> id;

            if (buscarPessoa(p, id, indexPessoa))
            {
                l[index].id_pessoa_emprestado = id;
                l[index].quantidade_emprestada++;
                dataAtual(l[index].data_ultimo_emprestimo);

                cout << "Livro emprestado com sucesso" << endl;         
            }else{
                cout << "Pessoa nao encontrada" << endl;
            }
        }
    }
}
