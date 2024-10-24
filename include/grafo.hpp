#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
using namespace std;

class Grafo {
private:
    int V; 
    vector<vector<int>> adj; 
    vector<int> tempoDescoberta; 
    vector<int> tempoTermino; 
    int tempo; 

public:
    Grafo(int V);
    void adicionaAresta(int v, int w);
    void ordenaAdjacencias();
    void DFS(int v, int x);
    void iniciaDFS(int verticeInicial);
};

#endif
