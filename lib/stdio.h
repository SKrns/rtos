#ifndef LIB_STDIO_H_
#define LIB_STDIO_H_

typedef enum utoa_t
{
	utoa_dec = 10,
	utoa_hex = 16,
} utoa_t;

uint32_t putstr(const char* s);
uint32_t putint(const);
uint32_t utoa(char* buf, uint32_t val, utoa_t base);

#endif /* LIB_STDIO_H_ */