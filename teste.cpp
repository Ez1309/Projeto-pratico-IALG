#include <iostream>

using namespace std;

int main() {
    
    string opcoes[7] = {"A", "A", "A", "B", "B", "A", "C"};
    int quantidade = 1;

    for (int i=0; i<7; i++){
        if (opcoes[i] == "A"){
            cout << quantidade << " | " << "A" << endl;
            quantidade++;
            }
    }

    
    return 0;
}