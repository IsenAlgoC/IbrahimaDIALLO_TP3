#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // bibliotheque qui nous permet d'utiliser la fonction "_getch()"
#include <ctype.h> // bibliotheque qui nous permet d'utiliser la fonction "toupper()"
#include <math.h> // bibliotheque qui nous permet d'utiliser "sqrt" et "pow"
#define NBMAXNOTES 30

int main() {
	int i;
	double note[NBMAXNOTES] = { -2 }, som = 0, moyenne;
	int NbNote = 0;
	int NbAbsence = 0;
	int reponse;
	double Note_Max = 0, Note_Min = 20;
	double ecart_type;

	/*====== Remplissage des notes ======*/
	for (i = 0; i < NBMAXNOTES; i++) {
		printf("Entrer la note no %d : ", i + 1);
		scanf_s("%lf", &note[i]);
		if (note[i] > 20 || note[i] < 0) {
			_cputs("Eleve absent? Ou voulez vous arreter la saisie des notes ? A/O/N\n");
			do {
				reponse = _getch();
				reponse = toupper(reponse);
			} while ((reponse != 'A') && (reponse != 'O') && (reponse != 'N'));

			switch (reponse) {
			case 'A':
				note[i] = -1;
				NbAbsence++;
				break;
			case 'N':
				NbNote++;
				printf("Veuillez ressaisir la note no %d : ", i + 1);
				scanf_s("%lf", &note[i]);
				som += note[i];
				break;
			case 'O':
				break;
			}
			if (reponse == 'O') {
				break;
			}
		}
		else {
			som += note[i];
			NbNote++;
		}
	}
	for (i = 0; i < (NbNote + NbAbsence); i++) {
		if (note[i] != -1) {
			if (note[i] > Note_Max) {
				Note_Max = note[i];
			}
			if (note[i] < Note_Min) {
				Note_Min = note[i];
			}
		}
		else {
			continue;
		}
	}
	moyenne = som / NbNote;
	printf("Le nombre de notes valides est de : %d\n\n", NbNote);
	printf("Le nombre d'absences est de : %d\n\n", NbAbsence);
	printf("La moyenne des notes valides est de : %.2lf\n\n", moyenne);
	printf("La plus grande note valide est de : %.2lf\n\n", Note_Max);
	printf("La plus petite note valide est de : %.2lf\n\n", Note_Min);
	
	/*====== Calcul de l'écart type ======*/
	float b;
	double a;
	double k = 0; // variable qui va contenir la somme de chaque note avec la moyenne eleve au carre
	
	b = (float)1 / (NbNote - 1); //Conversion de int en float pour pouvoir faire le calcul
	for (i = 0; i < (NbNote + NbAbsence); i++) {
		if (note[i] != -1) {
			a = (double)pow(note[i] - moyenne, 2); // on eleve au carre note[i] - moyenne
			k += a;
		}
		else {
			continue;
		}
	}

	ecart_type = sqrt(b * k); //on prend la racice carre de b*q
	printf("l'ecart type est de : %.2lf\n", ecart_type);

	for (i = 0; i < (NbNote + NbAbsence); i++) {
		printf("Numero Note : %d || Valeur note : %.2lf\n", i+1, note[i]);
	}

	/*===== Affichage des notes par ordre decroissant =====*/
	printf("\n\n");
	double copy_tab[NBMAXNOTES] = { -2 }; //copie du tableau de notes
	int idx[NBMAXNOTES] = { -2 }; //tableau qui contient les indices de chaque
	double tmp, tmp1; // variabes temporaire qui vont nous permettre de permuter les notes  
	for (i = 0; i < (NbNote - NbAbsence); i++) {
		copy_tab[i] = note[i];
		idx[i] = i + 1;
		
	}
	
	for (i = 0; i < (NbNote - NbAbsence); i++) {
		 for(int j = 0; j < (NbNote - NbAbsence -1 - i); j++){
			 if (copy_tab[j] < copy_tab[j + 1]) {
				 tmp = copy_tab[j];
				 copy_tab[j] = copy_tab[j + 1];
				 copy_tab[j + 1] = tmp;

				 tmp1 = idx[j];
				 idx[j] = idx[j + 1];
				 idx[j + 1] = tmp1;
			 }
		}
	}

	for (i = 0; i < (NbNote + NbAbsence); i++) {
		printf("Numero note : %d || Rang : %d || Valeur note : %.2lf\n",idx[i], i + 1, copy_tab[i]);
	}
}


