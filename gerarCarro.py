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

def gerar_preco(categoria, ano, quilometragem):
    # Novos intervalos de preço
    categorias_precos = {
        "Hatch Compacto": (100.00, 200.00),
        "Hatch Medio": (180.00, 350.00),
        "Hatch Premium": (400.00, 800.00),
        "Seda Compacto": (150.00, 300.00),
        "Seda Medio": (300.00, 600.00),
        "Seda Premium": (600.00, 1000.00),
        "Picape Compacta": (200.00, 400.00),
        "Picape Media": (400.00, 800.00),
        "SUV Compacto": (300.00, 600.00),
        "SUV Medio": (600.00, 1200.00),  # Ampliação para premium SUVs
    }

    # Preço base pela categoria
    min_preco, max_preco = categorias_precos.get(categoria, (150.00, 300.00))
    preco_base = random.uniform(min_preco, max_preco)

    # Ajuste pelo ano do carro
    ano_atual = 2024
    idade = ano_atual - ano

    if idade <= 1:  # Carro de até 1 ano
        fator_ano = 1.3  # 30% a mais no preço
    elif idade <= 3:
        fator_ano = 1.2  # 20% a mais
    elif idade <= 5:
        fator_ano = 1.1  # 10% a mais
    elif idade <= 10:
        fator_ano = 1.0  # Sem alteração
    elif idade <= 20:
        fator_ano = 0.8  # Redução de 20%
    else:
        fator_ano = 0.6  # Carros muito antigos: 40% de desconto

    # Ajuste pela quilometragem
    if quilometragem <= 20000:
        fator_km = 1.3  # 30% a mais para carros "seminovos"
    elif quilometragem <= 50000:
        fator_km = 1.2  # 20% a mais
    elif quilometragem <= 100000:
        fator_km = 1.0  # Sem alteração
    elif quilometragem <= 200000:
        fator_km = 0.8  # Redução de 20%
    else:
        fator_km = 0.6  # Carros muito rodados: 40% de desconto

    # Preço final considerando os fatores
    preco_final = preco_base * fator_ano * fator_km
    return round(preco_final, 2)



