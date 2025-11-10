#include <iostream>
#include <new> // Necessário para std::nothrow

int main()
{
    int *ptr_a = new (std::nothrow) int;
    if (ptr_a == nullptr)
    {
        std::cerr << "Memória insuficiente!\n";
        return 1;
    }

    std::cout << "Endereço de ptr_a: " << static_cast<const void *>(ptr_a) << "\n";

    *ptr_a = 90;
    std::cout << "Conteúdo: " << *ptr_a << "\n";

    delete ptr_a;
    ptr_a = nullptr; // Corrigido de "mullptr" para "nullptr"
}
