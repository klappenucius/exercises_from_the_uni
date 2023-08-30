#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void trazi_let(float iznos);

int main()
{
	float iznos;
	scanf("%f", &iznos);
	trazi_let(iznos);
	
	return 0;
}

void trazi_let(float iznos)
{
	FILE* cijene = NULL;
	cijene = fopen("cijene.dat", "rb");
	FILE* letovi = NULL;
	letovi = fopen("letovi.txt", "r");

	if (cijene == NULL || letovi == NULL)
	{
		printf("Nije moguce otvoriti datoteku");
		exit(1);
	}

	struct let {
		char sifra[6 + 1];
		float cijena;
	};

	struct let niz_cijene[6];
	char string[50];

	int c, i, j;
	for (i = 0; i < 6; i++)
	{
		fread(&niz_cijene[i], sizeof(struct let), 1, cijene);
		//printf("%d %s %.2f\n", i + 1, niz_cijene[i].sifra, niz_cijene[i].cijena);
		//fread(string, sizeof(string), strlen(string), cijene);
		//sscanf(string, "6%c, %.f", niz_cijene[i].sifra, &niz_cijene[i].cijena);
	}

	struct destinacija {
		char polaziste[100 + 1];
		char odrediste[100 + 1];
		char sifra_leta[6 + 1];
	};

	struct destinacija niz_letovi[6];
	

	char buffer[500];

	float novac = iznos;
	i = 0;
	while ((c = fgets(buffer, 500, letovi)) != 0)
	{
		sscanf(buffer, "%[^#]#%[^#]#%[^\n]", niz_letovi[i].polaziste, niz_letovi[i].odrediste, niz_letovi[i].sifra_leta);
		i++;
	}

	for (i = 0; i < 6; i++)
	{
		if (niz_cijene[i].cijena <= novac)
		{
			for (j = 0; j < 6; j++)
			{
				if (strcmp(niz_cijene[i].sifra, niz_letovi[j].sifra_leta) == 0)
				{
					printf("%s - %s\n", niz_letovi[j].polaziste, niz_letovi[j].odrediste);
					
				}
				//novac = novac - niz_cijene[i].cijena;
				
			}
		}
	}



	fclose(cijene);
	fclose(letovi);
	

}