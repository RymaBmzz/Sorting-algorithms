#include <stdio.h>
#include <stdlib.h>
#include <time.h>

   void fusion(double tableau[],int deb1,int fin1,int fin2)
        {
        double *table1;
        int deb2=fin1+1;
        int compt1=deb1;
        int compt2=deb2;
        int i;

        table1=malloc((fin1-deb1+1)*sizeof(double));


        for(i=deb1;i<=fin1;i++) //remplir la partie du tableau à trier dans table1
            {
            table1[i-deb1]=tableau[i];
            }

        for(i=deb1;i<=fin2;i++)  //faire le tri du tableau1
            {
            if (compt1==deb2)
                {
                break;
                }
            else if (compt2==(fin2+1))
                {
                tableau[i]=table1[compt1-deb1];
                compt1++;
                }
            else if (table1[compt1-deb1]<tableau[compt2])
                {
                tableau[i]=table1[compt1-deb1];
                compt1++;
                }
            else
                {
                tableau[i]=tableau[compt2];
                compt2++;
                }
            }
        free(table1);
        }

/*******************************************************************************/
    void tri_fusion_bis(double tableau[],int deb,int fin)
    {
        if (deb!=fin)
            {
            int milieu=(fin+deb)/2;
            tri_fusion_bis(tableau,deb,milieu);
            tri_fusion_bis(tableau,milieu+1,fin);
            fusion(tableau,deb,milieu,fin);
            }
    }


int main()
 {
   int size,i;
   double n,delta;
   clock_t t1,t2;
   double *tab;

   //n=204800000;
   n=1000;
   tab = malloc(n*sizeof(double));

   size=n;
   printf("remplir le tableau\n");
   //les element dans l'ordre

	/*for (i=0;i<size;i++)
	  {
	      tab[i] = i;
	  } */
	  //les elements dans l'ordre inverse
	 /* int j=n;
	  for(i=0;i<size;i++)
      {
       tab[i]=j;
       j--;
      } */
      //les elements aleatoirement
      for(i=0;i<size;i++)
       {
         tab[i]=rand() % (int)n;
       }

     t1=clock();
     tri_fusion_bis(tab,0,n);
	 t2=clock();
   delta= (double) (t2 - t1) / CLOCKS_PER_SEC;
   printf("\n le temps d'execution du tri est : %f   \n",delta);

    return 0;
   }
