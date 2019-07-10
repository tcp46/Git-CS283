#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Array {
  int* array;
  int size;
} Array;

void buildArray(Array* a, int n) {
  a->array = (int*) malloc(sizeof(int) * n);
  a->size = n;
}

void add(Array* a, int element) {
  a->size++;
  a->array = realloc(a->array, (a->size) * sizeof(int));
  a->array[a->size-1] = element;
}

void addDouble(Array* a, int element) {
	if (a->size == 0) {
		a->size++;
		a->array = realloc(a->array, (a->size) * sizeof(int));
		a->array[a->size-1] = element;
  	} else {
		int temp = a->size;
		a->size = temp * 2;
		a->array = realloc(a->array, ((a->size) * sizeof(int)));
		a->array[a->size - 1] = element;
  	}		
}	

int get(Array* a, int index) {
  if (index < a->size && index >= 0) {
    return a->array[index];
  } else {
    return -1;
  }
}

int removeAtIndex(Array* a, int index) {
  int i;
  if (index == (a->size - 1)) {
    a->size--;
    a->array = realloc(a->array, (a->size) * sizeof(int));
  } else {
    for (i = index; i < (a->size - 1); i++) {
      a->array[i] = a->array[i + 1];
    }
    a->size--;
    a->array = realloc(a->array, (a->size) * sizeof(int));
  }
}

void main() {
	double start;
  	double stop;
  	
  	Array *a = (Array*) malloc(sizeof(Array));
  	buildArray(a, 0);
  	Array *b = (Array*) malloc(sizeof(Array));
  	buildArray(b, 0);
  	
	int i;
  
  	printf("Add 10 elements to an Array.\n");
  	printf("Each element has a value equal to it's index.\n");
  	start = clock();
  	for (i = 0; i< 10000; i++) {
		add(a, i);
  	}
  	stop = clock();
  	printf("%10.2f", stop - start);
  
  	printf("\n");
  
 	printf("Add 10 elements to an Array.\n");
  	printf("With each element the size of the array doubles.\n");
  	start = clock();
  	for(i = 0; i < 10000; i++) {
		addDouble(b, i);
  	}
  	stop = clock();
  	printf("%10.2f", stop - start);

	printf("\n");
}
