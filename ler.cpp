#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>


#include "menu.cpp"

using namespace std;

struct veiculo{
    char *placa = new char[8];
    char *fabricante = new char[14];
    char *modelo = new char[9];
    char *cor = new char[9];
    int ano;
    int quilometragem;
    char *categoria = new char[16];
    char *descricao = new char [166];
    double preco;
    char *disponibilidade = new char[12];
    char *locador = new char[21];
};

int main(){

    menu();
    ifstream arquivo("carrosGrande.csv");
    string linha;
    getline(arquivo, linha);

    int tamanho = 0;
    veiculo *carros;
    carros = new veiculo[40];

    while(tamanho < 151){
        cout << linha << endl << endl;
        if (tamanho >= 40){
            veiculo *temp = new veiculo [tamanho + 1];
            copy(carros, carros+tamanho, temp);
            delete [] carros;
            carros = temp;
        }
        char lixo;
        arquivo.getline(carros[tamanho].placa, 8, ',');
        arquivo.getline(carros[tamanho].fabricante, 14, ',');
        arquivo.getline(carros[tamanho].modelo, 9, ',');
        arquivo.getline(carros[tamanho].cor, 9, ',');
        arquivo >> carros[tamanho].ano;
        arquivo.ignore();
        arquivo >> carros[tamanho].quilometragem;
        arquivo.ignore();
        arquivo.getline(carros[tamanho].categoria, 16, ',');
        arquivo >> lixo;
        arquivo.getline(carros[tamanho].descricao, 166, '"');
        arquivo >> lixo;
        arquivo >> carros[tamanho].preco;
        arquivo >> lixo;
        arquivo.getline(carros[tamanho].disponibilidade, 12, ',');
        arquivo.getline(carros[tamanho].locador, 21, '\n');
        tamanho++;
    }

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

    // ╭ ╮ ╰ ╯ ┬ ┴ ┼ ─

    // Códigos ANSI para negrito
    const string bold_on = "\033[1m";
    const string bold_off = "\033[0m";


    // Linha superior da tabela
    cout << "╭─────────┬───────────────┬────────────┬──────────┬──────┬───────────────┬────────────────┬──────────────┬─────────────────┬────────────────────╮" << endl;
    
    // Cabeçalho
    cout << "│"
         << bold_on
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
         << bold_off
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

    return 0;
}