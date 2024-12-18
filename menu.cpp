#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
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

    do {
        limpar();
        int largura = larguraTerminal();
        int leftPadding = (largura - 37) / 2;
        int invalidoPadding = (largura - 25) / 2;
        int opcaoPadding = (largura - 20) / 2;

        cout << "Largura terminal: " << largura << endl;

        ifstream titulo("menuInicial.txt");
        string linhaTitulo;

        while (getline(titulo, linhaTitulo)) {
            cout << setw(leftPadding) << " " << linhaTitulo << endl;
        }

        if (opcaoInvalida)
            cout << setw(invalidoPadding) << " " << "'" << opcao << "' "
                 << "É UMA OPÇÃO INVÁLIDA!" << endl;

        cout << setw(opcaoPadding) << " " << "Escolha uma opção: ";
        getline(cin, opcao);

        opcaoInvalida = (opcao != "1" && opcao != "2");

    } while (opcaoInvalida);
}

void limpar() {
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
    cout << "O sistema é Windows" << endl;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
#else //defined(_APPLE) || defined(linux_)
    // Para macOS/Linux
    struct winsize w;
    cout << "O sistema é Linux ou macOS" << endl;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    }
#endif
    // Retorna um valor padrão caso não consiga determinar a largura
    cout << "Não foi possível obter a largura do terminal. Usando valor padrão (80)." << endl;
    return 80;
}