/******** Fenwick ********/

struct Fenwick
{
  int size;
  vector<int> t;
  Fenwick(int sz) { init(sz); }
  Fenwick(vector<int> v) { init(v); }
  void init(int sz)
  {
    size = sz;
    t.assign(size, 0);
  }
  void init(vector<int> v)
  {
    size = v.size();
    t = v;
  }
  void upd(int pos, int val)
  {
    for(; pos < size; pos = pos | (pos + 1))
      t[pos] += val;
  }
  int get(int pos)
  {
    int res = 0;
    for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
      res += t[pos];
    return res;
  }
  void print()
  {
    for(int i = 0; i < size; i++)
    {
      printf("%d ", get(i) - get(i - 1));
    }
    printf("\n");
  }
};

/******** Fenwick ********/
