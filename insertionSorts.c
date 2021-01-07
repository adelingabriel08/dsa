/*Sorting by straight insertion */
type_element a[n];
void SortingByInsertion()
 { 
 	int i,j;
 	type_element temp;
 	for(i=2;i<n;i++)
 	{
 		temp= a[i];
 		a[0]= a[i]; /*sentinel in position a[0]*/
 		j= i-1;
 		while(a[j].key>temp.key)
 		{
			 a[j+1]= a[j]; j= j-1; /*3.2.1.b*/
 		}
 		a[j+1]= temp; /*insertion*/
 	 }
 }
