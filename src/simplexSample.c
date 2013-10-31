#include "har.h"

#include <stdlib.h>

int hitandrun_doubleAsc(void const *_a, void const *_b) {
	double d = *(double *)_a - *(double *)_b;
	return d > 0 ? 1 : (d < 0 ? -1 : 0);
}

int hitandrun_doubleDesc(void const *_a, void const *_b) {
	double d = *(double *)_b - *(double *)_a;
	return d > 0 ? 1 : (d < 0 ? -1 : 0);
}

void hitandrun_simplexSample(int *_n, int *_sort, int *_niter, double *_result) {
	int const n = *_n, niter = *_niter, sort = *_sort;
	Matrix result = { _result, niter, n };

	double x[n + 1];

	GetRNGstate(); // enable use of RNGs

	for (int i = 0; i < niter; ++i) {
		x[0] = 0.0; x[n] = 1.0;
		for (int j = 1; j < n; ++j) {
			x[j] = unif_rand();
		}
		qsort(x + 1, n - 1, sizeof(double), hitandrun_doubleAsc);
		for (int j = 0; j < n; ++j) {
			x[j] = x[j + 1] - x[j];
		}
		if (sort) {
			qsort(x, n, sizeof(double), hitandrun_doubleDesc);
		}
		writeRow(&result, i, x);
	}

	PutRNGstate();
}
