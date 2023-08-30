#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

int main()
{
	int polje[MAX][MAX], broj, max;
	int brojac, brojac2, brojac3, brojac4, brojac5;
	char oznaka;

	max = 0;

	printf("Upisite broj redaka/stupaca matrice > ");
	scanf("%d%c", &broj, &oznaka);

	printf("Upisite %dx%d clanova > ", broj, broj);
	for (brojac = 0; brojac < broj; brojac++)
	{
		for (brojac2 = 0; brojac2 < broj; brojac2++)
		{
			scanf("%d", &polje[brojac][brojac2]);
		}
	}

	for (brojac3 = 0; brojac3 < broj; brojac3++)
	{
		for (brojac4 = 0; brojac4 < broj; brojac4++)
		{
			if ((brojac3 == 0) || (brojac3 == broj - 1) || (brojac4 == broj - 1) || (brojac4 == 0))
			{
				if (polje[brojac3][brojac4] > max)
				{
					max = polje[brojac3][brojac4];
				}
			}
		}
	}
	printf("\nNajveca vrijednost u rubovima je: %d", max);


	return 0;
}