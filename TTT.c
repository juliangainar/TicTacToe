// TIC TAC TOE V0.1

//Inlcuding all libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// defining user and password (feel free to change it)
#define USER "mike"
#define PASS "mikey"

//declaring all functions
int login();
void menu(char v[3][3]);
void loop_1_player(char v[3][3]);
void loop_2_players(char v[3][3]);
void credits();
void create_table(char v[3][3]);
void table(char v[3][3]);
void intro_player1(char v[3][3]);
void intro_player2(char v[3][3]);
void intro_AI(char v[3][3]);
int check(char v[3][3]);


main(){   // main function: calls and checks the login
	
	int s;
	char v[3][3];
	s = login(s);
	
	if(s == 1){
		menu(v);
	}
	
	
	system ("pause");
	return 0;
}

int login(){  //checks if password and user are correct, then it returns 1 or 0
	
	int s;
	char user[4], pass[5];
	
	s = 0;
	
		
	do{
		
		system("cls");
		printf("User: \n");
		scanf("%s", &user);
		printf("Password: \n");
		scanf("%s", &pass);
		
		if(strcmp(user, USER) == 0 && strcmp(pass, PASS) == 0){
			
			s = 1;
			
		}
		else{
			
			printf("Wrong user or password. Try again.\n\n");
			system("pause");
			
		}
				
	}while(strcmp(user, USER) != 0 && strcmp(pass, PASS) != 0);
	 
	return s;
}



void menu(char v[3][3]){   // if you pass the login, you get to the menu, who calls all the other functions
	
	int c;
	
	system("cls");
	printf("\nWelcome, %s.\n\n", USER);
	printf("======================\n");
	printf("=                    =\n");
	printf("= TIC TAC TOE V. 0.1 =\n");
	printf("=                    =\n");
	printf("======================\n\n");
	printf("1. Player vs. AI\n");
	printf("2. Player vs. Player\n");
	printf("3. Credits\n");
	printf("4. Quit\n");
	scanf("%d", &c);
	
	switch(c) {	
		case 1:{  // if user choses 1, then execute loop 1 player
			
			loop_1_player(v);
			break;
		}
		
		case 2:{   // if user choses 2, then execute loop 2 player
			
			loop_2_players(v);
			break;
		}
		case 3:{    // if user choses 3, then execute credits
			
			credits();
			break;
		}
		case 4:{  // if user choses 4, then execute printf
			
			printf("Thanks for passing by. See you later.\n");
			break;
		}
		
	}
	
	
}

void loop_1_player(char v[3][3]){
	
	int i,j;
	i = 0;
	
	create_table(v);
	printf("PLAYER vs AI");
	
	do{
		system("cls");
		table(v);
		if(i % 2 == 0){
			intro_player1(v);
		}
		else{
			intro_AI(v);
		}
		j = check(v);
		i++;
		
	}while(i <= 9 && j == 2);
    
	system("cls");
	table(v);
	
	if(j == 0){
    	printf("Nice ! You win !\n");
	}
	else if(j == 1){
		printf("Oh... you lose !\n");
	}
	if(j != 0 && j != 1){
		printf("That looks like a draw... try again !\n");
	}
}
void loop_2_players(char v[3][3]){
	
	int i,j;
	i = 0;
	
	create_table(v);
	printf("PLAYER vs PLAYER\n");
	
	do{
		system("cls");
		table(v);
		if(i % 2 == 0){
			printf("Player 1 moves \n");
			intro_player1(v);
		}
		else{
			printf("Player 2 moves \n");
			intro_player2(v);
		}
		j = check(v);
		i++;
		
	}while(i <= 9 && j == 2);
    
	system("cls");
	tablero(v);
	
	if(j == 0){
    	printf("Player 1 wins !\n");
	}
	else if(j == 1){
		printf("Player 2 wins !\n");
	}
	if(j != 0 && j != 1){
		printf("That looks like a draw... try again !\n");
	}
	
}

void credits(char v[3][3]){
	
	int c;
	
	do{
		system("cls");
		printf("Tic Tac Toe, created by Iulian GAINAR on 20 / 08 / 2020.\n\n");
		printf("Developped by Iulian GAINAR.\n\n");
		printf("Music by Iulian GAINAR (There is actually no music... :( )).\n\n");
		printf("::: PRESS 1 TO GO BACK :::\n");
    	scanf("%d", &c);
    	if(c == 1){
    	
    	menu(v);
    	
	 }
	}while(c != 1);
	
}

void create_table(char v[3][3]){
	
	int i, j;
	char aux;
	
	aux = '1';
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			
			v[i][j] = aux++;
			
		}
	}
	
}

void table(char v[3][3]){
	
	int i, j;
	printf("\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(j < 2){
				printf(" %c |", v[i][j]);
			}
			else{
				printf(" %c ", v[i][j]);
			}
		}
		if(i < 2){
				printf("\n-----------\n");
			}
	}
	printf("\n\n");
	
}


