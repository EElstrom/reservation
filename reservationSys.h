#include <stdio.h>

//preprocessor directive to define the maximum seats in the plane as 10
#define MAXIMUM 10

void header(void);
int getMenuChoice(void);
void reservationSystem(void);
void assignSeats(int, int seatList[]);
void displaySeats(int firstClassList[], int numFirstClass, int econClassList[], int numEconClass);

// introduction and instructions
void header(void) {
  printf("\t\tWelcome to the plane\n"
          "\t\t--------------------\n\n"
          "There are 10 seats available, you may choose how many of those seats are treated as first "
		  "class, and then how many are considered economy class.\n\n"
          "\t\t---------------------\n\n");
}

// function to show and return a users choice
int getMenuChoice(void)
{  
  //declare variable that user will update.
  int choice=0;

  //print out the Menu
  printf("\t\t--------------------"
         "\n\t\t       [MENU]       "
         "\n\t\t--------------------");
  printf("\n\n\tPress [1]: Assign First Class.\n"
         "\tPress [2]: Assign Economy Class.\n"
         "\tPress [3]: Display current seating chart.\n"
         "\tPress [4]: Exit.\n\n");

  // loop that checks that choice was within parameters, and will 
  // continue to reprompt until a proper choice is assigned. 
  do 
  {
    printf("Please type in your menu choice: ");
    scanf("%d", &choice);
      if (choice > 4 || choice < 1)
        puts("\t\tInvalid choice.\n");
  }
  while (choice > 4 || choice < 1);

  // returns the integer value of the users choice in the menu.
  return choice;
}

// biggest function that is used in main
void reservationSystem(void) 
{  
  // declare variables and arrays
  int numFirstClass;
  int numEconClass;
  int firstClassList[MAXIMUM];
  int econClassList[MAXIMUM];

  // initialize arrays with all their values set to 0.
  for (int i = 0; i < MAXIMUM; i++) 
  {
		firstClassList[i]=0;
		econClassList[i]=0;
  }

  // do...while loop runs only once as long as the values inputted are valid (less than the MAXIMUM).
  do 
  {
    printf("\nPlease type how many First and Economy class seats: ");
    scanf("%d %d", &numFirstClass, &numEconClass);
      // if statement checks if variables are valid
      if (numFirstClass + numEconClass > MAXIMUM)
        puts("**ERROR** Too many seats designated."
			 "Please choose a layout that does not exceed 10.\n");
  }
  while (numFirstClass + numEconClass > MAXIMUM);

  // Switch case that calls Menu and its returned integer to determine 
  // which functions are called in respect to the menu choice.
  while (1) 
  { 
    switch (getMenuChoice()) {
      case 1: 
        assignSeats(numFirstClass, firstClassList);
        break;
      case 2: 
        assignSeats(numEconClass, econClassList);
        break;
      case 3: 
        displaySeats(firstClassList, numFirstClass, econClassList, numEconClass);
        break;
      //the exiting case, which ends the entire reservationSystem function, instead of just breaking the while.
      case 4:
        printf("Thank you, have a nice flight!");
        return;
    }
  }
}


// function that will update the seating arrays once per function call.
void assignSeats(int numSeat, int seatList[]) 
{
  printf("\n\nWe are finding your seat...\n\n");
  
  // for loop that iterates over the positions in the passed array, 
  // checking which of the seats, in order, are available. 
  // Iterates only the number of seats assigned in the very beginning.
  for (int i = 0; i < numSeat; i++) 
  {
	// 0 designates an available seat
    if (seatList[i] == 0) 
	{ 
      seatList[i] = 1; //updates that position to '1'
      printf("Seat Number: %d\n\n", i+1);
      // exits the assignSeats function, otherwise the for loop would update the entire array.
	  return;
    }
  }
  // error if the function is called and there are no positions left that are empty
  printf("**Sorry!** There are no more seats of that type available\n\n");
}

// a display that shows user the dynamically updated seating arrays. Can be selected at any time.
void displaySeats(int firstClassList[], int numFirstClass, int econClassList[], int numEconClass)
{
  
  printf("\nThe plane layout is as follows: \n");
  printf("[ ");
  // iterates over each element in the array, bounded by the number designated by user, 
  // and prints the value of that element.
  // display first class 
  for (int i = 0; i < numFirstClass; i++)
  {
    printf("%d ", firstClassList[i]);
  }

  // display economy class
  printf("]");
  printf(" [ ");
  for (int k = 0; k < numEconClass; k++)
  {
    printf("%d ", econClassList[k]);
  }
  printf("]\n\n");
}