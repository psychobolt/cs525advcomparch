// To compile:
// ~/simplescalar/bin/sslittle-na-sstrix-gcc quicksort.c lib/mt19937-64/mt19937-64.c -I/usr/include -o bin/quicksort
//
// Running this program require parameters
// See usage by running program wihout parameters
// ./bin/quicksort test
// or
// ./bin/quicksort n # where n the random array size

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include "lib/mt19937-64/mt64.h"

void quick_sort (int64_t *a, int n) {
	int64_t i, j, p, t;
	if (n < 2)
		return;
	p = a[n / 2];
	for (i = 0, j = n - 1;; i++, j--) {
		while(a[i] < p)
			i++;
		while(p < a[j])
			j--;
		if (i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	quick_sort(a, i);
	quick_sort(a + i, n - i);
}

void test() {
	int64_t a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
  int n = sizeof a / sizeof a[0];
  int64_t i;
  for (i = 0; i < n; i++)
		printf("%" PRId64 "%s", a[i], i == n - 1 ? "\n" : " ");
	quick_sort(a, n);
	for (i = 0; i < n; i++)
		printf("%" PRId64 "%s", a[i], i == n - 1 ? "\n" : " ");
}

void run(int n) {
	int64_t* a = malloc(n * sizeof(int64_t));
	int i;
  for (i = 0; i < n; i++) {
  	a[i] = genrand64_int63();
	}
	quick_sort(a, n);
	free(a);
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
