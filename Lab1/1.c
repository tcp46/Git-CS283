#include <stdlib.h>
#include <stdio.h>

int main() {
	int* w;
	int i;
	w = malloc(10 * sizeof(int)); //create memory for an array of 10 integers
	for (i = 0; i < 10; i = i + 1) {
		w[i] = i; //set each value in w
	}
	for (i = 0; i < 10; i = i + 1) {
		printf("%d\n", w[i]); //print each value in w
	}
	free(w);
}
