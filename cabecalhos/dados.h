#pragma once

#include <fstream>
#include <string>
#include <algorithm>

#include <iostream>
using namespace std;

// Constantes inteiras para a quantidade máxima de caracteres de cada coluna
const int tamanhoPlaca = 8;
const int tamanhoFabricante = 14;
const int tamanhoModelo = 9;
const int tamanhoCor = 9;
const int tamanhoAno = 6;
const int tamanhoQuilometragem = 15;
const int tamanhoCategoria = 16;
const int tamanhoDescricao = 166;
const int tamanhoPreco = 14;
const int tamanhoDisponibilidade = 17;
const int tamanhoLocador = 21;

// Registro para armazenar um veículo
struct veiculo {
    char placa[tamanhoPlaca];
    char fabricante[tamanhoFabricante];
    char modelo[tamanhoModelo];
    char cor[tamanhoCor];
    int ano;
    int quilometragem;
    char categoria[tamanhoCategoria];
    char descricao[tamanhoDescricao];
    double preco;
    char disponibilidade[tamanhoDisponibilidade];
    char locador[tamanhoLocador];
};

bool csvParaBinario(int &linhas);
bool lerDados(veiculo* &carros, int &linhas);
bool atualizarDados(veiculo* &carros, int &linhas);