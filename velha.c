#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int count(const char *string, char token) {
	int count = 0;
	while (*string != '\0') {
		count += *string++ == token;
	}
	return count;
}

void print_tab(char tabuleiro[]) {
	printf("%c %c %c\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
	printf("%c %c %c\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
	printf("%c %c %c\n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
}

void check (int position, int A, char B,char tabuleiro[]) {
	if (position < 1 || position > 9 || count(tabuleiro, B) != A) {
		printf("JOGA CERTO TROUXA"); 
		exit(-1);
	}
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
	int X = 0;
	int O = 0;
	char tabuleiro[] = "123456789";
	while (X < 5) {
		print_tab(tabuleiro);
		printf("Declare posicao:");
		scanf("%d", &position);
		replace(position,'X',tabuleiro);
		X++;
		check(position,X,'X',tabuleiro);
		if (checkwin(tabuleiro)){ 
			printf("Se ferrou O, X ganhou \n");
			char repeat;
			printf("Jogar novamente? (S/N)");
			scanf(" %c", &repeat);
			if (repeat == 'S') {
				replace_tab(tabuleiro);
				X = 0;
				O = 0;
				continue;
			}
			else
				break;
			}
		print_tab(tabuleiro);
		printf("Declare posicao:");
		scanf("%d", &position);
		replace(position,'O',tabuleiro);
		O++;
		check(position,O,'O',tabuleiro);
		if (checkwin(tabuleiro)) { 
			printf("Se ferrou X, O ganhou\n");
			char repeat;
			printf("Jogar novamente? (S/N)");
			scanf(" %c", &repeat);
			if (repeat == 'S') {
				replace_tab(tabuleiro);
				X = 0;
				O = 0;
			}
			else
				break;
		} 
	}  
	return 0;
}

