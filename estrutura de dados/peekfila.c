Elemento espiar(Fila *f) {
    Elemento vazio = {-1};              // Valor padrão se a fila estiver vazia
    if (filaVazia(f))
        return vazio;     // Impede acesso indevido
    return f->itens[f->inicio];         // Retorna o elemento da frente
}