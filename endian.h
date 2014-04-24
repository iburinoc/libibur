#ifndef LIBIBUR_ENDIAN_H
#define LIBIBUR_ENDIAN_H

#include <stdint.h>

static inline void     encle64(uint64_t n, void* _b);
static inline uint64_t decle64(void* _b);
static inline void     encbe64(uint64_t n, void* _b);
static inline uint64_t decbe64(void* _b);

static inline void     encle32(uint32_t n, void* _b);
static inline uint32_t decle32(void* _b);
static inline void     encbe32(uint32_t n, void* _b);
static inline uint32_t decbe32(void* _b);

static inline void     encle64(uint64_t n, void* _b) {
	uint8_t* b = (uint8_t*) _b;
	b[0] = (n >>  0) & 0xff;
	b[1] = (n >>  8) & 0xff;
	b[2] = (n >> 16) & 0xff;
	b[3] = (n >> 24) & 0xff;
	b[4] = (n >> 32) & 0xff;
	b[5] = (n >> 40) & 0xff;
	b[6] = (n >> 48) & 0xff;
	b[7] = (n >> 56) & 0xff;
}

static inline uint64_t decle64(void* _b) {
	uint8_t* b = (uint8_t*) _b;
	uint64_t n = 0;
	n |= ((uint64_t) b[0]) <<  0;
	n |= ((uint64_t) b[1]) <<  8;
	n |= ((uint64_t) b[2]) << 16;
	n |= ((uint64_t) b[3]) << 24;
	n |= ((uint64_t) b[4]) << 32;
	n |= ((uint64_t) b[5]) << 40;
	n |= ((uint64_t) b[6]) << 48;
	n |= ((uint64_t) b[7]) << 56;
	return n;
}

static inline void     encbe64(uint64_t n, void* _b) {
	uint8_t* b = (uint8_t*) _b;
	b[7] = (n >>  0) & 0xff;
	b[6] = (n >>  8) & 0xff;
	b[5] = (n >> 16) & 0xff;
	b[4] = (n >> 24) & 0xff;
	b[3] = (n >> 32) & 0xff;
	b[2] = (n >> 40) & 0xff;
	b[1] = (n >> 48) & 0xff;
	b[0] = (n >> 56) & 0xff;
}

static inline uint64_t decbe64(void* _b) {
	uint8_t* b = (uint8_t*) _b;
	uint64_t n = 0;
	n |= ((uint64_t) b[7]) <<  0;
	n |= ((uint64_t) b[6]) <<  8;
	n |= ((uint64_t) b[5]) << 16;
	n |= ((uint64_t) b[4]) << 24;
	n |= ((uint64_t) b[3]) << 32;
	n |= ((uint64_t) b[2]) << 40;
	n |= ((uint64_t) b[1]) << 48;
	n |= ((uint64_t) b[0]) << 56;
	return n;
}

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

static inline void     encbe32(uint32_t n, void* _b) {
	uint8_t* b = (uint8_t*) _b;
	b[3] = (n >>  0) & 0xff;
	b[2] = (n >>  8) & 0xff;
	b[1] = (n >> 16) & 0xff;
	b[0] = (n >> 24) & 0xff;
}

static inline uint32_t decbe32(void* _b) {
	uint8_t* b = (uint8_t*) _b;
	uint32_t n = 0;
	n |= ((uint32_t) b[3]) <<  0;
	n |= ((uint32_t) b[2]) <<  8;
	n |= ((uint32_t) b[1]) << 16;
	n |= ((uint32_t) b[0]) << 24;
	return n;
}

#endif
