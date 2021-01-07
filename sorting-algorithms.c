/*Sorting by straight insertion */
void straight_insertion(int a[],int n)
{
	for(int i=n-2;i>=0;i--)
	{
 		a[n]=a[i]; /*sentinel on position a[n]*/
 		int j=i+1;
 		while(a[j]<a[n])
 		{
			 a[j-1]=a[j]; j++; /*3.2.1.e*/
		 }
 			 a[j-1]=a[n]; /*insertion*/
	}
}

/* Sorting by binary insertion */
void sorting_by_binary_insertion()
{
 	type_element a[n];
 	type_index i,j,left,right,m;
 	type_element temp;
 	for(i=2;i<=n;i++)
 	{
		 temp= a[i]; left= 1; right= i-1;
 		while(left<=right)
 		{ 
 			m= (left+right)/ 2;
 			if (a[m].key>temp.key)
 				right= m-1;
 			else
 				left= m+1;
		} /*while*/
 		for(j=i-1;j>=left;j--) a[j+1]= a[j];
			 a[left]= temp;
 	} /*for*/
} /* Sorting_by_binary_insertion */

/* Sorting by straight selection – C variant */
void sorting_by_selection()
{
	 type_element a[n];
 	type_index i,j,min;
 	type_element temp;
 	for(i=0;i<=n-2;i++)
	{
 		min= i;
		temp= a[i];
 		for(j=i+1;j<=n-1;j++) /*find the smallest item*/
 			if(a[j].key<temp.key) /*3.2.2.b*/
 			{
				min=j;
				temp=a[j]; /*selection*/
 			}
 		a[min]= a[i]; 
		a[i]= temp; /*interchange*/
	 }
} /*sorting_by_selection*/

/* Sorting by exchange: Bubblesort - Variant 1 - C*/
void bubblesort()
{
 	type_element a[n];
 	int i,j;
 	type_element temp;
 	for(i=1;i<=n-1;i++)
 	{ /*3.2.3.a*/
 		for(j=n-1;j>=i;j--)
 			if (a[j-1].key>a[j].key)
 			{
		 		temp= a[j-1]; 
				a[j-1]= a[j]; 
				a[j]= tem;
 			}
 	}
} /*bubblesort*/

/* Sorting by exchange - Variant 3*/
void shakersort()
{
 	type_element a[n];
 	int j,last,up,down;
 	type_element temp;
 	up= 1; 
	down= n-1; 
	last= n-1; /*3.2.3.c*/
 	do {
 		for(j=down;j>=up;j--)
 		if (a[j-1].key>a[j].key) /*down->up*/
 		{
 			temp= a[j-1]; 
			a[j-1]= a[j];
			a[j]= temp;
 			last= j;
 		} /*for*/
 		up= last+1; /*up limit*/
 		for(j=up;j<=down;j++) /*up->down*/
 			if (a[j-1].key>a[j].key)
 			{
 				temp=a[j-1]; 
				a[j-1]=a[j]; 
				a[j]=temp;
 				last=j;
 			} /*for*/
 			down=last-1; /*down limit*/
 	} while (!(up>down));
} /*shakersort*/

/*Shellsort (Sedgewick variant) – C implementation*/
void shellsort1()
{
 	type_element a[n];
 	int i,j,h;
 	type_element temp;
 	h= 1;
 	do {
 		h=3*h+1;
 	} while(!(h>n)); /*the maximum increment*/
 	do {
 		h= h/3; /*the current increment*/
 		for(i=h+1;i<=n;i++) /*3.2.4.c*/
 		/*sorting by insertion with increment h*/
 		{
 			temp= a[i]; j= i;
			while((a[j-h].key>temp.key) && (j>h))
 			{
 				a[j]= a[j-h]; 
				j= j-h;
 			} /*while*/
 			a[j]= temp;
		} /*for*/
	} while(!(h==1));
} /*shellsort1*/

/* Heapsort */
void heapsort();
static void sift1(int* left, type_element* temp, int* right)
{
 	int i,j;
 	boolean ret;  // de cand avem boolean in c? =)))))
 	i=*left; 
	j= 2*i; 
	*temp= h[i]; 
	ret= false;
 	while ((j<=*right) && (!ret))
 	{
 		if (j<*d)
 		if (h[j].key<h[j+1].key) j= j+1;
 		if (temp->key<h[j])
 		{
 			h[i]= h[j]; 
			i= j; 
			j= 2*i;
 		}
 		else
 			ret= true;
	} /*while*/
 	h[i]= *temp;
} /*shift1*/
void heapsort()
{
 	int left,right;
 	type_element temp;
 	/* heap generating phase*/
 	left= (n/2)+1; 
	right= n; /*[3.2.5.f]*/
 	while (left>1)
 	{
 		left= left-1;
		sift1(&left, &temp, &right);
	} /*while*/
	/* heap sorting phase*/
	while (right>1)
 	{
 		temp= h[1]; 
		h[1]= h[right]; 
		h[right]= temp;
 		right= right-1;
		sift1(&left, &temp, &right);
 	} /*while*/
} /*heapsort*/

/* Quicksort */
void quicksort(int left,int right) { 
	//globals: int a[],int n
	int i=left,j=right,x=a[(left+right)/2];
	do { //partitioning the current interval left, right
 		while(a[i]<x)i++;
 		while(a[j]>x)j--;
 		if(i<=j) {
 			int temp=a[i]; //[3.2.6.e]
 			a[i]=a[j];
 			a[j]=temp;
 			i++;
			j--;
 		}
	} while(i<=j);
	if(left<j)
		quicksort(left,j); //process left interval
	if(right>i)
		quicksort(i,right); //process right interval
}/* Quicksort */

/* Straight radix sort – C variant */
void straight_radix() 
 {
	/*globals a[n],t[n];*/
 	int i,j,pass;
 	int count[m1]; /*m1:=2m
*/

 	/*sorting process requires b/m passes*/
 	for(pass=0;pass<=(b/m)-1;pass++)
 	{ 
 		/*initialize counters for the current pass*/
 		for(j=0;j<=m1-1;j++) count[j]= 0;
 		/*determine distribution counting for the current pass*/
 		for(i=1;i<=n;i++)
 			count[bits(a[i].key,pass*m,m)] = count[bits(a[i].key,pass*m,m)]+1;
 		/*adjust the counters for the current pass*/
 		for(j=1;j<=m1-1;j++)
 			count[j] = count[j-1]+count[j];
 		/*sort by distribution counting in t for the current pass*/
 		for(i=n-1;i>=1;i--)
 		{
 			t[count[bits(a[i].key,pass*m,m)]-1] = a[i];
 			count[bits(a[i].key,pass*m,m)] = count[bits(a[i].key,pass*m,m)]-1;
 		}
 		/*recopy the array t in a*/
 		for(i=0;i<=n-1;i++) a[i] = t[i];
 	}
 } /*straight_radix sort*/

