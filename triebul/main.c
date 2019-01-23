#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,i,nbp;
  printf("Donner la taille du tableau a trie (Superieure a 2)\n");
  scanf("%d",&n);
  double x;
  double TAB[n];
  printf("Remplir le tableau\n");
  for(i=0;i<n;i++)
  {
      scanf("%lf",&TAB[i]);
  }
  do
    {
     nbp =0;
     for(i=0;i<n-1;i++)
     {
         if(TAB[i]>TAB[i+1])
         {
            x = TAB[i];
            TAB[i]=TAB[i+1];
            TAB[i+1]=x;
            nbp++;
         }
     }
    }while(nbp != 0);
//pour afficher le tableau triée
for(i=0;i<n;i++)
  {
      printf("%lf  |",TAB[i]);
  }
    return 0;
}
