#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    cout << endl << endl << "         BEM VINDO À";
    ifstream titulo ("teste.txt");
    string linhaTitulo;
    
    while (getline(titulo, linhaTitulo)){
        cout << "         " << linhaTitulo << endl;
    }
    cout << endl;

    //╭─────────┬───────╮
    //│         │       │
    //╰─────────┴───────╯ 

    cout << "                                           ╭──────────────────────────────────╮" << endl
         << "                                           │                                  │" << endl
         << "                                           │   (1) Entrar como administrador  │" << endl
         << "                                           │   (2) Entrar como cliente        │" << endl
         << "                                           │                                  │" << endl
         << "                                           ╰──────────────────────────────────╯" << endl;
    
    
    return 0;
}