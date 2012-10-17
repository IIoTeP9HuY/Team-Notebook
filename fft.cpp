/*********  FFT  ************/

const int MAXN = 100000;
const double pi = acos(-1.0);

struct complex
{
  complex(double x = 0.0, double y = 0.0) : x(x), y(y) {}
  double x, y;
};

complex operator+ (const complex& c1, const complex& c2)
{
  return complex(c1.x + c2.x, c1.y + c2.y);
}
complex operator- (const complex& c1, const complex& c2)
{
  return complex(c1.x - c2.x, c1.y - c2.y);
}
complex operator* (const complex& c1, const complex& c2)
{
  return complex(c1.x * c2.x - c1.y * c2.y, c1.x * c2.y + c1.y * c2.x);
}

int rev[MAXN];

void buildRev(int length)
{
  rev[0] = 0;
  for (int i = 1; i < length; i <<= 1)
  {
    for (int j = 0; j < i; ++j)
    {
      rev[j] = rev[j] * 2;
      rev[j + i] = rev[j] + 1;
    }
  }
}

void fft(complex* array, int length, bool invert)
{
  buildRev(length);
  for (int i = 0; i < length; ++i)
    if (i > rev[i])
      std::swap(array[i], array[rev[i]]);

  for (int bSize = 2; bSize <= length; bSize <<= 1)
  {
    double arg = (2 * pi / bSize) * (invert ? -1 : 1);
    complex wn(cos(arg), sin(arg));
    for (int start = 0; start < length; start += bSize)
    {
      complex w(1.0, 0);
      for (int pos = 0; pos < bSize / 2; ++pos)
      {
        complex u = array[start + pos];
        complex v = array[start + pos + bSize / 2] * w;
        array[start + pos] = u + v;
        array[start + pos + bSize / 2] = u - v;
        w = w * wn;
      }
    }
  }
  if (invert)
    for (int i = 0; i < length; ++i)
      array[i] = array[i] * (1.0 / length);
}

std::vector<int> mult(std::vector<int> v1, std::vector<int> v2)
{
  int length = 1;
  while (length < std::max(v1.size(), v2.size()))
    length <<= 1;
  length <<= 1;

  complex* a = new complex[length];
  complex* b = new complex[length];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  std::copy(v1.begin(), v1.end(), a);
  std::copy(v2.begin(), v2.end(), b);

  fft(a, length, 0);
  fft(b, length, 0);
  for (int i = 0; i < length; ++i)
    a[i] = a[i] * b[i];

  fft(a, length, 1);

  std::vector<int> result;
  int carry = 0;
  for (int i = 0; i < length; ++i)
  {
    carry += int(a[i].x + 0.5);
    result.push_back(carry%10);
    carry /= 10;
  }
  while (carry)
  {
    result.push_back(carry%10);
    carry /= 10;
  }
  while (!result.empty() && result.back() == 0)
    result.pop_back();
  return result;
}

/*********  FFT  ************/
