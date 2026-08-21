VOGAIS_LISTA = "aeiou"
ALPHABET = "abcdefghijklmnopqrstuvwxyz"
vogais = [0, 4, 8, 14, 20]


def proxima_consoante(c):
    for i in range(ALPHABET.index(c) + 1, len(ALPHABET)):
        proxima = ALPHABET[i]
        if VOGAIS_LISTA.find(proxima) == -1:
            return proxima
    return c


def vogal_mais_perto(c):
    index_c = ALPHABET.index(c)
    index_vogal1 = 0
    index_vogal2 = 0

    for i in range(len(vogais) - 1):
        index_vogal1 = vogais[i]
        index_vogal2 = vogais[i + 1]

        if index_vogal1 < index_c < index_vogal2:
            menor_1 = abs(index_c - index_vogal1)
            menor_2 = abs(index_c - index_vogal2)

            if menor_1 == menor_2 or menor_1 < menor_2:
                return ALPHABET[index_vogal1]

            return ALPHABET[index_vogal2]

    return ALPHABET[index_vogal2]


def codificar(frase):
    result = ""

    for c in frase:
        if VOGAIS_LISTA.find(c) != -1:
            result += c
            continue

        result += c
        vogal = vogal_mais_perto(c)
        result += vogal
        c = proxima_consoante(c)
        result += c

    return result


phrase = input()
if 1 > phrase.len() or 30 < phrase.len():
    print("")

frase_codificada = codificar(phrase)

print(frase_codificada)