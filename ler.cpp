#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>

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
    int tamanho = 0;
    char caractere;
    linhas = 0;

    ifstream arquivoCSV("carros.csv");
    if (!arquivoCSV){
        cout << "Não foi possível abrir o arquivo carros.csv!" << endl;
        return (not leuComSucesso);
    }

    ofstream binarioSaida("carros.dat");

    // Ignorando o cabeçalho
    arquivoCSV.ignore(109);

    while(arquivoCSV.get(caractere)){
        cout << caractere;
        binarioSaida.write((const char *) &caractere, sizeof(char));
        tamanho++;
    }
    cout << tamanho << endl;

    binarioSaida.seekp(0, binarioSaida.beg);
    binarioSaida.write((const char *) &tamanho, sizeof(int));

    arquivoCSV.close();
    binarioSaida.close();

    int tamanho2 = 0;
    ifstream binarioEntrada("carros.dat");
    binarioEntrada.read((char *)(&tamanho2), sizeof(int));

    cout << tamanho2 << endl;




  



   

    /*string linha;
    getline(arquivoCSV, linha);





    
    // Ler os dados até chegar ao fim do arquivo
    while(!arquivoCSV.eof()){

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
        arquivoCSV.getline(carros[linhas].placa, tamanhoPlaca, ',');
        arquivoCSV.getline(carros[linhas].fabricante, tamanhoFabricante, ',');
        arquivoCSV.getline(carros[linhas].modelo, tamanhoModelo, ',');
        arquivoCSV.getline(carros[linhas].cor, tamanhoCor, ',');

        // Leitura do ano ignorando a vírgula
        arquivoCSV >> carros[linhas].ano;
        arquivoCSV.ignore();

        // Leitura da quilometragem ignorando a vírgula
        arquivoCSV >> carros[linhas].quilometragem;
        arquivoCSV.ignore();

        // Leitura da categoria
        arquivoCSV.getline(carros[linhas].categoria, tamanhoCategoria, ',');

        // Leitura da descrição ignorando as primeiras aspas " e a vírgula
        arquivoCSV.ignore();
        arquivoCSV.getline(carros[linhas].descricao, tamanhoDescricao, '"');
        arquivoCSV.ignore();

        // Leitura do preço ignorando a vírgula
        arquivoCSV >> carros[linhas].preco;
        arquivoCSV.ignore();

        // Leitura da disponibilidade e do locador
        arquivoCSV.getline(carros[linhas].disponibilidade, tamanhoDisponibilidade, ',');
        arquivoCSV.getline(carros[linhas].locador, tamanhoLocador, '\n');
        linhas++;
    }*/
    
    //if (not binarioEntrada){
    //    cout << "Não foi possível escrever no arquivo carros.dat" << endl;
    //    return (not leuComSucesso);
    //}

    // Ler dados do arquivo binário de entrada
    // A FAZER

    // Escrita dos dados no arquivo binário de saída
     //ofstream binarioSaida("carros.dat");
     //binarioSaida.write((const char *) (carros), sizeof(carros));

    // Fechamento dos arquivos
     //binarioSaida.close();
    // binarioEntrada.close();
     //arquivoCSV.close();
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