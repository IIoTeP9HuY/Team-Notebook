/********* Treap *********/

struct Node
{
  Node(int prior, int l, int r): prior(prior), l(l), r(r)
  {
    cnt = prior = 0;
  }
  Node() 
  { 
    l = r = cnt = prior = info = 0;
  }
  int prior, cnt, info;
  int l, r;
};

Node node[100];
int lastNode = 1;

int getNode()
{
  return lastNode++;
}

int getCnt(int t)
{
  return t ? node[t].cnt : 0;
}

void recalc(int t)
{
  node[t].cnt = (t != 0) + getCnt(node[t].l) + getCnt(node[t].r);
}

int merge(int l, int r)
{
  if (!l || !r)
    return l + r;
  
  int t = 0;
  if (node[l].prior > node[r].prior)
  {
    node[l].r = merge(node[l].r, r);
    t = l;
  }
  else
  {
    node[r].l = merge(l, node[r].l);
    t = r;
  }
  recalc(l);
  recalc(r);
  return t;
}

void split(int t, int key, int& l, int& r)
{
  if (!t)
  {
    l = r = 0;
    return;
  }
  int cnt = getCnt(node[t].l);
  if (cnt >= key)
  {
    split(node[t].l, key, l, node[t].l);
    r = t;
  }
  else
  {
    split(node[t].r, key - cnt - 1, node[t].r, r);
    l = t;
  }
  recalc(l);
  recalc(r);
}

void print(int t)
{
  if (t)
  {
    assert(node[t].prior >= node[node[t].l].prior);
    assert(node[t].prior >= node[node[t].r].prior);

    print(node[t].l);
    printf("%d ", node[t].info);
    print(node[t].r);
  }
}

/********* Treap *********/
