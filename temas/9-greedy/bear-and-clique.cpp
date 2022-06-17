/**
 * @file bear-and-clique.cpp
 * @author Humberto Alejandro Ortega Alcocer (humbertoalejandroortegalcocer@gmail.com)
 * @brief Solución al problema. Bear and Clique (https://www.codechef.com/APRIL17/problems/CLIQUED/)
 * @version 0.1
 * @date 2022-06-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
#include <set>
#include <limits>
using namespace std;

#define infinito 1000000000000000
typedef int ll;
typedef pair<int, int> esPar;

// Clase para representar un grafo.
class Grafo
{
  ll V;
  vector<pair<int, int>> *arr;

public:
  Grafo(ll vertices)
  {
    V = vertices;
    arr = new vector<esPar>[vertices];
  }
  void addEdge(int u, int v, ll w)
  {
    arr[u].push_back(make_pair(v, w));
    arr[v].push_back(make_pair(u, w));
  }
  void shortestPath(int src, int k, int x)
  {

    // set<esPar> s;
    priority_queue<esPar, vector<esPar>, greater<esPar>> pq;

    // const int infinito = 2000000000;
    // long long int infinito = 100000000100001;

    // vector<bool> visited;
    vector<long long int> dist;
    for (ll i = 0; i <= V; i++)
    {
      dist.push_back(infinito);
      // visited.push_back(false);
    }
    long long int prev = infinito;
    // s.insert(make_pair(0,src));
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
      // int u = (*s.begin()).second;
      ll u = pq.top().second;
      // s.erase(s.begin());
      pq.pop();

      if (u <= k && prev > dist[u])
      {
        // cout<<" x";
        int v, pos = 0;
        ll weight;

        for (int i = 1; i <= k + arr[u].size(); i++)
        {
          if (i == u)
          {
            continue;
          }
          if (i != u && i <= k)
          {
            v = i;
            weight = x; // arr[u][0].second;
          }
          if (i > k)
          {
            v = arr[u][pos].first;
            weight = arr[u][pos++].second;
          }
          if (dist[v] > dist[u] + weight)
          {
            dist[v] = dist[u] + weight;
            // s.insert(make_pair(dist[v], v));
            // if(v <= k){
            prev = min(prev, dist[v]);
            //}
            pq.push(make_pair(dist[v], v));
          }
        }
      }
      else
      {
        vector<esPar>::iterator it;
        for (it = arr[u].begin(); it != arr[u].end(); it++)
        {
          int v = (*it).first;
          ll weight = (*it).second;

          if (dist[v] > dist[u] + weight)
          {
            dist[v] = dist[u] + weight;
            // s.insert(make_pair(dist[v], v));
            pq.push(make_pair(dist[v], v));
          }
          //	prev = dist[u];
        }
      }
    }
    for (int i = 1; i < V; i++)
    {
      printf("%lld ", dist[i]);
    }
  }
};

int main()
{
  int t, n, k, m, s;
  int i, j, a, b;
  ll x, c;

  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d %d %d", &n, &k, &x, &m, &s);
    Grafo g(n + 1);
    for (i = 0; i < m; i++)
    {
      scanf("%d %d %d", &a, &b, &c);
      g.addEdge(a, b, c);
    }
    g.shortestPath(s, k, x);
    cout << endl;
  }
  return 0;
}