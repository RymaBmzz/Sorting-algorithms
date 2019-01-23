#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,i,j,min;
  printf("Donner la taille du tableau a trie \n");
  scanf("%d",&n);
  double x;
  double TAB[n];
  printf("Remplir le tableau\n");
  for(i=0;i<n;i++)
  {
      scanf("%lf",&TAB[i]);
  }
  for(i=0;i<n-1;i++)
  {
         min = i;
    for(j=i+1;j<n;j++)
    {
        if(TAB[j]<TAB[min])
        {
            min=j;
        }

    }
    if(min != i)
    {
        x=TAB[i];
        TAB[i]=TAB[min];
        TAB[min]=x;
    }
  }

  for(i=0;i<n;i++)
  {
     printf("%lf | ",TAB[i]);
  }
  return 0;
}
