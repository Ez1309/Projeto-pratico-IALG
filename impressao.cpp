#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <typeinfo>

#include "leitura.cpp"

using namespace std;

void imprimirTabela(veiculo carros[], int linhas, string modo);
void imprimirSeparacao(const char* delimEsq, const char* delim, const char* delimDir, const int tamanhos[], int qtdColunas);
void imprimirCabecalho(const int tamanhos[], const string colunas[], int qtdColunas);
void imprimirLinha(veiculo carros[], int linha, string modo);

void imprimirTabela(veiculo carros[], int linhas, string modo) {
    
    // Ponteiros que irão apontar para os vetores referentes as colunas da tabela
    const int* tamanhos; 
    const string* colunas;

    int qtdColunas;

    // Definição das colunas impressas no modo de administrador
    if (modo == "adm") {

        // Valores inteiros com a largura de cada coluna da tabela
        const int tamanhosAdm[] = {
            tamanhoPlaca, tamanhoFabricante, tamanhoModelo, tamanhoCor,
            tamanhoAno, tamanhoQuilometragem, tamanhoCategoria,
            tamanhoPreco, tamanhoDisponibilidade, tamanhoLocador
        };

        // Descrição de cada coluna da tabela
        const string colunasAdm[] = {
            " PLACA", " FABRICANTE", " MODELO", " COR", " ANO",
            " QUILOMETRAGEM", " CATEGORIA", " PREÇO DIÁRIO ",
            " DISPONIBILIDADE ", " LOCADOR "
        };

        tamanhos = tamanhosAdm;
        colunas = colunasAdm;
        qtdColunas = sizeof(tamanhosAdm) / sizeof(tamanhosAdm[0]);
    } 

    // Definição das colunas impressas no modo de cliente
    else if (modo == "cliente") {

        // Valores inteiros com a largura de cada coluna da tabela
        const int tamanhosCliente[] = {
            4, tamanhoFabricante, tamanhoModelo, tamanhoCor, tamanhoAno,
            tamanhoQuilometragem, tamanhoCategoria, tamanhoPreco
        };

        // Descrição de cada coluna da tabela
        const string colunasCliente[] = {
            "ID", " FABRICANTE", " MODELO", " COR", " ANO",
            " QUILOMETRAGEM", " CATEGORIA", " PREÇO DIÁRIO "
        };

        tamanhos = tamanhosCliente;
        colunas = colunasCliente;
        qtdColunas = sizeof(tamanhosCliente) / sizeof(tamanhosCliente[0]);
    } 

    // Imprime o cabeçalho
    imprimirCabecalho(tamanhos, colunas, qtdColunas);

    // Imprime as linhas e separadores
    for (int linha = 0; linha < linhas; linha++) {
        imprimirLinha(carros, linha, modo);

        if (linha != linhas - 1) {
            imprimirSeparacao("├", "┼", "┤", tamanhos, qtdColunas);
        } else {
            imprimirSeparacao("╰", "┴", "╯", tamanhos, qtdColunas);
        }
    }
}

// Função para imprimir os separadores de linhas com as larguras corretas de cada coluna
void imprimirSeparacao(const char* delimEsq, const char* delim, const char* delimDir, const int tamanhos[], int qtdColunas){
    cout << delimEsq; 
    for (int i=0; i< qtdColunas; i++){
        for (int j=0; j< tamanhos[i]; j++) cout << "─";
        if (i == qtdColunas-1) cout << delimDir;
        else cout << delim;
    }
    cout << endl;    
}

// Função para imprimir o cabeçalho da tabela 
void imprimirCabecalho(const int tamanhos[], const string colunas[], int qtdColunas){
    
    imprimirSeparacao("╭", "┬", "╮", tamanhos, qtdColunas);

    cout << "│";
    for (int i=0; i<qtdColunas; i++){
        cout << setw(tamanhos[i]) << left << colunas[i] << "│";
    }
    cout << endl;

    imprimirSeparacao("├", "┼", "┤", tamanhos, qtdColunas);
}

// Função para imprimir o conetúdo de uma linha da tabela
void imprimirLinha(veiculo carros[], int linha, string modo){

    cout << "│";

    // Colunas específicas dos dois modos de exibição
    if (modo == "adm")
        cout << setw(tamanhoPlaca) << left << carros[linha].placa << "│";
    else if (modo == "cliente")
        cout << setw(4) << left << linha+1 << "│";

    // Colunas comuns entre os dois modos de exibição
    cout << setw(tamanhoFabricante)       << left << carros[linha].fabricante                       << "│"
         << setw(tamanhoModelo)           << left << carros[linha].modelo                           << "│"
         << setw(tamanhoCor)              << left << carros[linha].cor                              << "│"
         << setw(tamanhoAno)              << left << carros[linha].ano                              << "│"
         << setw(tamanhoQuilometragem)    << left << to_string(carros[linha].quilometragem) + " Km" << "│"
         << setw(tamanhoCategoria)        << left << carros[linha].categoria                        << "│"
         << "R$ " << setw(tamanhoPreco-3) << left << fixed << setprecision(2) << carros[linha].preco;

         
        // << "R$ " << setw(colPreco-3) << left << fixed << setprecision(2) << carros[i].preco << "│"
    
    // Coluns específicas do modo de administrador
    if (modo == "adm"){
        cout << "│" 
             << setw(tamanhoDisponibilidade) << left << carros[linha].disponibilidade << "│"
             << setw(tamanhoLocador)         << left << carros[linha].locador;
    }
    cout << "│" << endl;

  
                
            
    
}

