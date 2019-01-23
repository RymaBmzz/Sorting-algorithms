#include <stdio.h>
#include <stdlib.h>
void triRapide(int *TAB[],int deb,int fin)
{
   int g = deb-1;
   int d = fin+1;
   int pivot = TAB[deb];
   int temp;
      if(deb >= fin)
        return 0;

      while(1)
      {
          do d--; while(TAB[d] > pivot);
          do g++; while(TAB[g] < pivot);
          if(g < d)
          {
               temp = TAB[g];
              TAB[g] = TAB [d];
              TAB[d]= temp;
          }
          else
            break;
      }


      triRapide(TAB,deb,d);
      triRapide(TAB,d+1,fin);

}
int main()
{
   int TAB[5]={25,13,34,31,42};
   int i;
   triRapide(TAB,0,4);
 for(i=0;i<5;i++)
  {
     printf("%d | ",TAB[i]);
  }
    return 0;
}
