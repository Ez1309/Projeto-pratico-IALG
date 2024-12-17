import random
import string

def gerar_placa():
    # Escolha aleatória entre os dois modelos de placa
    modelo = random.choice(["antigo", "mercosul"])

    if modelo == "antigo":
        # Geração de placa no formato XXX9999
        letras = ''.join(random.choices(string.ascii_uppercase, k=3))  # 3 letras aleatórias
        numeros = ''.join(random.choices(string.digits, k=4))  # 4 números aleatórios
        placa = letras + numeros

    elif modelo == "mercosul":
        # Geração de placa no formato XXX9X99
        letras = ''.join(random.choices(string.ascii_uppercase, k=3))  # 3 letras aleatórias
        numero = random.choice(string.digits)  # 1 número aleatório
        letra = random.choice(string.ascii_uppercase)  # 1 letra aleatória
        numeros_finais = ''.join(random.choices(string.digits, k=2))  # 2 números aleatórios
        placa = letras + numero + letra + numeros_finais

    return placa

# Teste
placa_gerada = gerar_placa()
print("Placa Gerada:", placa_gerada)
placa_gerada = gerar_placa()
print("Placa Gerada:", placa_gerada)
placa_gerada = gerar_placa()
print("Placa Gerada:", placa_gerada)
placa_gerada = gerar_placa()
print("Placa Gerada:", placa_gerada)
placa_gerada = gerar_placa()
print("Placa Gerada:", placa_gerada)
