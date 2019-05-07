def permutacao(lista):
    if len(lista)==0:
        return []

    if len(lista)==1:
        return [lista]

    l = []

    for i in range(len(lista)):
        m = lista[i]
        final = lista[:i] + lista[i+1:]

        for p in permutacao(final):
            l.append([m] + p)
    return l

valor = list('123')

for p in permutacao(valor):
    print(p)
