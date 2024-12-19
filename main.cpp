#include <iostream>

#include "telas.cpp"
#include "ler.cpp"

using namespace std;

int main() {
    
    string opcaoPrincipal = telaPrincipal();
    if (opcaoPrincipal == "3"){
        telaFinal();
        return 0;
    }
    veiculo *carros = new veiculo [40];
    int linhas = 0;
    

    bool leu = lerDados(carros, linhas);
    if (leu)
        imprimirTabela(carros, linhas);
    
    
    return 0;
}