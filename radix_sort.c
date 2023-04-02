#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
}ListNode;

ListNode *newList() {
   return NULL;
}

/* empties list */
void deleteNode(ListNode** head) {
    ListNode* current = *head;
    ListNode* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

/* printList */
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}


ListNode* addNode(ListNode* l,int val) {
	ListNode *n = malloc(sizeof(ListNode));
	ListNode *p = l;
	n->data = val;
	n->next = NULL;



	if (l == NULL)
	{
		return n;
	}

	while(p->next!= NULL)
	{
		p = p->next;
	}

	p->next = n;
	return l;
}


/* insert data into linked list */
void insertNode(ListNode **head, int val){
    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->data = val;
    newNode->next = NULL;

    if(*head == NULL) {
         *head = newNode;
    }
    else
    {
        ListNode *lastNode = *head;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }
}

/* length of linked list */
int length(ListNode *head) {
    int count = 0;
    ListNode *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}


/* helper function for numberDigits */
int largest(ListNode *head) {
    int count = 0;

    while (head != NULL) {
        if (count < head-> data) {
            count = head->data;
        }
        head = head->next;

    }

    return count;
}

/* this function returns the number of passes for radix */
int numberDigits(int n) {
    int digits = 0;
    while (n != 0) {
        n = n/10;
        digits++;
    }

    return digits;
}


int getNumberIndex(int n,int index) {
	int digits = numberDigits(n), counter = 1;

	if (digits < index)
	{
		return 0;
	}

	while (counter != index)
	{
		if (counter == index)
		{
			return n%10;
		}

		n = n/10;
		counter++;
	}

	return n%10;
}


int main(int argc, char **argv) {
    int i,random,max,pass,number,digits;
    ListNode *head = NULL;
    ListNode *b0,*b1,*b2,*b3,*b4,*b5,*b6,*b7,*b8,*b9;
    int seed = atoi(argv[1]);
    int NumVals = atoi(argv[2]);
    int low = atoi(argv[3]);
    int high = atoi(argv[4]);
    srand(seed);


    /* input validation for CLA */
    if (argc != 5) {
        printf("ERROR!\n");
        exit(0);
    }



    if (seed < 0 || NumVals < 0 || low < 0 || high < 0) {
        printf("ERROR!\n");
        exit(0);
    }

    for (i = 0; i < NumVals; ++i) {
        random = (rand() % (high - low + 1)) + low;
        insertNode(&head,random);
    }
    printf("****************************************************************************\n");
    printf("List before radix sort: ");
    printList(head);
    printf("\n");
    printf("----------------------------------------------------------------------------");
    printf("\n");
    max = largest(head);
    digits = numberDigits(max);


    
    b0 = newList();
    b1 = newList();
    b2 = newList();
    b3 = newList();
    b4 = newList();
    b5 = newList();
    b6 = newList();
    b7 = newList();
    b8 = newList();
    b9 = newList();


    for (pass = 0; pass < digits; pass++) {
        ListNode *curr = head;
        printf("Sequence %d:\n",pass+1);
        while (curr != NULL) {
            number = curr->data;
            switch(getNumberIndex(number,pass+1))
            {
                case 0:
                    b0 = addNode(b0,number);
                    break;
                case 1:
                    b1 = addNode(b1,number);
                    break;
                case 2:
                    b2 = addNode(b2,number);
                    break;
                case 3:
                    b3 = addNode(b3,number);
					break;
				case 4:
					b4 = addNode(b4,number);
					break;
				case 5:
					b5 = addNode(b5,number);
					break;
				case 6:
					b6 = addNode(b6,number);
					break;
				case 7:
					b7 = addNode(b7,number);
					break;
				case 8:
					b8 = addNode(b8,number);
					break;
				case 9:
					b9 = addNode(b9,number);
					break;
				default:
					printf("ERROR\n");
					exit(0);
            }
            curr = curr->next;
        }


            printf("bucket 0: ");
            printList(b0);
            printf("\n");
            printf("bucket 1: ");
            printList(b1);
            printf("\n");
            printf("bucket 2: ");
            printList(b2);
            printf("\n");
            printf("bucket 3: ");
            printList(b3);
            printf("\n");
            printf("bucket 4: ");
            printList(b4);
            printf("\n");
            printf("bucket 5: ");
            printList(b5);
            printf("\n");
            printf("bucket 6: ");
            printList(b6);
            printf("\n");
            printf("bucket 7: ");
            printList(b7);
            printf("\n");
            printf("bucket 8: ");
            printList(b8);
            printf("\n");
            printf("bucket 9: ");
            printList(b9);
            printf("\n");

            deleteNode(&head);
            while (b0 != NULL) {
                insertNode(&head,b0->data);
                b0 = b0->next;
            }
            deleteNode(&b0);
            while (b1 != NULL) {
                insertNode(&head,b1->data);
                b1 = b1->next;
            }
            deleteNode(&b1);
            while (b2 != NULL) {
                insertNode(&head,b2->data);
                b2 = b2->next;
            }
            deleteNode(&b2);
            while (b3 != NULL) {
                insertNode(&head,b3->data);
                b3 = b3->next;
            }
            deleteNode(&b3);
            while (b4 != NULL) {
                insertNode(&head,b4->data);
                b4 = b4->next;
            }
            deleteNode(&b4);
            while (b5 != NULL) {
                insertNode(&head,b5->data);
                b5 = b5->next;
            }
            deleteNode(&b5);
            while (b6 != NULL) {
                insertNode(&head,b6->data);;
                b6 = b6->next;
            }
            deleteNode(&b6);
            while (b7 != NULL) {
                insertNode(&head,b7->data);
                b7 = b7->next;
            }
            deleteNode(&b7);
            while (b8 != NULL) {
                insertNode(&head,b8->data);
                b8 = b8->next;
            }
            deleteNode(&b8);
            while (b9 != NULL) {
                insertNode(&head,b9->data);
                b9 = b9->next;
            }
            deleteNode(&b9);

            printf("\n");
            printf("Stitched list: ");
            printList(head);
            printf("\n");
            printf("----------------------------------------------------------------------------");
            printf("\n");

    }

    printf("list after sort: ");
    printList(head);
    printf("\n");
    printf("****************************************************************************");
    deleteNode(&head);
    free(b0);
    free(b1);
    free(b2);
    free(b3);
    free(b4);
    free(b5);
    free(b6);
    free(b7);
    free(b8);
    free(b9);

    return 0;
}

