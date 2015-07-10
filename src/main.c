#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#include "HashSHA256.h"

//To compile the following code you have to link OpenSSL libeay32.lib with your project.

int main(void){
	unsigned char *text = "Hello, World!\0";
	unsigned char hashed[EVP_MAX_MD_SIZE] = { 0 };
	int i = 0, len = 0;

	if ((len = HashSHA256(hashed, text, strlen(text))) > 0){
		printf("Hash value: ");
		for (i = 0; i < len; i++)
			printf("%02x", hashed[i]);
		printf("\n");
	}

	return EXIT_SUCCESS;
}
