/***** Z Function ******/

vector<int> buildZFunc(const string& s)
{
  int n = s.length();
  int l = 0, r = 0;
  vector<int> z(n, 0);
  for(int i = 1; i < n; i++)
  {
    if (i <= r)
      z[i] = min(z[i - l], r - i);
    while (s[i + z[i]] == s[z[i]])
      z[i]++;
    if (z[i] > r)
    {
      l = i;
      r = z[i];
    }
  }
  return z;
}

/***** Z Function ******/
