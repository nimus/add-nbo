#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

	uint32_t a, b;

	FILE *f1, *f2;
	f1 = fopen(argv[1], "rb");
	f2 = fopen(argv[2], "rb");

	fread(&a, sizeof(uint32_t), 1, f1);
	fread(&b, sizeof(uint32_t), 2, f2);

	fclose(f1);
	fclose(f2);

	a = ntohl(a);
	b = ntohl(b);

	uint32_t sum = a + b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", a, a, b, b, sum, sum);
}
