//sua funçao
// Descriçao
//retorno


//1 - indice (posicçao da primeira ocorrencia do valor, se encontrado)
//--1 , se o valor nao estiver na list.

int buscalinear(int list[],int tamanho,int valor){

    for (int i =0; i<tamanho;i++){
        if(list[i]==valor){
            // se encontramos retornamos a posiçao indice de onde está
            return i;
        }
    }
    // se o loop terminar e nao encontrarmos nada , retornamos 1
    return -1;
}