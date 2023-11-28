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

char tabuleiro[] = "123456789";

void print_tab() {
	printf("%c %c %c\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
	printf("%c %c %c\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
	printf("%c %c %c\n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);
}

void check (int position, int A, char B) {
	if (position < 1 || position > 9 || count(tabuleiro, B) != A) {
		printf("JOGA CERTO TROUXA"); 
		exit(-1);
	}
}		

bool checkwin() {
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



void replace (int position,char x) {
	for (int i = 0; i < strlen(tabuleiro); i++) {
		if (tabuleiro[i] == position + '0')
			tabuleiro[i] = x;
	}
}

int main () {
	int position;
	int X = 0;
	int O = 0;
	while (X < 5) {
		print_tab();
		printf("Declare posicao:");
		scanf("%d", &position);
		replace(position,'X');
		X++;
		check(position,X,'X');
		if (checkwin()){ 
			printf("Se ferrou O, X ganhou");
			break;
			}
		print_tab();
		printf("Declare posicao:");
		scanf("%d", &position);
		replace(position,'O');
		O++;
		check(position,O,'O');
		if (checkwin()) { 
			printf("Se ferrou X, O ganhou");
			break;
		} 
	} 
	return 0;
}

