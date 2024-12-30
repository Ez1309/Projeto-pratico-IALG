#include "cabecalhos/dados.h"

// Função que lê dados de um arquivo CSV e aramazena em um arquivo binário
bool csvParaBinario(int &linhas){

    bool leuComSucesso = true;

    // Criação ou atualização do arquivo binário
    ofstream arquivoBinario("arquivos/carros.dat");
    if (!arquivoBinario){
        cout << "Não foi possível escrever no arquivo carros.dat!" << endl;
        return(not leuComSucesso);
    }

    // Abertura do arquivo CSV
    ifstream arquivoCSV("arquivos/carros.csv");
    if (!arquivoCSV){
        cout << "Não foi possível abrir o arquivo carros.csv!" << endl;
        return (not leuComSucesso);
    }
    
    // Ignorar cabeçalho do CSV
    string linha;
    getline(arquivoCSV, linha);
    

    linhas = 0;
    //cout << "Linha " << linhas+1 << ": "<< linha << endl << endl;
    // Loop para preencher o arquivo binário com os carros
    while(!arquivoCSV.eof()){
        
        veiculo carro = {}; // Variável temporária

        // Leitura da placa, fabricante, modelo e cor
        arquivoCSV.getline(carro.placa, tamanhoPlaca, ',');
        arquivoCSV.getline(carro.fabricante, tamanhoFabricante, ',');
        arquivoCSV.getline(carro.modelo, tamanhoModelo, ',');
        arquivoCSV.getline(carro.cor, tamanhoCor, ',');
       
        // Leitura do ano ignorando a vírgula
        arquivoCSV >> carro.ano;
        arquivoCSV.ignore();
       
        // Leitura da quilometragem ignorando a vírgula
        arquivoCSV >> carro.quilometragem;
        arquivoCSV.ignore();
        
        // Leitura da categoria
        arquivoCSV.getline(carro.categoria, tamanhoCategoria, ',');

        // Leitura da descrição
        arquivoCSV.getline(carro.descricao, tamanhoDescricao, ',');
        
        // Leitura do preço ignorando a vírgula
        arquivoCSV >> carro.preco;
        arquivoCSV.ignore();
        
        // Leitura da disponibilidade e do locador
        arquivoCSV.getline(carro.disponibilidade, tamanhoDisponibilidade, ',');
        arquivoCSV.getline(carro.locador, tamanhoLocador, '\n');
        

        // Escrita do carro no arquivo binário
        arquivoBinario.write((const char*)(&carro), sizeof(veiculo));

        /*cout << "Linha " << linhas+2 << ": ";
        cout << carro.placa << ", ";
        cout << carro.fabricante << ", ";
        cout << carro.modelo << ", ";
        cout << carro.cor << ", ";
        cout << carro.ano << ", ";
        cout << carro.quilometragem << ", ";
        cout << carro.categoria << ", ";
        cout << carro.descricao << ", ";
        cout << carro.preco << ", ";
        cout << carro.disponibilidade << ", ";
        cout << carro.locador << endl << endl;*/
          
        linhas++;
    }

    //cout << endl << "Quantidade de linhas lidas: " << linhas << endl << endl;
    //cout << "Linhas depois da escrita: " << linhas << endl;

    // Fechando os arquivos abertos
    arquivoCSV.close();
    arquivoBinario.close();

    return leuComSucesso;
}

// Função que escreve os dados do arquivo binário no vetor de veículos
bool lerDados(veiculo* &carros, int &linhas){

    bool leuComSucesso = true;

    // Abertura do arquivo binário contendo os carros
    ifstream arquivoBinario("arquivos/carros.dat");
    if(!arquivoBinario){
        cout << "Não foi possível abrir o arquivo carros.dat!" << endl;
        return (not leuComSucesso);
    }

    int tamanhoVetor = 40;
    int qtdCarros = 0;

    for (int i=0; i<linhas; i++){
        // Redimensionando o vetor de carros
        if (qtdCarros == tamanhoVetor){
            //cout << "Redimensionando vetor de " << tamanhoVetor << " para " << tamanhoVetor + 10 << endl;
            int novoTamanho = tamanhoVetor + 10;
            veiculo *temp = new veiculo[novoTamanho];
            copy(carros, carros+tamanhoVetor, temp);
            delete[] carros;
            carros = temp;
            tamanhoVetor = novoTamanho;
        }

        // Leitura do carro
        arquivoBinario.read((char *)(&carros[i]), sizeof(veiculo));
        qtdCarros++;
    }

    // Fechando o arquivo binário
    arquivoBinario.close();

    return leuComSucesso;
}


bool atualizarDados(veiculo* &carros, int &linhas) {
    
    bool atualizouComSucesso = true;

    ofstream arquivoBinario("arquivos/carros.dat");
    if (!arquivoBinario){
        cout << "Não foi possível escrever no arquivo carros.dat!" << endl;
        return (not atualizouComSucesso);
    }
    arquivoBinario.write((const char*)(carros), sizeof(veiculo)*linhas);

    // Criar o novo arquivo
    ofstream arquivoCSV("arquivos/carros.csv");
    if (!arquivoCSV) {
        cout << "Não foi possível atualizar o arquivo carros.csv!" << endl;
        return false;
    }

    // Escrever o cabeçalho
    arquivoCSV << "Placa,Fabricante,Modelo,Cor,Ano,Quilometragem,Categoria,Descricao,Preco,Disponibilidade,Locador" << endl;

    // Escrever os dados dos carros
    for (int i = 0; i < linhas; i++) {
        arquivoCSV << carros[i].placa << ","
                   << carros[i].fabricante << ","
                   << carros[i].modelo << ","
                   << carros[i].cor << ","
                   << carros[i].ano << ","
                   << carros[i].quilometragem << ","
                   << carros[i].categoria << ","
                   << carros[i].descricao << ","
                   << carros[i].preco << ","
                   << carros[i].disponibilidade << ","
                   << carros[i].locador;
                   if (i != linhas - 1) arquivoCSV << endl;
    }

    arquivoCSV.close();
    arquivoBinario.close();
    return atualizouComSucesso;
}

