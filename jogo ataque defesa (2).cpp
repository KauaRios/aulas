#include <iostream>
#include <string>
using namespace std;

int main() {
    int jogarNovamente = 1;

    while (jogarNovamente == 1) {

        string nome, defnome;
        int ataque=0, poder=0, escudo=0;
        float vida = 0;
        int continuar = 1;

        cout << "Bem-vindo ao jogo de ataque e defesa!" << endl;

        cout << "Digite o nome do personagem: ";
        cin >> nome;

        cout << "Insira o nome do defensor: ";
        cin >> defnome;

        cout << "Insira o poder de ataque: ";
        cin >> ataque;

        cout << "Insira a vida do defensor: ";
        cin >> vida;

        cout << "Insira o poder de defesa: ";
        cin >> poder;

        do {
            cout << "O personagem tem escudo? Digite apenas 1 para sim ou 0 para nao: ";
            cin >> escudo;

            while (escudo != 1 && escudo != 0) {
                cout << "Valor inválido! Digite apenas 1 para sim ou 0 para nao: ";
                cin >> escudo;
            }

            if (escudo == 1) {
                cout << "O personagem tem escudo!" << endl;
            } else {
                cout << "O personagem não tem escudo!" << endl;
            }

            cout << "A vida do defensor " << defnome << " agora é: " << vida << endl;

            int dano = 0;

            if (ataque > poder && escudo == 1) {
                dano = ataque - poder;
                cout << "O personagem " << nome << " atacou " << defnome << " e causou " << dano << " de dano" << endl;
                vida -= dano;
            } else if (ataque > poder && escudo == 0) {
                dano = (ataque - poder) / 2;
                cout << "O personagem " << nome << " atacou " << defnome << " e causou " << dano << " de dano" << endl;
                vida -= dano;
            } else {
                cout << "O personagem " << nome << " atacou " << defnome << " e causou 0 de dano" << endl;
            }

            cout << "A vida do defensor " << defnome << " agora é: " << vida << endl;

            if (vida <= 0) {
                cout << "O defensor " << defnome << " foi derrotado!" << endl;
                break;
            }

            cout << "Deseja continuar atacando? 1 para sim e 0 para nao: ";
            cin >> continuar;

        } while (continuar == 1 && vida > 0);

        cout << "Fim do jogo!" << endl;

        cout << "Deseja jogar novamente? 1 para sim e 0 para nao: ";
        cin >> jogarNovamente;
    }

    cout << "Obrigado por jogar!" << endl;

    return 0;
}
