#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 99

int main(void) {

	srand(time(NULL));

	FILE* out = fopen("numbers.txt", "w");

	if(out == NULL) {
		fprintf(stderr, "Cannot create file");
		exit(1);
	}

	for(int i = 0; i < 100; i++) {
		fprintf(out, "%d\n", rand() % (MAX - MIN +1) + MIN);
	}

	fclose(out);

	printf("Successfully created numbers.txt\n");

	return 0;
}
