#include <iostream>
#include <memory>

int main()
{
    auto ptr_a = std::make_unique<int>(90);
    std::cout << "Endereco: "
              << static_cast<const void *>(ptr_a.get())
              << "\n";
}
/*Explicação passo a passo:

#include <iostream>
Inclui a biblioteca padrão para entrada e saída (como std::cout).

#include <memory>
Inclui utilitários de gerenciamento de memória, como std::unique_ptr.

int main()
Função principal, ponto de entrada do programa.

auto ptr_a = std::make_unique<int>(90);

std::make_unique<int>(90) cria dinamicamente um inteiro no heap, com valor 90.

ptr_a é um std::unique_ptr<int>, ou seja, um ponteiro inteligente que gerencia automaticamente a memória (não precisa chamar delete manualmente).

Esse ponteiro só pode ter um dono (daí o nome unique).

ptr_a.get()
Retorna o ponteiro cru (int*) para o valor armazenado.

static_cast<const void*>(ptr_a.get())
Converte o ponteiro para void* para que o cout exiba o endereço de memória em hexadecimal, e não tente interpretar como número inteiro.

Saída (std::cout)
Vai imprimir algo como:*/