#include <stdio.h>
#include <stdlib.h>
#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	printf("%d", carre(Nb+1));
}

// le r�sultat obtenu est 11
// le probl�me vient des param�tres ins�r�s dans la macro
// pour r�gler ce probleme au lieu d'�crire #define carre(x) x*x
// j'�cris #define carre(x) (x)*(x)