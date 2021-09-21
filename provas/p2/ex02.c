/*
2) Considerando o TAD ListaSequencial¹, implemente uma nova função
chamada remove_intervalo_lista, que retira da lista todos os elementos
de uma posição inicial até uma posição final.  Por exemplo,
na chamada abaixo, são retirados da lista os elementos das
posições 5,6,7,8 e 9. Não é permitido chamar outras funções do TAD Lista. 
Nas situações inválidas a função deverá retornar como código de erro
o número -1. Sucesso retornar 0. Mantenha o padrão pré-definido do
TAD, que diz que a posição 1 corresponde ao primeiro elemento da lista.

Exemplo de chamada da função:
remove_intervalo_lista(lista,5,9)

*/

int remove_intervalo_lista(Lista* li, int min, int max){
    if(li == NULL){
        return -1;
    }
    if(min < 1 || max < min || max < 1 || min < 1){
        return -1;
    }
    int k, i=max;
    while(i>=min){
        li->qtd--;
        k=i;
        while(k >= min){
            li->dados[k-1] = li->dados[k];
            k--;
        }
        i--;
    }
    return 0;
}
