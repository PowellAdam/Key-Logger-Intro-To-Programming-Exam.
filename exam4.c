
/////////////////////////////////////////////////////////////////
// Adam Powell                                                 //
// 4/6/2017                                                    //
// Exam 4: Key-Logger                                          //
// COP 1000: Hunchuck                                          //
/////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> 
#define PAUSE printf("\t\t\t\t\t"); system("pause")
#define CLEAR system("cls")
#define FLUSH myFlush(letters) 
#define SIZE 98

//prototype functions here
void aMessage(char m[]);
void caseSwitch(char a[], int b[]);
void characterList(char a[]);
void displayArrays(char a[], int b[]);
void header();
int highestToLowest(char letters[], int counts[]);
void keysNotPressed(char letters[], int counts[]);
void menu();
void thatWerePressed(char letters[], int counts[]); 
void typeAway(char a[], int b[]);





main() {

	char letters[SIZE] = { ' ' };

	int counts[SIZE] = { NULL };

	
	caseSwitch(letters, counts);


	
}//end of main

void aMessage(char m[]) {
	
	printf("\n\t\t\t%s\n", m);
	PAUSE;
	CLEAR;
	
	
}//end of aMessage()

void caseSwitch(char letters[], int counts[]) {//Switch statement (technically main function)

	int choice;
	characterList(letters); // do this one and only one time.
	

	do {
		menu();
		choice = getSelection();

		switch (choice) {

		case 1: //Press a Key(s) on Keyboard
			
			typeAway(letters, counts);
			break;

		case 2:// Display how many of each key that has been pressed
			
			highestToLowest(letters, counts);
			displayArrays(letters, counts);
			break;

		case 3://Display the keys that have never been pressed
			
			keysNotPressed(letters, counts);
			break;

		case 4://Display the key that has been pressed the most
			
			thatWerePressed(letters, counts);
			break;

		case 5://QUIT
			aMessage("See you next time!!!");
			break;

		default://in case bad input
			aMessage("Invalid Selection.....");
			break;
		}

	} while (choice != 5);

	}//end caseSwitch()


void characterList(char letters[]) {
	int i, j = 0;
	
	for (i = 32; i <= 129; i++){
	   letters[j] = i;
	   j = j + 1;

    } // End For

} // end characterList


void displayArrays(char a[], int b[]) {
	int i;

	for (i = 0; i < SIZE; i++)
		printf("\t\t\t\t\t%i.  %c   was pressed   %i   time(s)\n\n", i + 1, a[i], b[i]);
	PAUSE;
}// end of displayArryas()


int getSelection() {

	int selection;

	printf("\t\t\t\t\tMake selection by entering the\n\n\t\t\t\t\tnumber of the menu item (1-5):  ");
	scanf("%i", &selection);

	return selection;
}//end of getSelection()

	
	
void header() {
	printf("\n\n\n==========================================================================================================\n");
	printf("=========================================    Adam's KEY LOGGER   =========================================\n");
	printf("==========================================================================================================\n\n");

}// end of header

int highestToLowest(char letters[], int counts[]) {

	int i, b, temp = 0;
	int letterTemp = 0;

	CLEAR;

	header();

	for (i = 0; i < SIZE - 1; i++) {
		for (b = 0; b < SIZE - i - 1; b++) {

			if (counts[b] < counts[b + 1]) {
				temp = counts[b];
				counts[b] = counts[b + 1];
				counts[b + 1] = temp;

				letterTemp = letters[b];
				letters[b] = letters[b + 1];
				letters[b + 1] = letterTemp;


			}// of of if
		}//end of second for loop
	}//end for loop

	printf("\n");

}//end highestToLowest()


void keysNotPressed(char letters[], int counts[]) {
	
	int i; 
	int num = 0;

	CLEAR;

	header();

	printf("\n\n");

	for (i = 0; i < SIZE ; i++) {
		if (counts[i] == 0) {
			num += 1;
			printf("\t\t\t\t\t%i.   %c  was not pressed....:  %i\n\n", num, letters[i], counts[i]);
		}
	}
	PAUSE;

}//end keyNotPressed()

void menu() {

	CLEAR;

	printf("\n\n\n==========================================================================================================\n");
	printf("=========================================  KEY LOGGER MAIN MENU  =========================================\n");
	printf("==========================================================================================================\n\n");

	printf("\t\t\t\t 1.  Press a Key(s) on Keyboard\n\n");
	printf("\t\t\t\t 2.  Display how many of each key that has been pressed (in order from high to low)\n\n");
	printf("\t\t\t\t 3.  Display the keys that have never been pressed\n\n");
	printf("\t\t\t\t 4.  Display the key that has been pressed the most\n\n");
	printf("\t\t\t\t 5.  Quit\n\n");

	

}//end of menu


void thatWerePressed(char letters[], int counts[]) {
	header();
	int i, b = 0;

	highestToLowest(letters, counts);
	
	printf("\t\t\tTop Ten Most Pressed (Characters not used won't be listed)\n\n\n");

		for (i = 0; i < 10; i++) {
			if (counts[i] > 0) {
				printf("\t\t\t\t\t%i.  %c  was pressed %i time(s)\n\n", i + 1, letters[i], counts[i]);

			}

		}

	PAUSE;
}//end of thatWerePressed()


void typeAway(char letters[], int counts[]) {

	char tempChar;
	int i;

	CLEAR;

	header();

	printf("\n\t\t\t\tType away!...\n\n\t\t\t\t To Return to Menu, press Enter.\n\n\t\t\t\t You may return to add characters!\n\n");

	printf("\t\t\t");

	getchar();

	do {

		tempChar = getchar();

		if (tempChar == '\n')
			return;

		for (i = 0; i <= SIZE; i++) {
			if (tempChar == letters[i]) {

				counts[i] += 1;
			}
		}

	} while (tempChar != '\n');

	PAUSE;
	CLEAR;

}//end of typeAway()