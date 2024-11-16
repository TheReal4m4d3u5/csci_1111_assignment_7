/*
						Avery Jacobson	
						  James Polzin	
						     csci 1111


Assignment 7:                Given: 03/20/14     Due: 03/27/14
------------                                  Points: 10

Purpose: - Use arrays.
         - Model a deck of playing cards.

Description:
-----------
Create an array of 52 elements where each element represents a
card in a deck of playing cards. (Use the values 0-51 to 
represent the 52 different cards in the deck.)
      
Write functions to do the following:
  1) deal a card from the deck
  2) display a card, indicating suit and value 
     (Same as your function in assign #6.)
  3) shuffle the deck

Write a "driver program" to test your functions and show that
your functions and deck appear to be working properly. Have the
driver program deal a set of five cards from your deck.
   
Notes:
-----
 - When dealing, the card dealt should no longer be in the deck
 - Shuffling should "randomly" reorder the deck
   
E-mail your source code to Otto.
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char suits [4][9] = {
			"Hearts",
			"Diamonds",
			"Clubs",
			"Spades"
			};



void shuffle(int [], int *x);
void printDeck(const int d[], const int size);
void displayCard(const int cardValue);
void dealCard(const int arry[], const int);
void dealFinal(const int arry[], int*x, int);

int main()
{

	int deck[52];
	int i, inc =0;


	for(i=0; i<52; i++)
		deck[i] = i;

	printf("Original deck:\n");
	printDeck(deck, 52);


    	shuffle(deck, &inc);

	printf("\n\n\nPrint random deck:\n");
	printDeck(deck, 52);

	printf("\ndeal five cards\n");
	dealFinal(deck, &inc, 5);
	

	return 0;

}



void shuffle(int arry[], int *x)
{
	int i;
	*x = 0;
	

	for(i = 0; i< 52; i++)
	{
		int temp;
		int r1 = rand()%52;
		temp = arry[i];
		arry[i] = arry[r1];
		arry[r1] = temp;		
	}
}


void dealFinal(const int arry[], int *x, int ncards)
{

	int max;	

	max = *x + ncards;

	if(*x >= 52-(ncards-1))
		printf("Not enough card to deal hand, please shoufle deck");
	else
	{
		// dealing off (bottom or top deapending how you want to look at it) of deck 
		while(*x < max)
		{
			dealCard(arry, *x);
			*x +=1;
		}
	}

}


void dealCard(const int arry[], const int inc)
{
	int value;
	value = arry[inc];
	displayCard(value);
}




void printDeck(const int d[], const int size)
{
	 int i;
	
	for(i = 0; i < size; i++)
	{		
		displayCard(d[i]);
	}
}

void displayCard(const int cardValue)
{
	if(cardValue%13 == 0)
		printf("Ace");
	else if(cardValue%13 == 1)
		printf("King");
	else if(cardValue%13 == 11)
		printf("Jack");	
	else if(cardValue%13 == 12)
		printf("Queen");
	else
		printf("%d", cardValue%13);

	printf(" %s\n", suits[cardValue/13]);


}