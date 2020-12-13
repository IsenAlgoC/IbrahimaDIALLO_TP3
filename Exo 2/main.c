#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	unsigned int a = 2868838400;
	printf("Le nombre d'octets utilise pour representer le nombre entier : %d octets\n",sizeof(a)); // 4 octets
	printf("Le nombre de bits utilise pour representer le nombre entier : %d bits\n", 8 * sizeof(a)); // 32 bits
	for (i = 1; i <= 32; i++) { // cette boucle nous permet de arcours le nombre ecrit en binaire
		if (((a >> i) & 1) == 1) { // vérifie si le bit no i est a 1
			printf("bit %d : ON\n", i);
		}
		else (((a >> i) & 1) == 0); { // verifie si le bit no i est a 0
			printf("bit %d : OFF\n", i);
		}
	}
	printf("BYE !\n");
}