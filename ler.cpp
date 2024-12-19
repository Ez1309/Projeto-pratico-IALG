#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int tamanhoPlaca = 8;
const int tamanhoFabricante = 14;
const int tamanhoModelo = 9;
const int tamanhoCor = 9;
const int tamanhoCategoria = 16;
const int tamanhoDescricao = 166;
const int tamanhoDisponibilidade = 12;
const int tamanhoLocador = 21;

struct veiculo{
    char *placa = new char[tamanhoPlaca];
    char *fabricante = new char[tamanhoFabricante];
    char *modelo = new char[tamanhoModelo];
    char *cor = new char[tamanhoCor];
    int ano;
    int quilometragem;
    char *categoria = new char[tamanhoCategoria];
    char *descricao = new char [tamanhoDescricao];
    double preco;
    char *disponibilidade = new char[tamanhoDisponibilidade];
    char *locador = new char[tamanhoLocador];
};

bool lerDados(veiculo* &carros, int &linhas);
void imprimirTabela(veiculo carros[], int &linhas);

bool lerDados(veiculo* &carros, int &linhas){

    bool leuComSucesso = true;
    ifstream arquivo("carros.csv");

    if (!arquivo){
        cout << "Não foi possível abrir o arquivo carros.csv!" << endl;
        return (not leuComSucesso);
    }

    string linha;
    getline(arquivo, linha);

    int tamanho = 0;
    linhas = 0;

    
    // Ler os dados até chegar ao fim do arquivo
    while(!arquivo.eof()){

        // Condicional para redimensionar o vetor caso ele tenha mais de 40 elementos
        if (linhas == tamanho){
            int novoTamanho = tamanho + 10;
            veiculo *temp = new veiculo [novoTamanho];
            copy(carros, carros+tamanho, temp);
            delete [] carros;
            carros = temp;
            tamanho = novoTamanho;
        }

        // Leitura da placa, fabricante, modelo e cor
        arquivo.getline(carros[linhas].placa, tamanhoPlaca, ',');
        arquivo.getline(carros[linhas].fabricante, tamanhoFabricante, ',');
        arquivo.getline(carros[linhas].modelo, tamanhoModelo, ',');
        arquivo.getline(carros[linhas].cor, tamanhoCor, ',');

        // Leitura do ano ignorando a vírgula
        arquivo >> carros[linhas].ano;
        arquivo.ignore();

        // Leitura da quilometragem ignorando a vírgula
        arquivo >> carros[linhas].quilometragem;
        arquivo.ignore();

        // Leitura da categoria
        arquivo.getline(carros[linhas].categoria, tamanhoCategoria, ',');

        // Leitura da descrição ignorando as primeiras aspas " e a vírgula
        arquivo.ignore();
        arquivo.getline(carros[linhas].descricao, tamanhoDescricao, '"');
        arquivo.ignore();

        // Leitura do preço ignorando a vírgula
        arquivo >> carros[linhas].preco;
        arquivo.ignore();

        // Leitura da disponibilidade e do locador
        arquivo.getline(carros[linhas].disponibilidade, tamanhoDisponibilidade, ',');
        arquivo.getline(carros[linhas].locador, tamanhoLocador, '\n');
        linhas++;
    }
    ifstream binarioEntrada("carros.dat");
    
    if (not binarioEntrada){
        cout << "Não foi possível abrir o arquivo carros.dat" << endl;
        return (not leuComSucesso);
    }

    // Ler dados do arquivo binário de entrada
    // A FAZER

    // Escrita dos dados no arquivo binário de saída
     ofstream binarioSaida("carros.dat");
     binarioSaida.write((const char *) (carros), sizeof(carros));

    // Fechamento dos arquivos
     binarioSaida.close();
     binarioEntrada.close();
     arquivo.close();
     return leuComSucesso;
}

void imprimirTabela(veiculo carros[], int &tamanho){

    int colBarra = 1;
    int colPlaca = 9;
    int colFabricante = 15;
    int colModelo = 12;
    int colCor = 10;
    int colAno = 6;
    int colQuilometros = 15;
    int colCategoria = 16;
    int colPreco = 14;
    int colDisponibilidade = 17;
    int colLocador = 20;

    // Códigos ANSI para negrito
    const string ativarNegrito = "\033[1m";
    const string desativarNegrito = "\033[0m";


    // Linha superior da tabela
    cout << "╭─────────┬───────────────┬────────────┬──────────┬──────┬───────────────┬────────────────┬──────────────┬─────────────────┬────────────────────╮" << endl;

    // Cabeçalho
    cout << "│"
            << ativarNegrito
            << setw(colPlaca) << left << " PLACA "
            << setw(colBarra) << "│"
            << setw(colFabricante) << left << " FABRICANTE "
            << setw(colBarra) << "│"
            << setw(colModelo) << left << " MODELO "
            << setw(colBarra) << "│"
            << setw(colCor) << left << " COR "
            << setw(colBarra) << "│"
            << setw(colAno) << left << " ANO "
            << setw(colBarra) << "│"
            << setw(colQuilometros) << left << " QUILOMETRAGEM "
            << setw(colBarra) << "│"
            << setw(colCategoria) << left << " CATEGORIA "
            << setw(colBarra) << "│"
            << setw(colPreco) << left << " PREÇO DIÁRIO "
            << setw(colBarra) << "│"
            << setw(colDisponibilidade) << left << " DISPONIBILIDADE "
            << setw(colBarra) << "│"
            << setw(colLocador) << left << " LOCADOR "
            << desativarNegrito
            << "│" << endl;

    cout << "├─────────┼───────────────┼────────────┼──────────┼──────┼───────────────┼────────────────┼──────────────┼─────────────────┼────────────────────┤" << endl;

    // Exibir os dados das 20 linhas
    for (int i = 0; i < tamanho-1; i++) {
        cout << "│"
                << setw(colPlaca) << left << carros[i].placa
                << setw(colBarra) << "│"
                << setw(colFabricante) << left << carros[i].fabricante
                << setw(colBarra) << "│"
                << setw(colModelo) << left << carros[i].modelo
                << setw(colBarra) << "│"
                << setw(colCor) << left << carros[i].cor
                << setw(colBarra) << "│"
                << setw(colAno) << left << carros[i].ano
                << setw(colBarra) << "│"
                << setw(colQuilometros) << left << to_string(carros[i].quilometragem) + " Km"
                << setw(colBarra) << "│"
                << setw(colCategoria) << left << carros[i].categoria
                << setw(colBarra) << "│"
                << setw(colBarra) << "R$ "
                << setw(colPreco-3) << left << fixed << setprecision(2) << carros[i].preco
                << setw(colBarra) << "│"
                << setw(colDisponibilidade) << left << carros[i].disponibilidade
                << setw(colBarra) << "│"
                << setw(colLocador) << left << carros[i].locador
                << "│" << endl;

        // Exibir a linha de separação após cada linha
        if (i == tamanho-2)
            cout << "╰─────────┴───────────────┴────────────┴──────────┴──────┴───────────────┴────────────────┴──────────────┴─────────────────┴────────────────────╯" << endl;
        else
            cout << "├─────────┼───────────────┼────────────┼──────────┼──────┼───────────────┼────────────────┼──────────────┼─────────────────┼────────────────────┤" << endl;

    }
    for (int i=0; i<tamanho-1; i++){
        cout << "Carro " << i+1 << ": ";
        cout << carros[i].descricao << endl;
    }

}