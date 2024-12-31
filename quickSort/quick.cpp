#include <iostream>
#include <cstring>

using namespace std;

 void quickSort(const char* marcas[], int esq, int dir);
 int dividir(const char* marcas[], int esq, int dir);

int main(){


    const char *marcas[] = {"Volkswagen", "Chevrolet", "Fiat", "Honda", "Toyota", "Ford", "Peugeot", "Nissan", "Hyundai", "Renault", 
                     "Jeep", "BMW", "Mercedes-Benz", "Audi", "Ford", "Fiat", "BMW", "Peugeot", "Toyota", "Honda", 
                     "Nissan", "Chevrolet", "Volkswagen", "Hyundai", "Jeep", "Mercedes-Benz", "Audi", "Ford", "Renault", 
                     "Peugeot", "Volkswagen", "Chevrolet", "Honda", "Fiat", "BMW", "Nissan"
                     };

   

    int tamanhomarcas = sizeof(marcas)/sizeof(marcas[0]);

    cout << tamanhomarcas << endl;

    cout << "{";
    for (int i=0; i<tamanhomarcas; i++){
        cout << marcas[i] << ", ";
    }
    cout << "}" << endl << endl;

    quickSort(marcas, 0, tamanhomarcas - 1);

    cout << "{";
    for (int i=0; i<tamanhomarcas; i++){
        cout << marcas[i] << ", ";
    }
    cout << "}" << endl;


    return 0;
}

 void quickSort(const char* marcas[], int esq, int dir){

    if (esq < dir){
        int pivot = dividir(marcas, esq, dir);
        quickSort(marcas, esq, pivot-1);
        quickSort(marcas, pivot+1, dir);
    }

}


int dividir(const char* marcas[], int esq, int dir){

    const char *pivot = marcas[dir];

    int i = esq - 1;

    for (int j=esq; j<dir; j++){
        if (strcmp(marcas[j], pivot) <= 0){
            i++;
            const char *temp = marcas[i];
            marcas[i] = marcas[j];
            marcas[j] = temp;
        }
    }

    const char *temp = marcas[i+1];
    marcas[i+1] = marcas[dir];
    marcas[dir] = temp;
    return i+1;

}