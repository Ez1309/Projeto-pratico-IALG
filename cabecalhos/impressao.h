#pragma once

#include <iomanip>
#include "dados.h"

void imprimirTabela(veiculo carros[], int linhas, string modo, int inicio, int final);
void imprimirSeparacao(const char* delimEsq, const char* delim, const char* delimDir, const int tamanhos[], int qtdColunas);
void imprimirCabecalho(const int tamanhos[], const string colunas[], int qtdColunas);
void imprimirLinha(veiculo carros[], int linha, string modo, int index);