void intro_player1(char v[3][3]){
	
	char aux;
	int i,j,k;
	
	
	do{
		
		do{
			
			printf("Pick your spot: ");
			fflush(stdin);
			scanf("%c", &aux);
			
			if(aux < '1' || aux > '9'){
				printf("Wrong number. Please try again.\n");
			}
			
		}while(aux < '1' || aux > '9');
		
		k = 0;
		
		switch(aux){
		 	
		  case '1':{
		  	
			  	i = 0;
			  	j = 0;
			  	
			  	if(v[i][j] == 'X' || v[i][j] == 'O'){
			  		
			  		printf("Oops. That case is already taken ! Please try again.\n");
			  		k = 1;
		  		
			}
		 }
		  	
			break;
			
		   case '2':{
		  	
			 i = 0;
			 j = 1;
			  	
			 if(v[i][j] == 'X' || v[i][j] == 'O'){
			  		
			  printf("Oops. That case is already taken ! Please try again.\n");
			  k = 1;
			  		
			}
		 }
		   break;
		   
		   case '3':{
		  	
		  	i = 0;
		  	j = 2;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		  	
			break;
			
		   case '4':{
		  	
		  	i = 1;
		  	j = 0;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		 
		   break;
		   case '5':{
		  	
		  	i = 1;
		  	j = 1;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		  	
			break;
			
		   case '6':{
		  	
		  	i = 1;
		  	j = 2;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		   break;
		   
		   case '7':{
		  	
		  	i = 2;
		  	j = 0;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
	  	 }
		  	
			break;
			
		   case '8':{
		  	
		  	i = 2;
		  	j = 1;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
			break;
			
		   case '9':{
		  	
		  	i = 2;
		  	j = 2;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
		  	break;
		  		
			}
		 }
	    }
    }while(k == 1);
   
   v[i][j] = 'X';
}

void intro_player2(char v[3][3]){
	
	char aux;
	int i,j,k;
	
	
	do{
		
		do{
			
			printf("Pick your spot: ");
			fflush(stdin);
			scanf("%c", &aux);
			
			if(aux < '1' || aux > '9'){
				printf("Wrong number. Please try again.\n");
			}
			
		}while(aux < '1' || aux > '9');
		
		k = 0;
		
		switch(aux){
		 	
		  case '1':{
		  	
			  	i = 0;
			  	j = 0;
			  	
			  	if(v[i][j] == 'X' || v[i][j] == 'O'){
			  		
			  		printf("Oops. That case is already taken ! Please try again.\n");
			  		k = 1;
		  		
			}
		 }
		  	
			break;
			
		   case '2':{
		  	
			 i = 0;
			 j = 1;
			  	
			 if(v[i][j] == 'X' || v[i][j] == 'O'){
			  		
			  printf("Oops. That case is already taken ! Please try again.\n");
			  k = 1;
			  		
			}
		 }
		   break;
		   
		   case '3':{
		  	
		  	i = 0;
		  	j = 2;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		  	
			break;
			
		   case '4':{
		  	
		  	i = 1;
		  	j = 0;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		 
		   break;
		   case '5':{
		  	
		  	i = 1;
		  	j = 1;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		  	
			break;
			
		   case '6':{
		  	
		  	i = 1;
		  	j = 2;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
		   break;
		   
		   case '7':{
		  	
		  	i = 2;
		  	j = 0;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
	  	 }
		  	
			break;
			
		   case '8':{
		  	
		  	i = 2;
		  	j = 1;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
			}
		 }
			break;
			
		   case '9':{
		  	
		  	i = 2;
		  	j = 2;
		  	
		  	if(v[i][j] == 'X' || v[i][j] == 'O'){
		  		
		  		printf("Oops. That case is already taken ! Please try again.\n");
		  		k = 1;
		  		
		  	break;
		  		
			}
		 }
	    }
    }while(k == 1);
   
   v[i][j] = 'O';
}

void intro_AI(char v[3][3]){
	
	int i,j,k;
	
	srand(time(NULL));
	
	do{
		
	 	i = rand() % 3;	
	 	j = rand() % 3;
	 	k = 0;
    
    	if(v[i][j] == 'X' || v[i][j] == 'O'){
    	
    		k = 1;
    	
		}
		
	}while(k == 1);
	
	v[i][j] = 'O';
}
	
int check(char v[3][3]){
	
	
	if(v[0][0] == 'X' || v[0][0] == 'O'){
		
		if(v[0][0] == v[0][1] && v[0][0] == v[0][2]){
			
			if(v[0][0] == 'X'){
				
				return 0; //win
				
			}
			else{
				return 1; //lose
			}
			
		}
		
		if(v[0][0] == v[1][0] && v[0][0] == v[2][0]){
			
			if(v[0][0] == 'X'){
				
				return 0; 
				
			}
			else{
				return 1; 
			}
		
		}
		
	}
	
	
	if(v[2][2] == 'X' || v[2][2] == 'O'){
		
		if(v[2][2] == v[1][2] && v[2][2] == v[0][2]){
			
			if(v[2][2] == 'X'){
				
				return 0;
				
			}
			else{
				return 1;
			}
			
		}
		
		if(v[2][2] == v[2][0] && v[2][2] == v[2][1]){
			
			if(v[2][2] == 'X'){
				
				return 0; 
				
			}
			else{
				return 1; 
			}
		
			
		}
		
	}
	

	if(v[1][1] == 'X' || v[1][1] == 'O'){
		
		if(v[1][1] == v[0][1] && v[1][1] == v[2][1]){
			
			if(v[1][1] == 'X'){
				
				return 0; 
				
			}
			else{
				return 1; 
			}
			
			
		}
		
		if(v[1][1] == v[1][0] && v[1][1] == v[1][2]){
			
			if(v[1][1] == 'X'){
				
				return 0; 
				
			}
			else{
				return 1; 
			}
			
			
		}
		
		if(v[1][1] == v[0][2] && v[1][1] == v[2][0]){
			
			if(v[1][1] == 'X'){
				
				return 0; 
				
			}
			else{
				return 1; 
			}
			
			
		}
		
		if(v[1][1] == v[0][0] && v[1][1] == v[2][2]){
			
			if(v[1][1] == 'X'){
				
				return 0; 
				
			}
			else{
				return 1; 
			}

		}
		
	}
	
	
	return 2;
	
}

























