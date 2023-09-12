#include <assert.h>

#define N 5
unsigned char queens[N];

int abs(int x)
{
  return x >= 0 ? x: -x;
}

int attack()
{
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      if ((queens[i] == queens[j]) ||
          (abs(queens[i] - queens[j]) == j - i)) {
        return 1;
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[])
{
  int i;
  tis_make_unknown(queens[0], sizeof(queens[0]) * N);
  for (i = 0; i < N; i++) {
    queens[i] %= N;
  }
  int ret = attack();
  /* @assert ret == 0 */
  return 0;
}
