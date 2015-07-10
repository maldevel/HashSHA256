#include "HashSHA256.h"

int HashSHA256(unsigned char *hashed, const unsigned char *plain, unsigned int plen){
	if (hashed == NULL || plain == NULL || plen <= 0) return 0;

	EVP_MD_CTX *mdctx;
	int md_len = 0;

	if (!(mdctx = EVP_MD_CTX_create())) return 0;

	if (1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL)) {
		if (mdctx) EVP_MD_CTX_destroy(mdctx);
		return 0;
	}

	if (1 != EVP_DigestUpdate(mdctx, plain, plen)) {
		if (mdctx) EVP_MD_CTX_destroy(mdctx);
		return 0;
	}

	if (1 != EVP_DigestFinal_ex(mdctx, hashed, &md_len)) {
		if (mdctx) EVP_MD_CTX_destroy(mdctx);
		return 0;
	}

	if (mdctx) EVP_MD_CTX_destroy(mdctx);

	return md_len;
}
