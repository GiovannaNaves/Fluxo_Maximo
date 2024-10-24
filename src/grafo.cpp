#include "grafo.hpp"

using namespace std;

Grafo::Grafo(int V) : V(V), capacidade(V, vector<int>(V, 0)) {}

void Grafo::adicionarAresta(int u, int v, int cap) {
    capacidade[u][v] = cap;
}

bool Grafo::bfs(int s, int t, vector<int>& parent) {
    vector<bool> visitado(V, false);
    queue<int> fila;
    fila.push(s);
    visitado[s] = true;
    parent[s] = -1;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();

        for (int v = 0; v < V; v++) {
            if (!visitado[v] && capacidade[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                fila.push(v);
                parent[v] = u;
                visitado[v] = true;
            }
        }
    }
    return false;
}

int Grafo::fluxoMaximo(int s, int t) {
    int fluxoMaximo = 0;
    vector<int> parent(V);

    while (bfs(s, t, parent)) {
        int fluxoCaminho = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            fluxoCaminho = min(fluxoCaminho, capacidade[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            capacidade[u][v] -= fluxoCaminho;
            capacidade[v][u] += fluxoCaminho;
        }

        fluxoMaximo += fluxoCaminho;
    }

    return fluxoMaximo;
}

void Grafo::carregarDeArquivo(const string& nomeArquivo, int& origem, int& destino) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    arquivo >> origem >> destino;

    int numArestas;
    arquivo >> V >> numArestas;
    capacidade.resize(V, std::vector<int>(V, 0));

    int u, v, cap;
    for (int i = 0; i < numArestas; i++) {
        arquivo >> u >> v >> cap;
        adicionarAresta(u, v, cap);
    }

    arquivo.close();
}