#include "grafo.hpp"

using namespace std;

int main() {
    Grafo g(0);

    g.carregarDeArquivo("grafo.txt");

    int fluxo = g.fluxoMaximo(0, 5);
    cout << "O fluxo máximo é " << fluxo << endl;

    return 0;
}