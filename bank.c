/*
Mahmoud Chahine
CIS 170 Section 02

This program will simulate a bank program
*/
#include<stdio.h>
#include<stdlib.h>
void displayMenu();
float getDeposit(float);
float getWithdrawal(float);
void displayBalance(float);
int main(){
	float balance=0;
	char choice, user;
	do {
	displayMenu();
	printf("\n");
	scanf("\n%c", &choice);
	if (choice=='q'||choice=='Q') {
		printf("Thank You!"); 
	break;
}
	switch(choice){
		case 'D': case 'd':
			balance=getDeposit(balance);
		break;
		case 'W': case 'w':
			balance=getWithdrawal(balance);
		break;
		case 'B': case 'b':
			displayBalance(balance);
		break;
		case 'q': case 'Q':
			printf("Thank You!");
		break;
		default:
			printf("Error invalid data");
		break;
}

	printf("\nWould you like to complete another transiction y/n: ");
	scanf("\n%c", &user);
	}while (user=='y'||user=='Y');
	return 0;
}

void displayMenu(){
	printf("\tWelcome to HFC Federal Credit Union !\n\tPlease select from the following menu:\nD:\tMake a deposit\nW:\tMake a widthdrawal");
	printf("\nB:\tCheck your account balance\nQ:\tTo quit");
}

float getDeposit(float balance){
	float deposit;
	do {
		printf("How much would you like to deposit: ");
		scanf("%f", &deposit);
		if (deposit<0){
			printf("Error you can't deposit negative value\n");
			continue;
		}
		balance=balance+deposit;
	return balance;
}while(deposit<0);
}

float getWithdrawal(float balance){
	float withdraw;
	do {
		printf("how much would you like to withdraw:  ");
		scanf("%f", &withdraw);
		if (withdraw<0){
			printf("Error you can't withdraw negative value\n");
			continue;
		}
		
		if (withdraw>balance) {
			printf("Insufficent funds\n");
			continue;
		}
	
		}while(withdraw<0 || withdraw>balance);	
		
		balance=balance-withdraw;
		
	return balance;
}

void displayBalance(float balance) {
	printf("Your current balance is %.2f\n", balance);
}
