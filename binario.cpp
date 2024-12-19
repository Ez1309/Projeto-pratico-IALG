#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream arquivoTexto("entrada.txt");
	
	int capacidade = 5;
    int* vetor = new int[capacidade];
    int cont = 0;
    int valor;
    
    while (arquivoTexto >> valor) {
        if (cont == capacidade) {
            int novaCapacidade = capacidade + 5;
            int* temp = new int[novaCapacidade];
            for (int i = 0; i < capacidade; i++) {
                temp[i] = vetor[i];
            }
            delete[] vetor;
            vetor = temp;
            capacidade = novaCapacidade;
        }
        vetor[cont++] = valor;
    }
    
    arquivoTexto.close();
    
    cout << "Dados lidos do arquivo de texto:" << endl;
    for (int i = 0; i < cont; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
    
    ofstream arquivoBinarioSaida("dados.dat");
    
    arquivoBinarioSaida.write(reinterpret_cast<char*>(&cont), sizeof(int)); // Tamanho
    arquivoBinarioSaida.write(reinterpret_cast<char*>(vetor), cont * sizeof(int)); // Valores
    arquivoBinarioSaida.close();
    
    delete[] vetor;
    
    ifstream arquivoBinarioEntrada("dados.dat");
    
    int tamanho;
    arquivoBinarioEntrada.read(reinterpret_cast<char*>(&tamanho), sizeof(int)); // Tamanho
    int* vetorLido = new int[tamanho];
    arquivoBinarioEntrada.read(reinterpret_cast<char*>(vetorLido), tamanho * sizeof(int)); // Lê os valores
    arquivoBinarioEntrada.close();
    
    cout << "Dados lidos do arquivo binário:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << vetorLido[i] << " ";
    }
    cout << endl;
    
    delete[] vetorLido;
    
	return 0;
}
