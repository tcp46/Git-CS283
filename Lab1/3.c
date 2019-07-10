#include <stdio.h>
#include <stdlib.h>

//Bubble Sort
//Based off of Professor Boady CS260 Lecture sudo code
void sort(int* a, int size) {
  int i;
  int swapped = 0;
  while (swapped == 0) {
    swapped = 1;
    for (i = 1; i < size; i++) {
      if (*(a + i - 1) > *(a + i)) {
			//set a temp to hold the value at one location
			int temp = *(a + i);
			*(a + i) = *(a + i - 1);
			*(a + i - 1) = temp;
			//keep swapped at zero to continue checking values
			swapped = 0;
      }
    }
  }
}

int main() {
	//Example Array
	int size = 5;
	int a[] = {14, 3, 7, 10, 8};
	int i;
	printf("Unsorted List:\n");
	for (i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	sort(a, size);
	printf("Sorted List:\n");
	for (i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
