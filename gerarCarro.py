import csv
import random
import string



# Funções existentes


# Listas de nomes e sobrenomes
primeiros_nomes = ['Joao', 'Maria', 'Carlos', 'Ana', 'Jose', 'Fernanda', 'Rafael', 'Luciana', 
                   'Lucas', 'Juliana', 'Paulo', 'Camila', 'Renato', 'Tatiane', 'Gustavo']

sobrenomes = ['Silva', 'Souza', 'Oliveira', 'Costa', 'Pereira', 'Lima', 'Rodrigues', 'Martins', 
              'Santos', 'Almeida', 'Mendes', 'Gomes', 'Ferreira', 'Ribeiro', 'Cardoso']

# Funçao para gerar um nome completo aleatorio
def gerar_nome_completo():
    primeiro_nome = random.choice(primeiros_nomes)
    sobrenome = random.choice(sobrenomes)
    return f"{primeiro_nome} {sobrenome}"

def gerar_placa():
    modelo = random.choice(["antigo", "mercosul"])
    if modelo == "antigo":
        letras = ''.join(random.choices(string.ascii_uppercase, k=3))  # 3 letras aleatorias
        numeros = ''.join(random.choices(string.digits, k=4))  # 4 numeros aleatorios
        placa = letras + numeros
    elif modelo == "mercosul":
        letras = ''.join(random.choices(string.ascii_uppercase, k=3))  # 3 letras aleatorias
        numero = random.choice(string.digits)  # 1 numero aleatorio
        letra = random.choice(string.ascii_uppercase)  # 1 letra aleatoria
        numeros_finais = ''.join(random.choices(string.digits, k=2))  # 2 numeros aleatorios
        placa = letras + numero + letra + numeros_finais
    return placa

def gerar_preco(categoria):
    categorias_precos = {
        "Hatch Compacto": (90.00, 150.00),
        "Hatch Medio": (140.00, 220.00),
        "Hatch Premium": (250.00, 450.00),
        "Seda Compacto": (100.00, 170.00),
        "Seda Medio": (180.00, 300.00),
        "Seda Premium": (350.00, 600.00),
        "Picape Compacta": (150.00, 230.00),
        "Picape Media": (250.00, 400.00),
        "SUV Compacto": (180.00, 280.00),
        "SUV Medio": (300.00, 500.00),
    }
    min_preco, max_preco = categorias_precos.get(categoria, (100.00, 200.00))  # Valores padrao caso categoria nao seja encontrada
    preco = random.uniform(min_preco, max_preco)  # Gera um valor aleatorio dentro do intervalo
    return round(preco, 2)  # Arredonda para 2 casas decimais

def gerarKm(ano):
    if ano >= 2022:
        return random.randint(0, 20000)
    elif 2018 <= ano <= 2021:
        return random.randint(30000, 80000)
    elif 2010 <= ano <= 2017:
        return random.randint(80000, 150000)
    elif 2000 <= ano <= 2009:
        return random.randint(150000, 300000)

def gerar_cor():
    cores = ["Preto", "Branco", "Prata", "Cinza", "Azul", "Vermelho", "Amarelo", 
             "Verde", "Bege", "Laranja", "Marrom"]
    return random.choice(cores)

