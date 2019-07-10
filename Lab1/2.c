#include <stdlib.h>
#include <stdio.h>

int main() {
	char** words = malloc(10 * sizeof(char*));
	//create an arrary of words, an array of char* s
	for (int i = 0; i < 10; i++) {
		//allocate memory at each location in w
		words[i] = (char*)malloc(15*sizeof(char));
	}
	for (int i = 0; i < 10; i++) {
		//free every word in words
		free(a[i]);
	}
	//free words itself
	free(words);
}
