#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint32_t count_ways(uint32_t *vals, uint32_t N, uint32_t target) {
  uint32_t ways[target + 1];

  memset(ways, 0, sizeof(ways));
  ways[0] = 1;

  uint32_t i, j;
  uint32_t n_ways;

  for (i = 1; i < target + 1; i++) {
    n_ways = 0;
    for (j = 0; j < N; j++) {
      if((vals[j] <= i) && ways[(i-vals[j])]){
        n_ways += ways[(i - vals[j])];
      }
    }
    ways[i] = n_ways;
  }
  return ways[target];
}

#define NELMS(x) sizeof(x)/sizeof(x[0])

int main (void) {
  uint32_t vals[] = {2, 3, 7};

  uint32_t c, t;

  t = 12;
  c = count_ways(vals, NELMS(vals), t);
  printf("target:%d c=%d\n", t, c);

  return 0;
}