def gerar_carro():
    fabricantes_modelos = {
        "Volkswagen":["Gol", "Fox", "Polo", "Voyage", "Saveiro", "Jetta", "Amarok"],
        "Chevrolet":["Onix", "Prisma", "S10", "Corsa", "Celta", "Classic"],
        "Fiat":["Palio", "Uno", "Mobi", "Toro", "Strada", "Siena", "Argo", "Pulse"],
        "Honda":["Civic", "HR-V", "Fit", "City", "CR-V"],
        "Toyota":["Corolla", "Yaris", "Hilux", "Etios", "SW4"],
        "Ford":["Ka", "Fiesta", "EcoSport", "Fusion", "Ranger"],
        "Peugeot":["208", "2008"],
        "Nissan":["Kicks", "March", "Frontier", "Versa"],
        "Hyundai":["HB20", "Creta", "Tucson"],
        "Renault":["Kwid", "Sandero", "Logan", "Duster"],
        "Jeep":["Renegade", "Compass"],
        "BMW":["320i", "X1", "X3"],
        "Mercedes-Benz":["C180", "A200"],
        "Audi":["A3", "A4", "Q3"],
    }
   
        "Hatch Compacto":
        "Hatch Medio": 
        "Hatch Premium":
        "Seda Compacto": 
        "Seda Medio":
        "Seda Premium": 
        "Picape Compacta":
        "Picape Media": 
        "SUV Compacto"
        "SUV Medio"
    categorias_descricao = {
        "Hatch Compacto": "carro compacto, pratico e economico. Ideal para o uso no dia a dia urbano, com baixo consumo de combustivel.",
        "Hatch Medio": "carro espaçoso, confortavel e economico. Ideal para viagens curtas e uso em familia, com bons recursos e conforto",
        "Hatch Premium": "carro luxuoso, altamente confortavel e tecnologico. Ideal para quem busca mais conforto, desempenho e design refinado.",
        "Seda Compacto": "carro popular, espaçoso, com boa estabilidade de direçao. Ideal para conforto e desempenho urbano.",
        "Seda Medio": "carro confortavel, espaçoso, com bom acabamento e motor potente. Ideal para viagens longas e uso na cidade, combinando desempenho e conforto.",
        "Seda Premium": "carro espaçoso, extremamente confortavel, com acabamento e tecnologias premium. Ideal para quem busca um carro de alto padrao, com design e desempenho excepcionais.",
        "Picape Compacta": "carro versatil com caçamba e cabine de passageiros. Ideal para transporte de pequenas cargas e tarefas cotidianas, com agilidade para o uso urbano.",
        "Picape Media": "carro com motor resistente, caçamba grande e cabine de passageiros. Ideal para terrenos rurais e acidentados, com mais capacidade de carga e robustez.",
        "SUV Compacto": "carro espaçoso, versatil e com bom desempenho. Ideal para quem busca um carro mais robusto, adequado para o dia a dia e leves aventuras.",
        "SUV Medio": "carro espaçoso, sofisticado e com motor potente. Ideal para viagens longas em familia e atividades ao ar livre, com mais recursos e conforto.",
    }


    
    

    placa = gerar_placa()
    categoria = random.choice(list(categorias_modelos.keys()))
    modelo = random.choice(categorias_modelos[categoria])
    
    # Encontrar o fabricante para o modelo escolhido
    fabricante = None
    for f, modelos in fabricantes_modelos.items():
        if modelo in modelos:
            fabricante = f
            break

    descricao = categorias_descricao[categoria]
    preco = gerar_preco(categoria)
    cor = gerar_cor()
    ano = random.randint(2000, 2024)
    quilometragem = gerarKm(ano)
    disponibilidade = random.choice(["A", "D"])
    if disponibilidade == "D":
        locador = "Disponivel"
    else:
        locador = gerar_nome_completo()
    

    carro = {
        "Placa": placa,
        "Marca": fabricante,
        "Modelo": modelo,
        "Cor": cor,
        "Ano": ano,
        "Quilometragem": quilometragem,
        "Categoria": categoria,
        "Descriçao": descricao,
        "Preço Diario": preco,
        "Disponibilidade": disponibilidade,  # Vamos deixar como "Disponivel" por enquanto
        "Nome do locador": locador  # Nome temporario
    }

    return carro

# Funçao para salvar os carros em um arquivo CSV com codificaçao UTF-8
def salvar_csv(nome_arquivo, quantidade):
    with open(nome_arquivo, mode='w', newline='', encoding='utf-8') as file:
        writer = csv.DictWriter(file, fieldnames=["Placa", "Marca", "Modelo", "Cor", "Ano", "Quilometragem", "Categoria", "Descriçao", "Preço Diario", "Disponibilidade", "Nome do locador"])
        writer.writeheader()
        
        for _ in range(quantidade):
            carro = gerar_carro()
            writer.writerow(carro)

# Gerar e salvar 30 carros no arquivo "carrosGrande.csv"
salvar_csv("carrosGrande.csv", 150)
