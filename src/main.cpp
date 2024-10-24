#include "grafo.hpp"

#include <chrono>

using namespace std;

int main() {
    Grafo g(0);
    int origem, destino;

    g.carregarDeArquivo("bipartido2000.txt", origem, destino);

    auto inicio = chrono::high_resolution_clock::now();
    int fluxo = g.fluxoMaximo(origem, destino);
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double> duracao = fim - inicio;


    cout << "Fluxo máximo: " << fluxo << endl;
    cout << "Tempo de execução: " << duracao.count() << " segundos." << endl;

    return 0;
}