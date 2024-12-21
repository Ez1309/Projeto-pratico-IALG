#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <typeinfo>

#include "telas.cpp"
#include "ler.cpp"

using namespace std;

int main() {

    string opcaoPrincipal = telaPrincipal();

    if (opcaoPrincipal == "3"){
        telaFinal();
        return 0;
    }

    int linhas = 0;
    bool leu = false;
    leu = csvParaBinario(linhas);

    if (leu){
        veiculo *carros = new veiculo[40];
        leu = lerDados(carros, linhas);
        if (leu)
            imprimirTabela(carros, linhas);
        else 
            return 1;
    }
    else
        return 1;
    return 0;
}