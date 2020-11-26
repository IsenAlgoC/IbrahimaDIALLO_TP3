#include <stdio.h>
#include <stdlib.h>
#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	printf("%d", carre(Nb+1));
}

// le résultat obtenu est 11
// le probléme vient des paramétres insérés dans la macro
// pour régler ce probleme au lieu d'écrire #define carre(x) x*x
// j'écris #define carre(x) (x)*(x)