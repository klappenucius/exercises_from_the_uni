#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX 20

int ucitaj_konfiguraciju()
{
	int x;
	//int i = 1;
	//while (i > 0)
	//{
		scanf("%d", &x);
		//if ((x >= 3) || (x <= 20))
		//{
			//break;
		//}
		if (x < 3)
		{
			printf("Premala dvorana za ispit");
			exit(0);
		}
		else if (x > 20)
		{
			printf("Prevelika dvorana za ispit");
			exit(0);
		}
		
	//}
	return x;
}

float izracun_udaljenosti(float x, float y)
{
	float d;
	d = sqrt((x * x) + (y * y));
	return d;
}

float pad_postotka(float x, float y)
{
	float postotak;
	postotak = x / (y * y);
	return postotak;
}


int main()
{
	int duljina, sirina, polozaj_nastavnika, strogoca, x, i, j, k, l, fiksni_i, fiksni_j;
	char oznaka;
	float udaljenost, znanje, a, b, dvorana[MAX][MAX];

	znanje = 0;
	duljina = ucitaj_konfiguraciju();
	sirina = ucitaj_konfiguraciju();

	scanf("%d", &polozaj_nastavnika);
	scanf("%d", &strogoca);
	if (polozaj_nastavnika > sirina)
	{
		printf("Nastavnik mora biti u predavaonici!");
		exit(0);
	}

	fiksni_i = 0;
	fiksni_j = 0;

	for (i = 0; i <= duljina; i++)
	{
		
		for (j = 0; j < sirina; j++)
		{
			if ((i == 0) && (j == polozaj_nastavnika - 1))
			{
				dvorana[i][polozaj_nastavnika - 1] = strogoca;
			}
			else if ((i == 0) && (j != polozaj_nastavnika - 1))
			{
				dvorana[i][j] = 0;
			}
			else
			{
			scanf(" %c", &oznaka);
			dvorana[i][j] = (int)oznaka;
			switch ((int)dvorana[i][j])
			{
			case 90:
				dvorana[i][j] = 90;
				break;
			case 88:
				dvorana[i][j] = 0;
				break;
			case 78:
				dvorana[i][j] = -30;
				break;
			case 72:
				dvorana[i][j] = 72;
				fiksni_i = i;
				fiksni_j = j;
				break;
			}

			}
				
		}
	}
	for (i = 0; i <= duljina; i++)
	{
		for (j = 0; j <= sirina; j++)
		{
			if (dvorana[i][j] != 72)
			{
				if (fiksni_i >= i)
				{
					a = fiksni_i - i;
				}
				else if (fiksni_i < i)
				{
					a = i - fiksni_i;
				}
				if (fiksni_j >= j)
				{
					b = fiksni_j - j;
				}
				else if (fiksni_j < j)
				{
					b = j - fiksni_j;
				}
				udaljenost = izracun_udaljenosti(a, b);
				switch ((int)dvorana[i][j])
				{
				case 90:
					znanje = 90;
					dvorana[i][j] = pad_postotka(znanje, udaljenost);
					break;
				case 0:
					znanje = 0;
					dvorana[i][j] = pad_postotka(znanje, udaljenost);
					break;
				case -30:
					znanje = -30;
					dvorana[i][j] = pad_postotka(znanje, udaljenost);
					break;
				}
				if (dvorana[i][j] == (float)strogoca)
				{
					znanje = ((float)strogoca * (-1));
					dvorana[i][j] = pad_postotka(znanje, udaljenost);
				}
				
				
			}
			else
			{
				dvorana[i][j] = 0;
			}
		}
	}
	float suma = 0;

	for (i = 0; i <= duljina; i++)
	{
		for (j = 0; j < sirina; j++)
		{
				suma += dvorana[i][j];
		}
	}
	if (suma < 0)
	{
		suma = 0;
	}
	else if (suma > 100)
	{
		suma = 100;
	}
	printf("Sanse za prolaz su %.2f%%", suma);

	return 0;
}