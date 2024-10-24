#include "grafo.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string filename;
    int x;
    cin >> filename >> x;

    ifstream arquivo(filename);

    int u, v;
    int maxVertice = -1; 
    vector<pair<int, int>> arestas; 

    while (arquivo >> u >> v) {
        arestas.push_back({u, v});
        maxVertice = max(maxVertice, max(u, v));
    }

    Grafo G(maxVertice + 1);

    for (const auto& aresta : arestas) {
        G.adicionaAresta(aresta.first, aresta.second);
    }

    G.iniciaDFS(x);

    return 0;
}
