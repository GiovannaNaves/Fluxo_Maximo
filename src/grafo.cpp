#include "grafo.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Grafo::Grafo(int V) {
    this->V = V;
    adj.resize(V);
    tempoDescoberta.resize(V, 0);
    tempoTermino.resize(V, 0);
    tempo = 0;
}

void Grafo::adicionaAresta(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Grafo::ordenaAdjacencias() {
    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
}

void Grafo::DFS(int v, int x) {
    tempo++;
    tempoDescoberta[v] = tempo;

    for (int u : adj[v]) {
        if (tempoDescoberta[u] == 0) {
            if (v == x) {
                cout << "Árvore: (" << x << ", " << u << ")"<< endl;
            }
            DFS(u, x);
        } else if (v == x) {
            if (tempoDescoberta[u] > 0 && tempoTermino[u] == 0) {
                cout << "Retorno: (" << x << ", " << u << ")"<< endl;
            } else if (tempoDescoberta[u] > tempoDescoberta[v]) {
                cout << "Avanço: (" << x << ", " << u << ")"<< endl;
            } else {
                cout << "Cruzamento: (" << x << ", " << u << ")"<< endl;
            }
        }
    }

    tempo++;
    tempoTermino[v] = tempo;
}

void Grafo::iniciaDFS(int x) {
    ordenaAdjacencias();

    for (int i = 0; i < V; i++) {
        if (tempoDescoberta[i] == 0) {
            DFS(i, x); 
        }
    }
}
