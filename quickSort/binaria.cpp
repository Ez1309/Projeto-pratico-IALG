#include <iostream>
#include <cstring>  // Para strcmp

using namespace std;

void quickSort(const char* marcas[], int esq, int dir);
int dividir(const char* marcas[], int esq, int dir);

int buscaBinaria(const char* vetor[], int inicial, int final, const char* achar);
void acharAdjacentes(const char* vetor[], const char* achados[], int index, int tamanhoVetor, int& achou);

int main() {

    const char* marcas[] = {
        "Volkswagen", "Chevrolet", "Fiat", "Honda", "Toyota", "Ford", "Peugeot", "Nissan", "Hyundai", "Renault", 
        "Jeep", "BMW", "Mercedes-Benz", "Audi", "Ford", "Fiat", "BMW", "Peugeot", "Toyota", "Honda", 
        "Nissan", "Chevrolet", "Volkswagen", "Hyundai", "Jeep", "Mercedes-Benz", "Audi", "Ford", "Renault", 
        "Peugeot", "Volkswagen", "Chevrolet", "Honda", "Fiat", "BMW", "Nissan"
    };

    int tamanhomarcas = sizeof(marcas) / sizeof(marcas[0]);
    cout << "Vetor original (não ordenado): " << endl;
    cout << "{";
    for (int i = 0; i < tamanhomarcas; i++) {
        cout << marcas[i] << ", ";
    }
    cout << "}" << endl << endl;

    // Aplicando o QuickSort
    quickSort(marcas, 0, tamanhomarcas - 1);

    cout << "Vetor ordenado: " << endl;
    cout << "{";
    for (int i = 0; i < tamanhomarcas; i++) {
        cout << marcas[i] << ", ";
    }
    cout << "}" << endl << endl;

    // Realizando a busca binária para encontrar todas as ocorrências de "Fiat"
    const char* achar;
    
    int index = buscaBinaria(marcas, 0, tamanhomarcas - 1, achar);
    cout << "Primeira ocorrência de " << achar << " está no índice: " << index << endl;
    
    if (index != -1) {
        // Inicializando o vetor de achados
        const char* achados[tamanhomarcas]; 
        int achou = 0;
        
        // Preenchendo o vetor achados com a primeira ocorrência
        achados[achou++] = marcas[index];

        // Passo 2: Buscar as ocorrências adjacentes à direita
        acharAdjacentes(marcas, achados, index, tamanhomarcas, achou);

        // Imprimir todas as ocorrências
        cout << "Todas as ocorrências de " << achar << " são: ";
        for (int i = 0; i < achou; i++) {
            cout << achados[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Função de QuickSort
void quickSort(const char* marcas[], int esq, int dir) {
    if (esq < dir) {
        int pivot = dividir(marcas, esq, dir);
        quickSort(marcas, esq, pivot - 1);
        quickSort(marcas, pivot + 1, dir);
    }
}

// Função para dividir no QuickSort
int dividir(const char* marcas[], int esq, int dir) {
    const char* pivot = marcas[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (strcmp(marcas[j], pivot) <= 0) {
            i++;
            const char* temp = marcas[i];
            marcas[i] = marcas[j];
            marcas[j] = temp;
        }
    }

    const char* temp = marcas[i + 1];
    marcas[i + 1] = marcas[dir];
    marcas[dir] = temp;
    return i + 1;
}

// Função de busca binária
int buscaBinaria(const char* vetor[], int inicial, int final, const char* achar) {
    if (inicial <= final) {
        int meio = (inicial + final) / 2;
        int comparacao = strcmp(achar, vetor[meio]);  // Compara as strings
        if (comparacao > 0)
            return buscaBinaria(vetor, meio + 1, final, achar);
        else if (comparacao < 0)
            return buscaBinaria(vetor, inicial, meio - 1, achar);
        else
            return meio;
    }
    return -1;  // Não encontrado
}

// Função para achar as ocorrências adjacentes à direita
void acharAdjacentes(const char* vetor[], const char* achados[], int index, int tamanhoVetor, int& achou) {
    // Buscar à direita (ocorrências posteriores)
    int indexDir = index + 1;
    while (indexDir < tamanhoVetor && strcmp(vetor[indexDir], vetor[index]) == 0) {
        achados[achou++] = vetor[indexDir++];  // Coloca o valor encontrado no vetor achados
    }
}
