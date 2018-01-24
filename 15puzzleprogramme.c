#include <stdio.h>
#include <stdlib.h>

void draw_board();
char take_input();
void process_input(char ch);
void go_left();
void go_up();
void go_down();
void go_right();
void clear_board();
void swap(int x1,int y1,int x2,int y2);
int check_win();
int board[4][4]= {1,2,3,4,5,6,7,8,9,10,11,12,0,13,14,15};
//Initial board , change the values and zero indexes for various boards

 int b=3;
 int v=0;
//Intially zero postions ,first and second indexes , if 0 is at (1,3) firstindex will be 1 and second will be 3

//Initial move count
int move_count=0;

int main()
{

     int c;
     char l;
    draw_board();//Intitially draw the board
c=check_win();
    //Loop till check_win is not equal to 1
        while(c!=1){

       l=take_input();//Take input and store in ch
	    process_input(l);//Process input (ch)
        clear_board();//Clear the board
        draw_board();//Draw the board again
        move_count++;//Increase move count
c=check_win();
   } //End Loop
    printf("you have won with %d moves",move_count);//Print You have won with ___ Moves
   return 0;
}

void draw_board()
{
	int i,j;

	for(i=0;i<4;i++){
printf("\t____________________________________\n\n");
			printf("\t|");
		for(j=0;j<4;j++){
			printf("   %d   ",board[i][j]);
		printf("|");
		}
		printf("\n");

	}
	printf("\t____________________________________\n");
/*
Print the current board like
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14  0 15
*/

printf("\n----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right-----------\n") ;


}
void clear_board(){
   system("cls"); //Clear the board
}
char take_input()
{   fflush(stdin);
	char m;

  scanf("%c",&m);

  return m;
  /*
Take input and return it ,Use Fflush if scanf is being used

*/
}

void process_input(char ch)
{


 switch(ch){

case 'W' :
case'w': go_up();

       break;
case 'A' :
case 'a': go_left();
       break;

case 'S' :
case 's': go_down();
       break;

case 'D' :
case 'd': go_right();
       break;

/*
Handle the input char ch ,which is either w,a,s,d ,for up,left,down and right
Use a switch case and call go_left(),go_right()etc respectively
*/
default: break;
 }
}

void go_left()
{
if(v>0)
{
v=v-1;
swap(b,v+1,b,v);
}
//move 0 tile left
}
void go_right()
{
if(v<3)
{
v=v+1;
swap(b,v-1,b,v);//move 0 tile right
}
}
void go_up()
{
if(b>0)
{
b=b-1;
swap(b+1,v,b,v);
}
//Move 0 tile up
}
void go_down()
{
if(b<3)
{
b=b+1;
swap(b-1,v,b,v);//Move 0 tile down

}
}

void swap(int x1,int y1,int x2,int y2)
{
int temp;

temp=board[x1][y1];
board[x1][y1]=board[x2][y2];
board[x2][y2]=temp;//Swap board[x1][y1] and board[x2][y2];

}

int check_win(){

	int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	int r,z,o=0;
	for(r=0;r<4;r++){
		for(z=0;z<4;z++){
			if(board[r][z]==a[r][z]){
				o++;
			}
		}
	}
	 if(o==16)
		return 1;
	 else
		return 0;
//Return 1 , if current board has all tiles perfectly places ,or 0 otherwise
}
