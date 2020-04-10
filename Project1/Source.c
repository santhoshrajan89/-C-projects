
#include <stdio.h>
#include <stdlib.h>


#define SOB 8
int readPointer = 0;
int writePointer = 0;

struct Buffer
{
	int item;
	int *next;

};

struct Buffer *head;
struct Buffer *prev;



int readFromBuffer()
{
	int data;
	struct Buffer *itr=head;

	if (readPointer <= writePointer)
	{
		for (int i = 0; i < readPointer; i++)
			itr = itr->next;

		data = itr->item;
		readPointer++;
	}
	else
	{
		printf("\n unable to read from the buffer...");
		return 0;
	}
	
	return data;

}

void writeTOBuffer()
{
	int data;
	struct Buffer *p;

	if (writePointer >= SOB - 1)
		printf("\nBuffer is full");
	else
	{
		writePointer++;

		printf("\nEnter the data to be written\n");
		scanf_s(" %d", &data);
		p = malloc(sizeof(struct Buffer));
		p->item = data;
		p->next = head;
		
		if (head == NULL)
			head = p;
		else
			prev->next = p;

		prev = p;
	}

	return data;

}

void printBuffer()
{
	struct Buffer *itr = head;
	while (1)
	{
		printf("%d->", itr->item);
		itr = itr->next;
		//if (itr == head)
			//break;
	}
	//printf("<-%d", head->item);
}

int main()
{
	int quit = 0;
	char input;
	int ret;
	printf("\nWlecome to the Ring Buffer\n");
    
	while (quit != 1)
	{
		printf("\nEnter the operation you wish to perform\n");
		printf("\nPress R-Read, W-write,P-print, Q-quit\n");
		scanf_s(" %c", &input);

		switch (input)
		{
		case 'R':
			 ret = readFromBuffer();
			printf(" the value read from buffer is %d", ret);
			break;
		case 'W':
			writeTOBuffer();
			break;
		case 'Q':
			quit = 1;
			break;

		case 'P':
			printBuffer();
			break;

		default:
			printf("A bad input..cannot slip through");
			break;
		}
		
	}


	




}