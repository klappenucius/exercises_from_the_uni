#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int karat, i, j, k;
	char zvjezdica = 42;
	char nista = 32;
	scanf("%d", &karat);

	if (karat % 2 != 0)
	{
		if (karat == 1)
		{
			printf("%c", zvjezdica);
		}
		else
		{
			for (i = 1; i <= karat; i += 2)
			{

                for (k = (karat - i)/ 2; k > 0; k --)
                {
                    printf("%c", nista);
                }
                for (j = 1; j <= i; j++)
                {

                    printf("%c", zvjezdica);

                }

                printf("\n");

			}

            for (i = karat - 2; i > 0; i -= 2)
			{
				for (k = 1; k < karat - i; k += 2)
                {
                    printf("%c", nista);
                }
				for (j = 1; j <= i; j++)
				{
					printf("%c", zvjezdica);

				}
                printf("\n");

            }

        }
    }
    else if (karat % 2 == 0)
    {
        printf("Pogreska: Zadani dijamant nije savrsen!");
    }

return 0;
}