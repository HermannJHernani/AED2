def desarranjo(posicao, entrada , visitados, resposta): 
    if (posicao == len(entrada)):
        print (resposta)
    for i in range(len(entrada)):
        if ((i != posicao) and (visitados[i]==0)):
            visitados[i] = 1
            resposta[posicao] = entrada[i]
            desarranjo(posicao+1, entrada, visitados, resposta)
            visitados[i] = 0
    
entrada = [1, 2, 3, 4]
visitados = [0]*len(entrada)
resposta = [-1]*len(entrada)
desarranjo(0, entrada, visitados, resposta)