#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(time(NULL)); // inicializa a semente aleatória

    int numeroGerado = rand() % 10 + 1; // número entre 1 e 10
    int chute = 0;

    while (chute != numeroGerado)
    {
        cout << "Digite um numero de 1 a 10. ";
        cin >> chute;

        if (chute == numeroGerado)
        {
            cout << "Acertou!!" << endl;
        }
        else
        {
            cout << "Errooouuu!!" << endl;
        }
    }

    return 0;
}