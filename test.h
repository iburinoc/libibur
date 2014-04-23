#ifndef LIBIBUR_TEST_H
#define LIBIBUR_TEST_H

/**
 * A set of functions to facilitate testing
 * Header for test.c
 */

/**
 * A set of functions to facilitate testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <libibur/util.h>

static inline void assert_equals(const void* const _a, const void* const _b, int len, const char* const message) {
	uint8_t* a = (uint8_t*) _a;
	uint8_t* b = (uint8_t*) _b;
	for(int i = 0; i < len; i++) {
		if(a[i] != b[i]) {
			printf("%s failed\n", message);
			printbuf(a, len);
			printbuf(b, len);
			exit(-1);
		}
	}
}

#endif
