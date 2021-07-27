#include<stdio.h>
#include<windows.h>
#include <stdbool.h>

void gotoxy(int x, int y){//This function is basically given the any (x,y) postion on the console screen

 COORD c;
 c.X = x;
 c.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//Globel variable
char key;
char x,y;//Cordinates of snakes hea
char *bodyX,*bodyY;
char BorderX[180];
char BorderY[180];
char foodX = 40,foodY=20;
char length =3,j = 0;
char speed = 70;
//All the funcations
char menu(void);
void Border(void);
void BARRIERSandFOOD(void);
bool Right(void);
bool Left(void);
bool Up(void);
bool Down(void);
void Scores(char pos);



int main(void)
{	
	system("COLOR F3");//Color of console(wher f = backgraound color and c = text color)
	while(1){//free loop
		bodyX = (char*)malloc(length*sizeof(char));
		bodyY = (char*)malloc(length*sizeof(char));
		
		char pos = menu();//caling the function menue
		
		if 				(pos == 'B'){system("cls");Scores(pos);}
		else if			(pos == 'D'){system("cls"); break;}													//ending the loop if excit is press
		else if			(pos == 'C'){system("cls");gotoxy(10,10); printf("Cradit goes to Hasan, Ahsan and Merium.");key = getch();}//showing the cradits
		
		else
		{
			system("cls");
			puts("To navigate use w,a,s ,and d");
			puts("____________________________");
			x = 60; y =15;//(intital variables of snake head
			Border();//lading borders
			key = 'a';//starting with key i.e right diraction
			short check =1 ;
			while(key != 'z')
			{
				if	   (key == 'd' && check == 0)
					check = Right();
				else if(key == 's' && check == 1)
					check = Down();
				else if(key == 'w' && check == 0)
					check = Up();
				else if(key == 'a' && check == 1)
					check = Left();
			}
		j=0;//its just itration to check intililize the size of snake
		system("cls");
		Scores(pos);
		length = 3;
		}
	system("cls");
	}//where length of the snake after the game over
	printf("Thank you for playing.");
	return 0;
}
char menu(void)
{
	puts("To navigate use w(for up) ,s (for down) a(Enter)");
	puts("________________________________________________");
	char key = 's',pos =  'A';
	char pla=205,Cra = 196,exc=196,rec =196;
	 while(key != 'a' )
	 {
	 		gotoxy(44,4);
	 		printf("%c%c%c%c%c%c%c%c",201,pla,pla,pla,pla,pla,pla,187);
	 		gotoxy(44,5);
		 	printf("%c PLAY %c",186,186);
		 	gotoxy(44,6);
		 	printf("%c%c%c%c%c%c%c%c",200,pla,pla,pla,pla,pla,pla,188);
	 		gotoxy(43,8);
			printf("%c%c%c%c%c%c%c%c%c%c%c",201,rec,rec,rec,rec,rec,rec,rec,rec,rec,187);
	 		gotoxy(43,9);
	 		printf("%c RECORDS %c",186,186);
	 		gotoxy(43,10);
	 		printf("%c%c%c%c%c%c%c%c%c%c%c",200,rec,rec,rec,rec,rec,rec,rec,rec,rec,188);
	 	
	 		gotoxy(43,12);
	 		printf("%c%c%c%c%c%c%c%c%c%c%c",201,Cra,Cra,Cra,Cra,Cra,Cra,Cra,Cra,Cra,187);
	 		gotoxy(43,13);
	 		printf("%c CREDITS %c",186,186);
	 		gotoxy(43,14);
	 		printf("%c%c%c%c%c%c%c%c%c%c%c",200,Cra,Cra,Cra,Cra,Cra,Cra,Cra,Cra,Cra,188);
	 	
	 		gotoxy(44,16);
	 		printf("%c%c%c%c%c%c%c%c",201,exc,exc,exc,exc,exc,exc,187);
	 		gotoxy(44,17);
	 		printf("%c EXIT %c",186,186);
	 		gotoxy(44,18);
	 		printf("%c%c%c%c%c%c%c%c",200,exc,exc,exc,exc,exc,exc,188);
	 	key = getch(key);
		if(key == 's' && pos == 'A')     	{pos = 'B'; pla = 196 ; rec = 205;}
		else if(key == 's' && pos == 'B')	{pos = 'C'; rec = 196 ; Cra = 205;}
		else if(key == 'w' && pos == 'B')	{pos = 'A'; rec = 196 ; pla = 205;}
		else if(key == 'w' && pos == 'C')	{pos = 'B'; Cra = 196 ; rec = 205;}
		else if(key == 's' && pos == 'C')	{pos = 'D'; Cra = 196 ; exc = 205;}
		else if(key == 'w' && pos == 'D')	{pos = 'C'; exc = 196 ; Cra = 205;}
	}
	return pos;
}
void Border()
{
	int i,k=0;
	for(i=10;i<75;i++)//loading the horizontal barriers 
  	{
   	    gotoxy(i,3);//
        printf("%c",220);//upper horizontal barrier
        BorderX[k] = i;//saving the cordinates of walls in border array
        BorderY[k] = 3;//saving the cordinates of walls in border array
        k++;
        gotoxy(i,28);
    	printf("%c",220);//lower horizontal barrier
       	BorderX[k] = i;
        BorderY[k] = 28;
        k++;
 	}
   for(i=4;i<29;i++)//loading the vertical barriers
   {
       gotoxy(10,i);
        	printf("%c",219);
        BorderX[k] = 10;//saving the cordinates of walls in border array
        BorderY[k] = i;//saving the cordinates of walls in border array
        k++;
       gotoxy(74,i);
    		printf("%c",219);
    	BorderX[k] = 74;
        BorderY[k] = i;
        k++;
   }
   int l;
   for(l = 1 ; l<4 ;l++)
   for(i=0 ;i <6 ;i ++)
   {
   	gotoxy(i+25,8*l);
   	printf("%c",220);
   	gotoxy(i+55,8*l);
   	printf("%c",220);
   }
   	gotoxy(10,2);
    printf("Score  :  %d",length-3);//printing the score
	gotoxy(foodX,foodY);
	printf("%c",232);//intial cordinates of food
}
void BARRIERSandFOOD()
{
	short i;
	short check = 1;
	
	for(i = 0 ; i<180 ; i++)
			if(BorderX[i] == x && BorderY[i] == y)//checking where head of the snake maches with walls
				{
					key = 'z';
					return;
				}
	for(i = 0 ; i<length-2 ; i++)
		if(bodyX[i] == x && bodyY[i] == y)//here checking  if head cordinates maches with body cordinates
		{
		
					key = 'z';
					return;
		}
	gotoxy(10,2);
    printf("Score  :  %d",34*(length-3));//printing the score wither 34 some randome number it shows that it's gaining high score
	if(x==foodX && y==foodY)//checking the food cordinates if maches with  head cordinates
	{
		while(check != 0){
       		time_t t;
   
  			srand((unsigned) time(&t));//calling the random funcation where seed is time
      		foodX = rand()%74;//horizontal range of food is between (11 - 73)
      		if(foodX<=10)
          		foodX += 11;
      		foodY=rand()%28;//where vertical range is (5 - 27) for the cordinates of food
        	if(foodY<=4)
            	foodY += 5;  	      
			length++;
			bodyX = (char *) realloc(bodyX, length);
			bodyY = (char *) realloc(bodyY, length);
			for(i = 0 ; i<length-2 ; i++)
			if(bodyX[i] == foodX && bodyY[i] == foodY)//here i am checking if cordinates of body does not  match with the food(where we do not print the food on to the body)
				check = 1;				
			else check = 0;
		}
		gotoxy(foodX,foodY);
		printf("%c",232);
    }
}
bool Right()//All the (Right,Left and Up working on same method)
{	short i;
	while(!(key == 'w' || key == 's')){//not ending the loop till these specific keys are pressed
	do{
	x++;		//for right funcation i am increasing the x in the positive-x direaction
		gotoxy(x,y);//printing the o in x y cordinates
		printf("o");
			bodyX[j] = x;
			bodyY[j] = y;//saving the cordinates of body in body array x and array y

		gotoxy(0,0);//this really does not do any thing importent 
		Sleep(speed*0.8);//waiting till print next body part of snake (to give smooth effect)
		if(j >= length-1){
		gotoxy(bodyX[0],bodyY[0]);
		printf(" ");//removing the last body part of the snake where it's cordinates is in location (0,0) body array
		for(i= 0 ; i<length-1 ; i++){
	
			bodyX[i] = bodyX[i+1];
			bodyY[i] = bodyY[i+1];}//here i am moving the current cordinate(one by one) to (0,0) loaction in body array
			BARRIERSandFOOD();//here we are calling function
			if(key == 'z') return;}//if the function return z ending the function
			
		else j++;  

		
		}while(!kbhit());
		key = getch();
	}
	if(key == 's')  {return 1;}
	else 			{return 0;}
}
bool Left()
{
	short i;
	while(!(key == 's' || key == 'w')){
	do{
	x--;
		gotoxy(x,y);
		printf("o");
			bodyX[j] = x;
			bodyY[j] = y;

		gotoxy(0,0);
		Sleep(speed*0.8);
		if(j >= length-1){
		gotoxy(bodyX[0],bodyY[0]);
		printf(" ");
		gotoxy(0,0);
		for(i= 0 ; i<length-1 ; i++){
	
			bodyX[i] = bodyX[i+1];
			bodyY[i] = bodyY[i+1];}
			BARRIERSandFOOD();
			if(key == 'z') return;}
			
		else j++;  
		
		}while(!kbhit());
		key = getch();
	}
	if(key == 's') {return 1;}
	else 		   {return 0;}
	
}
bool Up()
{
	short i;
	while(!(key == 'a' || key == 'd') ){
	do{
		y--;
			gotoxy(x,y);
		printf("o");
			bodyX[j] = x;
			bodyY[j] = y;

		gotoxy(0,0);
		 Sleep(speed);
		if(j >= length-1){
		gotoxy(bodyX[0],bodyY[0]);
		printf(" ");
		gotoxy(0,0);
		for(i= 0 ; i<length-1 ; i++){
	
			bodyX[i] = bodyX[i+1];
			bodyY[i] = bodyY[i+1];}
			BARRIERSandFOOD();
			if(key == 'z') return;}
			
		else j++;  
		
		}while(!kbhit());
		key = getch();
	}
	if(key == 'a')  {return 1;}
	else 			{return 0;}
	
}
bool Down()//going downwards
{
	short i;
	while(!(key == 'a' || key == 'd')){//Checking if these specific keys are pressed
		do{
			y++;
			gotoxy(x,y);
			printf("o");
			bodyX[j] = x;
			bodyY[j] = y;

			gotoxy(0,0);
			Sleep(speed);
			if(j >= length-1){
				gotoxy(bodyX[0],bodyY[0]);
				printf(" ");
				gotoxy(0,0);
				for(i= 0 ; i<length-1 ; i++){
	
				bodyX[i] = bodyX[i+1];
				bodyY[i] = bodyY[i+1];}
				BARRIERSandFOOD();
				if(key == 'z') return;
			}	
		else j++;  
		}while(!kbhit());
	key = getch();
	}
	if(key == 'a')  {return 1;}
	else            {return 0;}
}
void Scores(char pos)
{
	FILE *data;
	if(pos != 'B')
	{
		int i;
		char name[9];
		char newName[10] = "         ";
		printf("Enter your name:");
		scanf("%s",name);
		short len = strlen(name);
	
		for(i =0 ; i <len ; i++){
			if(i< len)
			newName[i] = name[i];	
		}

		data = fopen("data.txt","a");
		fprintf(data,"\nPlayer:%s          score:%d\n",newName,34*(length-3));
		fprintf(data,"______________________________________");
		fclose(data);
		printf("To check othres scores go to records.\nPress any key to continue.");
		getch();
	}
	else{
		puts("");
		puts("    These are all the previous records\n");
		puts("_____________________________________________");
		char singleLine[40];
		data = fopen("data.txt","r");
		while(!feof(data))
		{
			fgets(singleLine,40,data);
			puts(singleLine);
		}
		fclose(data);
		getch();
	}	
}
