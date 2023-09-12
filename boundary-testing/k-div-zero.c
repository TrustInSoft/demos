
int f(int x)
{
  return 1/(x*x - 2*x + 1);
}

int main(int argc, char *argv[])
{
  int x;
  klee_make_symbolic(&x, sizeof x, "x");
  return f(x);
}
