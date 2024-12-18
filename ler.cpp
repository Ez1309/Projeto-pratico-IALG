#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>


#include "menu.cpp"

using namespace std;

struct veiculo{
    string placa;
    string fabricante;
    string modelo;
    string cor;
    int ano;
    int quilometragem;
    string categoria;
    string descricao;
    double preco;
    char disponibilidade;
    string locador;
};

int main(){

    menu();
    ifstream arquivo("carros.csv");
    string linha;
    getline(arquivo, linha);

    veiculo carros[151];

    for(int i=0; i<151; i++){
        char lixo;
        getline(arquivo, carros[i].placa, ',');
        getline(arquivo, carros[i].fabricante, ',');
        getline(arquivo, carros[i].modelo, ',');
        getline(arquivo, carros[i].cor, ',');
        arquivo >> carros[i].ano;
        arquivo.ignore();
        arquivo >> carros[i].quilometragem;
        arquivo.ignore();
        getline(arquivo, carros[i].categoria, ',');
        arquivo >> lixo;
        getline(arquivo, carros[i].descricao, '"');
        arquivo >> lixo;
        arquivo >> carros[i].preco;
        arquivo.ignore();
        arquivo >> carros[i].disponibilidade;
        arquivo.ignore();
        getline(arquivo, carros[i].locador, '\n');

    }

    int colBarra = 1;
    int colPlaca = 9;
    int colFabricante = 15;
    int colModelo = 12;
    int colCor = 10;
    int colAno = 6;
    int colQuilometros = 15;
    int colCategoria = 17;
    int colPreco = 14;
    int colDisponibilidade = 17;
    int colLocador = 20;

    // ╭ ╮ ╰ ╯ ┬ ┴ ┼ ─

    // Códigos ANSI para negrito
    const string bold_on = "\033[1m";
    const string bold_off = "\033[0m";


    // Linha superior da tabela
    cout << "╭─────────┬───────────────┬────────────┬──────────┬──────┬───────────────┬────────────────┬──────────────┬─────────────────┬────────────────────╮" << endl;
    
    // Cabeçalho
    cout << "│"
         //<< bold_on
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
         << setw(colPreco) << left << " PREÇO DIáRIO "
         << setw(colBarra) << "│"
         << setw(colDisponibilidade) << left << " DISPONIBILIDADE "
         << setw(colBarra) << "│"
         << setw(colLocador) << left << " LOCADOR "
         //<< bold_off
         << "│" << endl;
    
    cout << "├─────────┼───────────────┼────────────┼──────────┼──────┼───────────────┼────────────────┼──────────────┼─────────────────┼────────────────────╮" << endl;
    

    // Exibir os dados das 20 linhas
    for (int i = 0; i < 150; i++) {
            // Cabeçalho
    cout << "│"
         //<< bold_on
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
         << setw(colQuilometros) << left << carros[i].quilometragem
         << setw(colBarra) << "│"
        << " " << setw(colCategoria) << left << carros[i].categoria
         << setw(colBarra) << "│"
         << setw(colPreco) << left << carros[i].preco
         << setw(colBarra) << "│"
         << setw(colDisponibilidade) << left << carros[i].disponibilidade
         << setw(colBarra) << "│"
         << setw(colLocador) << left << carros[i].locador
         //<< bold_off
         << "│" << endl;

    }
    for (int i=0; i<150; i++){
        cout << "Carro " << i+1 << ": ";
        cout << carros[i].descricao << endl;
    }

    return 0;
}