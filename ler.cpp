#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <typeinfo>

using namespace std;

const int tamanhoPlaca = 8;
const int tamanhoFabricante = 14;
const int tamanhoModelo = 9;
const int tamanhoCor = 9;
const int tamanhoCategoria = 16;
const int tamanhoDescricao = 166;
const int tamanhoDisponibilidade = 12;
const int tamanhoLocador = 21;

/*struct veiculo{
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
};*/

struct veiculo {
    char placa[tamanhoPlaca];
    char fabricante[tamanhoFabricante];
    char modelo[tamanhoModelo];
    char cor[tamanhoCor];
    int ano;
    int quilometragem;
    char categoria[tamanhoCategoria];
    char descricao[tamanhoDescricao];
    double preco;
    char disponibilidade[tamanhoDisponibilidade];
    char locador[tamanhoLocador];
};

bool csvParaBinario();
bool lerDados(veiculo* &carros, int &linhas);
void imprimirTabela(veiculo carros[], int &linhas);

bool csvParaBinario(){

    // Abertura do arquivo CSV com checagem de erro
    bool leuComSucesso = true;
    ifstream arquivoCSV("carros.csv");
    if (!arquivoCSV){
        cout << "Não foi possível abrir o arquivo carros.csv!" << endl;
        return (not leuComSucesso);
    }

    // Criação ou atualização do arquivo binário
    ofstream arquivoBinario("carros.dat", ios::binary);
    if (!arquivoBinario){
        cout << "Não foi possível criar o arquivo carros.dat!" << endl;
        return (not leuComSucesso);
    }

    // Ignora o cabeçalho do arquivo CSV
    string linha;
    getline(arquivoCSV, linha);
    cout << linha << endl;

    // Contador para o número de carros
    int linhas = 0;

    // Reservando o início do arquivo binário para receber a quantidade de carros
    arquivoBinario.write((const char *)(&linhas), sizeof(int));

    while(getline(arquivoCSV, linha)){
        cout << linha << endl;
        veiculo carro;
        int tamanhoCarro = 0;
        // Leitura da placa, fabricante, modelo e cor
        arquivoCSV.getline(carro.placa, tamanhoPlaca, ',');
        cout << carro.placa << endl;
        arquivoCSV.getline(carro.fabricante, tamanhoFabricante, ',');
        cout << carro.fabricante << endl;
        arquivoCSV.getline(carro.modelo, tamanhoModelo, ',');
        cout << carro.modelo << endl;
        arquivoCSV.getline(carro.cor, tamanhoCor, ',');
        cout << carro.cor << endl;

        // Leitura do ano ignorando a vírgula
        arquivoCSV >> carro.ano;
        cout << carro.ano << endl;
        arquivoCSV.ignore();

        // Leitura da quilometragem ignorando a vírgula
        arquivoCSV >> carro.quilometragem;
        cout << carro.quilometragem << endl;
        arquivoCSV.ignore();

        // Leitura da categoria
        arquivoCSV.getline(carro.categoria, tamanhoCategoria, ',');
        cout << carro.categoria << endl;

        // Leitura da descrição ignorando as primeiras aspas " e a vírgula
        arquivoCSV.ignore();
        arquivoCSV.getline(carro.descricao, tamanhoDescricao, '"');
        cout << carro.descricao << endl;
        arquivoCSV.ignore();

        // Leitura do preço ignorando a vírgula
        arquivoCSV >> carro.preco;
        cout << carro.preco << endl;
        arquivoCSV.ignore();

        // Leitura da disponibilidade e do locador
        arquivoCSV.getline(carro.disponibilidade, tamanhoDisponibilidade, ',');
        cout << carro.disponibilidade << endl;
        arquivoCSV.getline(carro.locador, tamanhoLocador, '\n');
        cout << carro.locador << endl << endl;

        // Escrita do carro no arquivo binário
        arquivoBinario.write((const char *)(&carro), sizeof(veiculo));
        linhas++;
    }

    cout << linhas << endl;

    // Voltando ao início do arquivo binário para armazenar a quantidade de carros
    arquivoBinario.seekp(0, arquivoBinario.beg);
    arquivoBinario.write((const char *)(&linhas), sizeof(int));

    // Fechando os arquivos utilizados
    arquivoBinario.close();
    arquivoCSV.close();

    return leuComSucesso;
}

bool lerDados(veiculo* &carros, int &linhas){

    bool leuComSucesso = true;

    // Abertura do arquivo binário contendo os carros
    ifstream arquivoBinario("carros.dat");
    if(!arquivoBinario){
        cout << "Não foi possível abrir o arquivo carros.dat!" << endl;
        return (not leuComSucesso);
    }

    // Leitura da quantidade de carros existentes
    arquivoBinario.read((char *)(&linhas), sizeof(int));

    int tamanhoVetor = 0;
    int qtdCarros = 0;

    for (int i=0; i<linhas; i++){
        // Redimensionando o vetor de carros
        if (qtdCarros == tamanhoVetor){
            int novoTamanho = tamanhoVetor + 10;
            veiculo *temp = new veiculo[novoTamanho];
            copy(carros, carros+tamanhoVetor, temp);
            delete[] carros;
            carros = temp;
        }

        // Leitura do carro
        arquivoBinario.read((char *)(&carros[i]), sizeof(veiculo));
        qtdCarros++;
        tamanhoVetor++;
    }

    // Fechando o arquivo binário
    arquivoBinario.close();

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