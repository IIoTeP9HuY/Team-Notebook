/**** Suffix array ****/

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DB(x) cout << #x << " : " << x << endl;

using namespace std;

const int MAXN = 1000099;
const int alpha = 150;

char str[MAXN];
int p[MAXN];
int n;

int cnt[MAXN];
int classCnt;
int c[MAXN];
int cn[MAXN];
int pn[MAXN];

void buildSuffArr()
{
  memset(cnt, 0, sizeof(cnt));
  REP(i, n)
  {
    cnt[str[i] + 1]++; 
  }
  for(int i = 1; i < alpha; i++)
    cnt[i] += cnt[i - 1];

  REP(i, n)
  {
    p[ cnt[str[i]] ] = i;
    cnt[str[i]]++;
  }

  classCnt = 1;
  c[0] = 0;
  for(int i = 1; i < n; i++)
  {
    if (str[p[i]] != str[p[i - 1]])
      classCnt++;
    c[p[i]] = classCnt - 1;
  }
  memset(cnt, 0, sizeof(cnt));
  for(int k = 1; k < n; k <<= 1)
  {
    REP(i, n)
    {
      pn[i] = p[i] - k;
      if (pn[i] < 0)
        pn[i] += n;
    }

    REP(i, n)
    {
      cnt[ c[i] + 1 ]++;
    }

    FOR(i, 1, n - 1)
    {
      cnt[i] += cnt[i - 1];
    }

    REP(i, n)
    {
      p[ cnt[ c[pn[i]] ]++ ] = pn[i];
    }

    classCnt = 1;
    cn[p[0]] = 0;
    FOR(i, 1, n - 1)
    {
      if ((c[p[i]] != c[p[i - 1]]) || 
          (c[p[i]] == c[p[i - 1]] 
          && (c[(p[i] + k) % n] != c[(p[i - 1] + k) % n])))
        classCnt++;
      cn[p[i]] = classCnt - 1; 
    }

    REP(i, n)
      c[i] = cn[i];

    memset(cnt, 0, sizeof(cnt));
  }
}

int lcp[MAXN];
int bp[MAXN];

void buildLCP()
{
  REP(i, n)
    bp[p[i]] = i;
  int len = 0;
  int cur = bp[0];
  REP(i, n)
  {
    int c1 = p[cur];
    int c2 = p[(cur + 1) % n];
    while (c1 + len < n && c2 + len < n && str[c1 + len] == str[c2 + len])
      len++;
    lcp[cur] = len;
    len = max(0, len - 1);
    cur = bp[i + 1];
  }
}

void printSorted()
{
  REP(i, n)
  {
    FOR(j, p[i], n - 1)
      printf("%c", str[j]);
    printf("\n");
  }
}
