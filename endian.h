#ifndef LIBIBUR_ENDIAN_H
#define LIBIBUR_ENDIAN_H

#include <stdint.h>

static inline void     encle32(uint32_t n, void* b);
static inline uint32_t decle32(void* b);
static inline void     encbe32(uint32_t n, void* b);
static inline uint32_t decbe32(void* b);

static inline void     encle32(uint32_t n, void* _b) {
	uint8_t* b = (uint8_t*) _b;
	b[0] = (n >>  0) & 0xff;
	b[1] = (n >>  8) & 0xff;
	b[2] = (n >> 16) & 0xff;
	b[3] = (n >> 24) & 0xff;
}

static inline uint32_t decle32(void* _b) {
	uint8_t* b = (uint8_t*) _b;
	uint32_t n = 0;
	n |= ((uint32_t) b[0]) <<  0;
	n |= ((uint32_t) b[1]) <<  8;
	n |= ((uint32_t) b[2]) << 16;
	n |= ((uint32_t) b[3]) << 24;
	return n;
}

static inline void     encbe32(uint32_t n, void* b) {
	uint8_t* b = (uint8_t*) _b;
	b[3] = (n >>  0) & 0xff;
	b[2] = (n >>  8) & 0xff;
	b[1] = (n >> 16) & 0xff;
	b[0] = (n >> 24) & 0xff;
}

static inline uint32_t decbe32(void* b) {
	uint8_t* b = (uint8_t*) _b;
	uint32_t n = 0;
	n |= ((uint32_t) b[3]) <<  0;
	n |= ((uint32_t) b[2]) <<  8;
	n |= ((uint32_t) b[1]) << 16;
	n |= ((uint32_t) b[0]) << 24;
	return n;
}

#endif
