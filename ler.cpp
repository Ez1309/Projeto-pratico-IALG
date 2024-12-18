#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>

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
    char disponibilidade;
    char *locador = new char[21];
};

int main(){

    menu();
    ifstream arquivo("carrosGrande.csv");
    string linha;
    getline(arquivo, linha);
    cout << "Li o cabeçalho" << endl;

    int tamanho = 40;
    cout << "Defini o tamanho" << endl;
    veiculo *carros = new veiculo[40];
    cout << "Criei o vetor de veiculos 40 tamanhos" << endl;

    while(getline(arquivo, linha)){
        cout << "Entrei no while loop" << endl;
        if (tamanho > 40){
            cout << "Entrei no if" << endl;
            veiculo *temp = new veiculo[tamanho+1];
            cout << "Criei o vetor temporario" << endl;
            memcpy(temp, carros, sizeof(veiculo) * tamanho);
            cout << "Copiei o vetor" << endl;
            delete [] carros;
            cout << "Deletei o antigo" << endl;
            carros = temp;
            cout << "Atualizei o vetor" << endl;
        }
        char lixo;
        cout << "Li o lixo" << endl;
        arquivo.getline(carros[tamanho].placa, 8, ',');
        cout << "Li a placa" << endl;
        arquivo.getline(carros[tamanho].fabricante, 14, ',');
        cout << "Li o fabricante" << endl;
        arquivo.getline(carros[tamanho].modelo, 9, ',');
        cout << "Li o modelo" << endl;
        arquivo.getline(carros[tamanho].cor, 9, ',');
        cout << "Li a cor" << endl;
        arquivo >> carros[tamanho].ano;
        cout << "Li o ano" << endl;
        arquivo.ignore();
        arquivo >> carros[tamanho].quilometragem;
        cout << "Li a quilometragem" << endl;
        arquivo.ignore();
        arquivo.getline(carros[tamanho].categoria, 16, ',');
        cout << "Li a categoria" << endl;
        arquivo >> lixo;
        arquivo.getline(carros[tamanho].descricao, 166, '"');
        cout << "Li a descrição" << endl;
        arquivo >> lixo;
        arquivo >> carros[tamanho].preco;
        cout << "Li o preço" << endl;
        arquivo.ignore();
        arquivo >> carros[tamanho].disponibilidade;
        cout << "Li a disponibilidade" << endl;
        arquivo.ignore();
        arquivo.getline(carros[tamanho].locador, 21, '\n');
        cout << "Li o locador" << endl;
        cout << "Li o carro número " << tamanho;
        tamanho++;
        
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