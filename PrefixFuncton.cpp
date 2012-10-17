/***** Prefix Function ******/

vector<int> buildPFunc(const string& s)
{
  int n = s.length();
  vector<int> p(n, 0);
  int k = 0;
  for(int i = 1; i < n; i++)
  {
    while (k > 0 && s[i] != s[k]) k = p[k - 1];
    if (s[i] == s[k])
      k++;
    p[i] = k;
  }
  return p;
}

/***** Prefix Function ******/
