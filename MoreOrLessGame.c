#include <stdio.h>
#include <stdlib.h>
#include <time.h> // creation de nombres random

void clean_stdin(void)
{
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int main(int argc, char *argv[])
{
	const int MIN = 1;
	int max;
	int nombreMystere;
	int monNombre = 0;
	int compteur;
	int continuerPartie = 1;
	int difficulte = 0;
	int choix = 0;
	srand(time(NULL)); // Ne pas le faire lire par le programme plus d'une fois !

	while (continuerPartie)
	{
		choix = 0;
		while (choix != 1 && choix != 2)
		{
			printf("Combien de Joueur 1 ou 2 ?\n");
			scanf("%d", &choix);

   			if (choix == 1)
    		{
    			difficulte = 0;
    			while (difficulte != 1 && difficulte != 2 && difficulte != 3)
    			{
    				printf("Mode 1 Joueur :\n");
    				printf("1 Facile (1 à 100)\n");
    				printf("2 Moyen (1 à 1000)\n");
    				printf("3 Difficile (1 à 10000)\n");
    				scanf("%d", &difficulte);
    				if (difficulte == 1)
    				{
    					max = 100;
    				}
    				else if (difficulte == 2)
    				{
    					max = 1000;
    				}
    				else if (difficulte == 3)
    				{
    					max = 10000;
    				}
    				else
    				{
    					printf("Choix incorrecte !\n");
    					clean_stdin();
    				}
    			}
    			nombreMystere = (rand() % (max - MIN + 1)) + MIN; // Creation d'un nombre random	
    		}
    		else if (choix == 2)
    		{
    			while (1 > nombreMystere || nombreMystere > 10000)
    			{
    				printf("Mode 2 Joueur :\n");
	    			printf("Entrez un nombre !\n");
    				scanf("%d", &nombreMystere);
                    if (1 < nombreMystere && nombreMystere < 10000)
                    {
                        system("clear");
                        printf("Trouver le nombre !\n");
                    }
                    else
                    {
                        printf("Nombre incorrecte !\n");
                        clean_stdin();
                    }
    			}    			
    		}
    		else
    		{
	    		printf("Choix incorrecte !\n");
	    		clean_stdin();
    		}
		}

		for (compteur = 1 ; monNombre != nombreMystere ; compteur++)
		{
			printf("Quel est le nombre ? ");
			scanf("%d", &monNombre);
			if (monNombre < nombreMystere)
			{
				printf("C'est plus !\n");
				clean_stdin();
			}
			else if (monNombre > nombreMystere)
			{
				printf("C'est moins !\n");
				clean_stdin();
			}
			else
			{
				printf("Bravo, le nombre mystere était %d!\n", nombreMystere);
				printf("Vous l'avez trouver en %d coups !\n", compteur);
			}
		}
		printf("Voulez-vous continuer ?\n");
		printf("1 Oui\n");
		printf("0 Non\n");
		scanf("%d", &continuerPartie);
	}

	return 0;
}
