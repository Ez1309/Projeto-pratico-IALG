#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

struct veiculo{
    char* numero = new char[1];
};

int main() {
    
    int tamanho = 0;
    veiculo *vetor = new veiculo [5];

    char *linha = new char[1];
    string titulo;

    ifstream arquivo("testeRed.txt");

    arquivo >> titulo; 
    
    while(arquivo >> linha){
        if (tamanho > 5){
            veiculo *temp = new veiculo[tamanho+1];
            delete [] vetor;
            vetor = temp;
        }
        vetor[tamanho].numero = linha;
        tamanho++;
        cout << "Tamanho: " << tamanho << " | Vetor: { ";
        for (int i=0; i<tamanho; i++){
            cout << vetor[i].numero << " ";
        }
        cout << "}" << endl;
    }

    
    return 0;
}