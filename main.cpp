#include <iostream>

#include "menu.cpp"
#include "ler.cpp"

using namespace std;

int main() {
    
    menu();
    veiculo *carros = new veiculo [40];
    int linhas = 0;
    

    bool leu = lerDados(carros, linhas);
    if (leu)
        imprimirTabela(carros, linhas);
    
    
    return 0;
}