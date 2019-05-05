def Combinacao(lista, numero):
    n = numero
    result = []
    combinacao = []

    for i in range(len(lista) - (n-1)):
        sentinela = lista[i]
        for j in range((i),(len(lista)-(n-1))):
            combinacao.append(sentinela)
            cont = 1
            while (cont < numero):
                combinacao.append(lista[j+cont])
                cont+=1
            result.append(combinacao)
            combinacao=[]

    return result

print(Combinacao([1,2,3], 2))
