#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void my_putchar(char c)
{
  write(1, &c, 1);
}

int total_width(int taille)//largeur des blocs
{
  int ligne = 4;
  int cpt_lignes; //compteur de ligne
  int nb_etoiles = 1;
  int etoiles_perdues = 2; //nombre d'étoile perdues entre deux blocs
  int nbBlocs = 0; //nombre de bloc à créer

 
  while (nbBlocs < taille)
          //0<1
    {
      cpt_lignes = 0;
      while (cpt_lignes < ligne)
        	{  //0<4
            //1<4
            //2<4
            //3<4
        	  nb_etoiles = nb_etoiles + 2;

            //1=1+2
            //3=3+2
            //5=5+2
            //7
        	  cpt_lignes++;
        	}
      ligne++;
            if (nbBlocs % 2 == 0)
              // Savoir si le on est sur un bloc pair
               
                {
                  etoiles_perdues = etoiles_perdues + 2;
                }
            nb_etoiles = nb_etoiles - etoiles_perdues;
            
                nbBlocs++;
   }
 return (nb_etoiles + etoiles_perdues - 2);

}

void mon_sapin(int taille)	
{
  int line = 4;
  int width = total_width(taille);// largeur
  int nbr_espaces = width / 2; // il y a 2 fois moins d'espaces que la largeur du dernier bloc a premier bloc
  int espaces = 0;
  int cpt_espaces;
  int etoiles_perdues = 2;
  int nbBlocs = 0; //compteur nombre de bloc
  int i;
  int nb_etoiles = 1;
  int j; //compteur des étoiles

  while (nbBlocs < taille)
    {
      if (nbBlocs % 2 == 0 && nbBlocs != 0)  // si le nombre de bloc est pair 
	    {
	      etoiles_perdues = etoiles_perdues + 2; // On perd 2 étoiles de plus tous les blocs pairs 
	    }
       
      i = 0;
      while(i < line)
            	{
            	   espaces = nbr_espaces - nb_etoiles / 2; 
            	   cpt_espaces = 0;
            	       while (cpt_espaces < espaces)
                	    {
                	      my_putchar(' ');
                   
                	      cpt_espaces++;
                	    }
                      	  j = 0;
                      	  while (j < nb_etoiles)
                      	    {
                      	      my_putchar('*');
                      	      j++;
                      	    }
                      	  my_putchar('\n');          	  
            	  if (i == line - 1) //pour vérifier si on est sur la dernière ligne puisque i=0
            	    nb_etoiles = nb_etoiles - etoiles_perdues;
            	  else
            	    nb_etoiles = nb_etoiles + 2; //incrèmente deux étoiles à chaque ligne
            	   i++;
            	}
      
      line++; //incrémente une ligne de plus à chaque nouveau bloc
      nbBlocs++;
    }
}


void tronc(int taille)
{
  int nbr_espaces;
  int cpt_hauteur = 0;
  int cpt_width= 0;
  int cpt_espaces = 0;
  int largeur = taille;
  int hauteur = taille;

  if (taille%2 == 0)
  {
    largeur = taille +1;
  }

  nbr_espaces = total_width(taille)/ 2 - (largeur/2);

  while(cpt_hauteur<hauteur)
  {
    cpt_hauteur++;
    cpt_espaces=0;
    while(cpt_espaces<nbr_espaces)
    {
      my_putchar(' ');
      cpt_espaces++;
    }
      cpt_width=0;
    while(cpt_width<largeur)
    {
      my_putchar('|');
      cpt_width++;
    }

    my_putchar('\n');
  }
}
  
  int	main(int argc, char **argv)
{
  
   if (argc != 2)
   return 1;

      int taille;
      taille = atoi(argv[1]);
       if (taille<1){

        printf("Impossible\n");
        return 1;
       }
       mon_sapin(taille);
       tronc(taille);
      
  return 0;
}
