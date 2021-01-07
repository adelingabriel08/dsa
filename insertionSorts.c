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

