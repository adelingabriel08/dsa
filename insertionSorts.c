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
