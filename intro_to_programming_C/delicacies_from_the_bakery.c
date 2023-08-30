#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 50

int main()
{
	FILE* file_in = NULL;
	file_in = fopen("pekara.txt", "r");
	int c, i;
	FILE* file_out = NULL;
	file_out = fopen("preporuka.txt", "w");
	char proizvod[25 + 1];
	char string[MAX];
	int slatkoilislano;
	int kalorije;
	float cijena;
	int mesno;
	i = 0;
	int min_kalorije;
	float min_cijena;
	min_cijena = 99.00;
	min_kalorije = 999;
	char najpogodniji[25 + 1];
	char enter;

	while ((c = fgets(string, 99, file_in)) != 0)	
			{
			sscanf(string, "%[^#]#%d#%d#%d#%f%c", proizvod, &slatkoilislano, &mesno, &kalorije, &cijena, &enter);
				if ((slatkoilislano == 1) && (kalorije < 150))
				{
					if (mesno == 0)
					{
						fprintf(file_out, "%d##%s##NE##%.2f\n", kalorije, proizvod, cijena);
					}
					else if (mesno == 1)
					{
						fprintf(file_out, "%d##%s##DA##%.2f\n", kalorije, proizvod, cijena);
					}
					if ((cijena < min_cijena)&& (kalorije < min_kalorije))
					{
						min_cijena = cijena;
						min_kalorije = kalorije;
						strcpy(najpogodniji, proizvod);

					}
					
				}
			

			}
	fprintf(file_out, "\nNajjeftiniji slani proizvod s najmanje kalorija je %s.", najpogodniji);

		fclose(file_in);
		fclose(file_out);
	
	return 0;
}