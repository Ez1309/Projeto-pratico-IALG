#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _APPLE_
// Inclusões para largura do terminal em macOS/Linux
#include <sys/ioctl.h>
#include <unistd.h>
#endif

using namespace std;

void limpar();
void menu();
int larguraTerminal();

void menu() {
 
    string opcao;
    bool opcaoInvalida = false;
    
    do{
    limpar();
    int largura = larguraTerminal();
    int leftPadding = (largura-37)/2;
    int invalidoPadding = (largura-25)/2;
    int opcaoPadding = (largura-20)/2;
    cout << "Largura terminal: " << largura << endl;
    ifstream titulo ("teste.txt");
    string linhaTitulo;
    
    while (getline(titulo, linhaTitulo)){
        cout << setw(leftPadding) << " " << linhaTitulo << endl;
    }

    if (opcaoInvalida)
        cout << setw(invalidoPadding) << " " << "'" << opcao << "' " << " É UMA OPÇÃO INVÁLIDA!" << endl;

    cout <<  setw(opcaoPadding) << " " << "Escolha uma opção: ";
    getline(cin, opcao);

    opcaoInvalida = (opcao != "1" and opcao != "2");

    }while(opcaoInvalida);
    
}

void limpar(){
    #ifdef _WIN32
        system("cls");
        SetConsoleOutputCP(CP_UTF8);
    #else
        system("clear");
    #endif
}

int larguraTerminal() {

    #ifdef _WIN32
        // Para Windows
        CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    #elif defined(_APPLE) || defined(linux_)
    // Para macOS/Linux
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    }
    #endif
    return 80; // Valor padrão se não for possível obter a largura
}
