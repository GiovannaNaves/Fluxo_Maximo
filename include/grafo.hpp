#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <climits>
#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;

class Grafo {
private:
    int V; 
    vector<vector<int>> capacidade; 
    vector<int> tempoDescoberta; 
    bool bfs(int s, int t, vector<int>& parent);

public:
    Grafo(int V);
    void adicionarAresta(int u, int v, int cap);
    int fluxoMaximo(int s, int t);
    void carregarDeArquivo(const string& nomeArquivo, int& origem, int& destino);
};

#endif
