#include "cabecalhos/telas.h"
#include "cabecalhos/impressao.h"

#include <iostream>
using namespace std;

int main() {

    string opcaoPrincipal = telaPrincipal();
    string modo;

    if (opcaoPrincipal == "3"){
        telaFinal();
        return 0;
    }
    else if (opcaoPrincipal == "1")
        modo = "adm";
    else if (opcaoPrincipal == "2")
        modo = "cliente";

    veiculo *carros = new veiculo[40];
    int linhas = 0;

    int inicio = 0;
    int final = 100;
    
    // Imprimir tabela se tudo tiver sido lido corretamente
    if (csvParaBinario(linhas) and lerDados(carros, linhas)){
        imprimirTabela(carros, linhas, modo, inicio, final);
    }
    else return 1;

    return 0;
}