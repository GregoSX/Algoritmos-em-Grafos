#include<iostream>
#include <list>

using namespace std;

void numeroDeCaminhosAux(list<int> *adj, int u, int v, bool visited[],int caminhos[], int &indice, int &cont);

int numeroDeCaminhos(list<int> *adj, int s, int v, int n);

int main() 
{
	int n, resultado = 0;
	cin >> n;
	list<int> *adj = new list<int>[n+1];
	int *grauSaida = new int [n+1];
	
	for (int i = 1; i <= n; i++) {
		grauSaida[i] = 0;
	}
	
	int u, v;
    bool verifica = false;
	cin >> u >> v;
	while (u != -1 and v != -1) {
		adj[u].push_back(v);
		grauSaida[u]++;
		cin >> u >> v;
        verifica = true;
	}
    
    for (int i = 1; i <= n and verifica; i++) {
		if (grauSaida[i] == 0) {
			resultado += numeroDeCaminhos(adj, 1, i, n);
		}
	}
	
	cout << resultado << endl;
    
    return 0;
}

int numeroDeCaminhos(list<int> *adj, int s, int v, int n) {
    int cont = 0;
    bool *visitado = new bool[n+1];

    int *caminhos = new int[n+1];
    int indice = 0; 

    for (int i = 1; i <= n; i++)
        visitado[i] = false;

    numeroDeCaminhosAux(adj, s, v, visitado, caminhos, indice, cont);
    
    return cont;
}

void numeroDeCaminhosAux(list<int> *adj,int u, int v, bool visitado[],int caminhos[], int &indice, int &cont) {
    visitado[u] = true;
    caminhos[indice] = u;
    indice++;

    if (u == v) {
        cont++;
    }
    else { 
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visitado[*i])
                numeroDeCaminhosAux(adj, *i, v, visitado, caminhos, indice, cont);
    }

    indice--;
    visitado[u] = false;
}