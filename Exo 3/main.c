#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define NBMAXNOTES 30

int main() {
	int i = 1, k;
	float note = 0, som = 0, moyenne;
	int NbNote = 0;
	int NbAbsence = 0;
	int reponse;
	float note1;
	/*while (note >= 0 && note <= 20 && i <= 30) {
		printf("Entrer la note no %d : ", i);
		scanf_s("%f", &note);
		i++;
		NbNote++;
		som += note;
	}*/

	printf("Vous avez arrete la saisie. L'eleve est il Absent ou souhaitez vous arreter la saisie ? Oui Non : \n");
	reponse = _getch();
	switch (reponse)
	{
	case 'A':
		NbAbsence += 1;
		break;
	case 'N':
		printf("tb");
		break;
	case 'O':
		break;
	default:
		printf("ohhhhhhhhhhh");
		break;
	}
	float note[NBMAXNOTES];


}


