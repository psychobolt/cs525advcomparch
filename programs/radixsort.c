// To compile:
// ~/simplescalar/bin/sslittle-na-sstrix-gcc radixsort.c -I/usr/include -o bin/radixsort
// Ignore warnings
//
// Running this program require parameters
// See usage by running program wihout parameters
// ./bin/radixsort test
// or
// ./bin/radixsort n # where n the random array size

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define swap(a, b) {tmp = a; a = b; b = tmp;}
#define each(i, x) for (i = 0; i < x; i++)

/* sort unsigned ints */
static void rad_sort_u(uint *from, uint *to, uint bit) {
  uint *ll = from, *rr = to - 1, tmp;

  if (!bit || to < from + 1) {
    return;
  }
  while (1) {
    /* find left most with bit, and right most without bit, swap */
      while(ll < rr && !(*ll & bit)) ll++;
      while(ll < rr && (*rr & bit)) rr--;
      if (ll >= rr) break;
      swap(*ll, *rr);
  }

  if (!(bit & *ll) && ll < to) ll++;
  bit >>= 1;

  rad_sort_u(from, ll, bit);
  rad_sort_u(ll, to, bit);
}

/* sort signed ints: flip highest bit, sort as unsigned, flip back */
static void radix_sort(int *a, const size_t len) {
  size_t i;
  uint *x = (uint*) a;

  each(i, len) x[i] ^= INT_MIN;
  rad_sort_u(x, x + len, INT_MIN);
  each(i, len) x[i] ^= INT_MIN;
}

static inline void radix_sort_unsigned(uint *a, const size_t len) {
  rad_sort_u(a, a + len, (uint) INT_MIN);
}

void test() {
    int len = 16, x[16], i;
    each(i, len) x[i] = rand() % 512 - 256;
    each(i, len) printf("%d%c", x[i], i + 1 < len ? ' ' : '\n');

    radix_sort(x, len);

    each(i, len) printf("%d%c", x[i], i + 1 < len ? ' ' : '\n');
}

void run(int len) {
  int x[len], i;

  each(i, len) x[i] = rand() % 512 - 256;
  radix_sort(x, len);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
		printf("Usage: %s n #where n the random array size or a string 'test' without quotes\n", argv[0]);
		return 1;
	}
	if (strcmp(argv[1], "test") == 0) {
		test();
	} else {
  	run(atoi(argv[1]));
	}
  return 0;
}
