#ifndef HASH256_H_
#define HASH256_H_

#include <openssl/evp.h>

int HashSHA256(unsigned char *hashed, const unsigned char *plain, unsigned int plen);


#endif
