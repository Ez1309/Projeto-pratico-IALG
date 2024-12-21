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
     arquivo.close();
     return leuComSucesso;
}