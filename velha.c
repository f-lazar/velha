#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void print_tab(char tabuleiro[]) {
	printf("%c %c %c\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
	printf("%c %c %c\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
	printf("%c %c %c\n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
}

bool check (int position, char tabuleiro[]) {
	int num = position - 1;
	return (
	(position < 1) || 
	(position > 9) || 
	(tabuleiro[num]=='X') ||
	(tabuleiro[num] == 'O')
	);
}		

bool checkwin(char tabuleiro[]) {
	return( 
	(tabuleiro[0] == tabuleiro[1] && tabuleiro [1] == tabuleiro[2]) ||
	(tabuleiro[3] == tabuleiro[4] && tabuleiro [4] == tabuleiro[5]) ||
	(tabuleiro[6] == tabuleiro[7] && tabuleiro [7] == tabuleiro[8]) ||
	(tabuleiro[0] == tabuleiro[3] && tabuleiro [3] == tabuleiro[6]) ||
	(tabuleiro[1] == tabuleiro[4] && tabuleiro [4] == tabuleiro[7]) ||
	(tabuleiro[2] == tabuleiro[5] && tabuleiro [5] == tabuleiro[8]) ||
	(tabuleiro[8] == tabuleiro[4] && tabuleiro [4] == tabuleiro[0]) ||
	(tabuleiro[6] == tabuleiro[4] && tabuleiro [1] == tabuleiro[2]) 
	);
} 

void replace (int position,char x, char tabuleiro[]) {
	for (int i = 0; i < strlen(tabuleiro); i++) {
		if (tabuleiro[i] == position + '0')
			tabuleiro[i] = x;
	}
}

void replace_tab (char tabuleiro[]){
	for(int i=0; i <= 8;) {
		tabuleiro[i] = i+'1';
		i++;
	}
} 

int main () {
	int position;
	char tabuleiro[] = "123456789";
	char token = 'X';
	while (true) {
		print_tab(tabuleiro);
		if (checkwin(tabuleiro)){ 
			if (token == 'O')
				printf("Se ferrou O, X ganhou \n");
			else 
				printf("Se ferrou X, O ganhou\n");
			char repeat;
			printf("Jogar novamente? (S/N)");
			scanf(" %c", &repeat);
			if (repeat == 'S') {
				replace_tab(tabuleiro);
				token = 'X';
				continue;
			} 
			else
				break;
		} 
		printf("Declare posicao:");
		scanf(" %d", &position);
		while (check(position,tabuleiro)== true) { 
			printf("JOGA DIREITO TROUXA, que posicao tu que:");
			scanf(" %d", &position);
		} 
		replace(position,token,tabuleiro);
		if (token == 'X') 
			token = 'O';
		else
			token = 'X';
	}   
	return 0;
}

