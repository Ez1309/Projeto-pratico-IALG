#pragma once

#include <fstream>
#include <iomanip>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

using namespace std;

void limpar();
string telaPrincipal();
void telaFinal();   
int larguraTerminal();