#include "stdio.h"
#include <time.h>

double totalTime1;
clock_t start1, end1;

// player names
char player1Name[30], player2Name[30];
char winnerName[30];
// check for turn
int turnCount = 0;

// board representation
int board[3][7];
int column3Filled, column5Filled, column7Filled;

// players input
int selectedColumn;
int numberOfCirclesCircled;

void getTheUserNames() {
  printf("Enter player 1 name: ");
  scanf("%s", player1Name); 
  printf("Enter player 2 name: ");
  scanf("%s", player2Name); 
}

void initBoard(){
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 7; j++) {
      board[i][j] = 0;
    }
  }
  
  column3Filled = 0;
  column5Filled = 0;
  column7Filled = 0;
  
}

void displayBoard(){
  int column, element;
  for(column = 0; column < 3; column++)
  {
    for(element = 0; element < 3 + 2 * column; element++){
      printf(" %d", board[column][element] );
    }
  	if (column < 2) 
  		printf(" ||");
  }
}

// Print the player's name 
// take the input
void getPlayersInput() {
  printf("\n");
  if(turnCount%2==0){
  	printf("%s it is your turn.", player1Name);

  }
  else{
  	printf("%s it is your turn.", player2Name );
  }
  printf("\nEnter column number: ");
  scanf("%d", &selectedColumn);
  printf("Enter number of circles to be filled: ");
  scanf("%d", &numberOfCirclesCircled);
  
}

// validity 
// return 
//  1 if valid
// -1 if invalid
int isValidInput(){
  if((selectedColumn==3) || (selectedColumn==5) || (selectedColumn==7) ){
    // available spaces
    int availableCircles = 0;
    switch(selectedColumn){
      case 3:
        availableCircles = selectedColumn - column3Filled;
        break;
      case 5:
        availableCircles = selectedColumn - column5Filled;
        break;
      case 7:
        availableCircles = selectedColumn - column7Filled;
        break;
      
    }


    if (numberOfCirclesCircled == 0) {
    	printf("Atleast one circle has to be selected");
    	return -1;
    }    

    if(numberOfCirclesCircled <= availableCircles) {
      return 1;
    } else {
    	printf("There are only %d circles available", availableCircles);
    }

  } else {
  	printf("Enter proper inputs. Column numbers: 3, 5, 7 and no of circles cannot be greater than the zeros in the selected column.\n");
  }

  
  return -1;
}

// update board
void updateBoard(){
  int column = selectedColumn/2 -1;
  for(int i = 0; i < numberOfCirclesCircled; i++){
    switch(selectedColumn) {
      case 3:
        board[column][column3Filled] = 1;
        column3Filled++;
      break;
      case 5:
        board[column][column5Filled] = 1;
        column5Filled++;
      break;
      case 7:
        board[column][column7Filled] = 1;
        column7Filled++;
      break;
      
    }
  }
}
void winnerOfTheGame(){
  if(column3Filled + column5Filled + column7Filled >= 14){
    printf("Game Over  ");
  }
}

// return
//   1 on complete, and update the winner name
//   -1 otherwise
int isGameOver() {
  if(column3Filled + column5Filled + column7Filled >= 14){
      return 1;
    
  }
  else 
    return -1; 
}

void displayTheWinner() {
  if(turnCount%2==0){
    printf("\n%s is winner.", player2Name);      
  }
  else{
    printf("\n%s is winner.", player1Name);
  }
}

  

int main(void) {
  start1 = clock();

  // get the names of the users
  getTheUserNames();
  
  // display board status
  initBoard();
  
  do {
    displayBoard();
  
    // display player's turn
    // enter column number, no of circles to be filled
    // check for validity
    // if yes update and display the board
    // if no invalid move please enter correct choice
    
    do {
      getPlayersInput();
    } while(isValidInput() != 1);
    
    turnCount += 1;
    updateBoard();
    
    
  } while (isGameOver() != 1);
  
  displayBoard();
  // check for winner 
  // print the winner otherwise continue
  displayTheWinner();
  end1 = clock();
  totalTime1 = (double)(end1 - start1)/CLOCKS_PER_SEC;
  printf("Time taken for entire program is %lf.", totalTime1);
  return 0;
}

