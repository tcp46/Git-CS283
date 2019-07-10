#include <stdlib.h>
#include <stdio.h>

//Create a new data structure ListNode
struct ListNode {
  int value;
  struct ListNode* next;
  //struct ListNode* prev;
};

//swap takes in two pointers to ListNode objects
void swap (struct ListNode* b, struct ListNode* c) {
  int temp = b->value;
  b->value = c->value;
  c->value = temp;
}

//Bubble sort similar to Question 3
//sort takes in a pointer to the first element in the linked list
void sort(struct ListNode* first) {
	int swapped = 0;
	struct ListNode* temp;
  	struct ListNode* current = NULL;

  	//Case for if the linked list is empty
  	//Nothing to sort
  	if (first == NULL) {
		return;
  	}
 	do {
		swapped = 1;
    	temp = first;
    
    	while (temp->next != current) {
			//check to see if the value at temp is greater than the next value in temp
      	//if so call swap
      	if (temp->value > temp->next->value) {
				swap(temp, temp->next);
        		swapped = 0;
      	}
      	//essentially increment temp by setting temp to next
      	temp = temp->next;
    	}
    	current = temp;
	} while (swapped == 0);
}


void insert(struct ListNode** head, int data) {
  struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
  temp->value = data;
  temp->next = *head;
  *head = temp;
}

void printList(struct ListNode* first) {
	struct ListNode* temp = first;
	while (temp != NULL) {
		printf("%d ", temp->value);
		temp = temp->next;
	}
}

void main() {
	//Example Linked List Sorting
	int list[] = {12, 5, 7, 4, 3, 99, 10, 11, 37};
	int i;
	struct ListNode* a = NULL;
	
	for(i = 0; i < 9; i++) {
		insert(&a, list[i]);
	}

	printf("Unsorted Array: \n");
	printList(a);
	printf("\n");

	sort(a);

	printf("Sorted Array: \n");
	printList(a);
	printf("\n");
}
