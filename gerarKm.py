import random

def gerarKm(ano):
    if ano >= 2022:  # Carros novos
        return random.randint(0, 20000)
    elif 2018 <= ano <= 2021:  # Semi-novos
        return random.randint(30000, 80000)
    elif 2010 <= ano <= 2017:  # Usados
        return random.randint(80000, 150000)
    elif 2000 <= ano <= 2009:  # Antigos
        return random.randint(150000, 300000)
    
ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")

ano = random.randint(2000,2024)
quilometragem = gerarKm(ano)
print(f"O carro é do ano {ano} e tem {quilometragem} km rodados")
