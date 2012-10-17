#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <vector>

#define pb push_back
#define mp make_pair

using namespace std;

const int inf = 1000000000;
const int MAXN = 5009;

struct Edge
{
  Edge(int to, int cap, int rev) : to(to), cap(cap), flow(0), rev(rev)
  {
  }

  int to, cap, flow, rev;
};

vector<Edge> G[MAXN];
int lastEdge[MAXN];
int dist[MAXN];
int S, T;
int n, m;

int q[MAXN], hd, tl;

void addEdge(int from, int to, int cap)
{
  G[from].pb(Edge(to, cap, G[to].size()));
  G[to].pb(Edge(from, 0, G[from].size() - 1));
}

int dinic(int v, int minEdge)
{
  if (!minEdge)
    return 0;

  if (v == T)
    return minEdge;

  for (; lastEdge[v] < G[v].size(); ++lastEdge[v])
  {
    int i = lastEdge[v];
    int to = G[v][i].to;
    int cap = G[v][i].cap;
    int flow = G[v][i].flow;

    if (dist[to] != dist[v] + 1)
      continue;

    if (int f = dinic(to, min(minEdge, cap - flow)))
    {
      G[v][i].flow += f;
      G[to][G[v][i].rev].flow -= f;
      return f;
    }
  }
  return 0;
}

bool buildResidualNetwork(int S)
{
  memset(dist, -1, n * sizeof(int));
  dist[S] = 0;

  hd = tl = 0;
  q[hd++] = S;

  while (tl < hd)
  {
    int v = q[tl++];

    for (int i = 0; i < G[v].size(); ++i)
    {
      int to = G[v][i].to;
      if (G[v][i].cap > G[v][i].flow && dist[to] == -1)
      {
        dist[to] = dist[v] + 1;
        q[hd++] = to;
        if (to == T)
          return;
      }
    }
  }
  return (dist[T] != -1);
}

long long findMaxFlow(int S)
{
  long long flow = 0;
  while (buildResidualNetwork(S))
  {
    memset(lastEdge, 0, n * sizeof(int));

    while (int f = dinic(S, inf))
      flow += f;
  }
  return flow;
}