def gerarKm(ano):
    if ano >= 2022:
        return random.randint(0, 20000)
    elif 2018 <= ano <= 2021:
        return random.randint(30000, 80000)
    elif 2010 <= ano <= 2017:
        return random.randint(80000, 150000)
    elif 2000 <= ano <= 2009:
        return random.randint(150000, 300000)
    elif ano <=1999:
        return random.randint(300000, 500000)

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

    categorias_modelos = {
        "Hatch Compacto":["Mobi", "Argo", "Fit", "Ka", "Etios", "Yaris", "208", "March", "HB20", "Kwid"],
        "Hatch Medio": ["Gol", "Fox", "Polo", "Onix", "Corsa", "Celta", "Classic", "Palio", "Uno", "Fiesta"],
        "Hatch Premium": ["A3", "A200"],
        "Seda Compacto": ["Voyage", "Prisma", "Siena", "City", "Sandero", "Logan"],
        "Seda Medio": ["Jetta", "Civic", "Corolla", "Fusion", "Versa"],
        "Seda Premium": ["320i", "C180", "A4"],
        "Picape Compacta": ["Saveiro", "Toro", "Strada"],
        "Picape Media": ["Amarok", "S10", "Hilux", "Ranger", "Frontier"],
        "SUV Compacto": ["Pulse", "HR-V", "CR-V", "EcoSport", "2008", "Kicks", "Creta", "Duster", "Renegade", "Q3"],
        "SUV Medio": ["Tucson", "Compass", "X1", "X3"],
    }

    
    categorias_descricao = {
        "Hatch Compacto": "carro compacto pratico e economico. Ideal para o uso no dia a dia urbano com baixo consumo de combustivel.",
        "Hatch Medio": "carro espaçoso confortavel e economico. Ideal para viagens curtas e uso em familia com bons recursos e conforto",
        "Hatch Premium": "carro luxuoso altamente confortavel e tecnologico. Ideal para quem busca mais conforto desempenho e design refinado.",
        "Seda Compacto": "carro popular espaçoso com boa estabilidade de direçao. Ideal para conforto e desempenho urbano.",
        "Seda Medio": "carro confortavel espaçoso com bom acabamento e motor potente. Ideal para viagens longas e uso na cidade combinando desempenho e conforto.",
        "Seda Premium": "carro espaçoso extremamente confortavel com acabamento e tecnologias premium. Ideal para quem busca um carro de alto padrao com design e desempenho excepcionais.",
        "Picape Compacta": "carro versatil com caçamba e cabine de passageiros. Ideal para transporte de pequenas cargas e tarefas cotidianas com agilidade para o uso urbano.",
        "Picape Media": "carro com motor resistente caçamba grande e cabine de passageiros. Ideal para terrenos rurais e acidentados com mais capacidade de carga e robustez.",
        "SUV Compacto": "carro espaçoso versatil e com bom desempenho. Ideal para quem busca um carro mais robusto adequado para o dia a dia e leves aventuras.",
        "SUV Medio": "carro espaçoso sofisticado e com motor potente. Ideal para viagens longas em familia e atividades ao ar livre com mais recursos e conforto.",
    }

    anos_fabricacao = {
    "Gol": (1980, 2022), "Fox": (2003, 2021), "Polo": (2002, 2024), "Voyage": (1981, 2023), "Saveiro": (1982, 2024), "Jetta": (2006, 2024), "Amarok": (2010, 2024),
    "Onix": (2012, 2024), "Prisma": (2006, 2019), "S10": (1995, 2024), "Corsa": (1994, 2012), "Celta": (2000, 2015), "Classic": (1995, 2016),
    "Palio": (1996, 2017), "Uno": (1984, 2021), "Mobi": (2016, 2024), "Toro": (2016, 2024), "Strada": (1998, 2024), "Siena": (1997, 2021), "Argo": (2017, 2024), "Pulse": (2021, 2024),
    "Civic": (1972, 2024), "HR-V": (2015, 2024), "Fit": (2001, 2020), "City": (2009, 2024), "CR-V": (1995, 2024),
    "Corolla": (1966, 2024), "Yaris": (2018, 2024), "Hilux": (1968, 2024), "Etios": (2012, 2021), "SW4": (1993, 2024),
    "Ka": (1996, 2021), "Fiesta": (1976, 2019), "EcoSport": (2003, 2021), "Fusion": (2006, 2020), "Ranger": (1983, 2024),
    "208": (2012, 2024), "2008": (2013, 2024),
    "Kicks": (2016, 2024), "March": (1982, 2020), "Frontier": (1997, 2024), "Versa": (2011, 2024),
    "HB20": (2012, 2024), "Creta": (2016, 2024), "Tucson": (2004, 2024),
    "Kwid": (2015, 2024), "Sandero": (2007, 2024), "Logan": (2004, 2024), "Duster": (2010, 2024),
    "Renegade": (2015, 2024), "Compass": (2016, 2024),
    "320i": (1975, 2024), "X1": (2009, 2024), "X3": (2003, 2024),
    "C180": (1993, 2024), "A200": (2012, 2024),
    "A3": (1996, 2024), "A4": (1994, 2024), "Q3": (2011, 2024),
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
    
    cor = gerar_cor()
    intervaloAnos = anos_fabricacao[modelo]
    ano = random.randint(intervaloAnos[0], intervaloAnos[1])
    quilometragem = gerarKm(ano)
    preco = gerar_preco(categoria, ano, quilometragem)
    disponibilidade = random.choice(["Alugado", "Disponivel"])
    if disponibilidade == "Disponivel":
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
salvar_csv("carros.csv", 10)