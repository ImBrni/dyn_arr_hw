#include <stdio.h>
#include <stdlib.h>

#define INITIAL 10
#define MULTIPlIER 2

struct DynArray {
	int *array;
	int used;
	int size;
};

void init_DynArray(struct DynArray *a) {
	a->array = malloc(INITIAL * sizeof(int));

	if(a->array == NULL) {
		printf("DynArray initialization failed!");
		exit(1);
	}	

	a->used = 0;
	a->size = INITIAL;
}

void insert_DynArray(struct DynArray *a, int element) {
	if(a->array == NULL) {
		printf("DynArray needs to be initialized before use!");
		exit(1);
	}

	if (a->used == a->size) {
		a->size *= 2;
		a->array = realloc(a->array, a->size * sizeof(int));

		if(a->array == NULL) {
			printf("DynArray reallocation failed!");
			exit(1);
		}	

	}
	a->array[a->used++] = element;
}

void free_DynArray(struct DynArray *a) {
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}

int main(void) {

	FILE* input = fopen("numbers.txt", "r");
	if(input == NULL) {
		printf("Failed to open numbers.txt");
		exit(1);
	}

	struct DynArray data;
	init_DynArray(&data);

	int num = 0, sum = 0, count = 0;
	while(fscanf(input, "%d", &num) == 1) {
		insert_DynArray(&data, num);
		sum += num;
		count++;
	}

	printf("Average of numbers.txt: %.2lf\n", (double)sum/(double)count);

	fclose(input);
	free_DynArray(&data);

	return 0;
}
