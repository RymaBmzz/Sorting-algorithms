#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void heapsort(double a[],int n) {
	int i,t;
	heapify(a,n);
	for (i=n-1;i>0;i--) {
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		adjust(a,i);
	}
}
void heapify(double a[],int n) {
	int k,i,j,item;
	for (k=1;k<n;k++) {
		item = a[k];
		i = k;
		j = (i-1)/2;
		while((i>0)&&(item>a[j])) {
			a[i] = a[j];
			i = j;
			j = (i-1)/2;
		}
		a[i] = item;
	}
}
void adjust(double a[],int n) {
	int i,j,item;
	j = 0;
	item = a[j];
	i = 2*j+1;
	while(i<=n-1) {
		if(i+1 <= n-1)
		   if(a[i] <a[i+1])
		    i++;
		if(item<a[i]) {
			a[j] = a[i];
			j = i;
			i = 2*j+1;
		} else
		   break;
	}
	a[j] = item;
}
main() {
	int i,j;
    int randomValue;
    double n,delta;
      clock_t t1,t2;
	    n=6400000;
   double *tab;
   tab = malloc(n*sizeof(double));
       int size=n;
	//les element dans l'ordre

	/*for (i=0;i<size;i++)
	  {
	      tab[i] = i;
	  }*/
	  //les elements dans l'ordre inverse
	   /*j=n;
	  for(i=0;i<size;i++)
      {
       tab[i]=j;
       j--;
      }*/
      //les elements aleatoirement
      for(i=0;i<size;i++)
       {
         tab[i]=rand() % (int)n;
       }
     /* printf("\nles element avant le tri:\n\n");
      for (i=0;i<n;i++)
	  printf("\t%lf",tab[i]);
	  printf("\n\n");*/
     t1=clock();
     heapsort(tab,n);
	 t2=clock();
   delta= (double) (t2 - t1) / CLOCKS_PER_SEC;
   printf("\n le temps d'execution du tri est : %f   \n",delta);
	/*printf("\nles elements apres le trie:\n");
	for (i=0;i<n;i++)
	  printf("\t%lf",tab[i]);
	printf("\n");*/
return 0;
}

