/*Implementation of FindString*/
int find_string(type_string* sub, type_string* s) /*[4.2.1.g]*/
/*finds the first instance of sub in s and returns its position or 0 if no match has found*/
{
	 int mark; /*index in s for starting position of comparing */
	 int index_sub; /*index substring*/
	 int index_string; /*index string*/
	 int pos; /*position of sub in s*/
	 boolean stop; /*becomes true when the corresponding elements of s and sub become different */

 	 index_string= 1;
	 pos= 0;
	 do {
	 	index_sub= 1;
	 	mark= index_string; /*starting position of the current comparison*/
	 	stop= false;
	 	while ((!stop)&&(index_string<=s->length)&&
	 	(index_sub<=sub->length))
		 	if(s->string[index_string-1]==sub->string[index_sub-1])
			 {
				 index_string= index_string+1;
			 	index_sub= index_sub+1;
		 	}
			 else
				 stop= true; /*while*/
				 if (index_sub>sub->length)
					 pos= mark; /*matching*/
				 else
					 index_string= mark+1; /*non matching=>advance model*/
	 } while (!((pos>0)|| (index_string+sub->length-1>s->length))); /*do*/
 return pos;
}
/*find_string*/
----------------

/* Boyer-Moore search – C variant */
typedef unsigned char boolean; /*[4.3.4.d]*/
#define true (1)
#define false (0)
enum { 
  mmax = 20 /*maximum pattern length*/
  nmax = 200
 } /*maximum string length*/
int m; /*pattern length*/
int n; /*string length*/
char p[mmax]; /*pattern*/
char s[nmax]; /*text*/
int d[256]; /*displacements table*/

boolean bm_search(int* pos)
 {
    int i,j,k;
 	/*read string in s /*n=current string length*/
 	/*read pattern in p /*m = current pattern length

 	for(i=0; i<=255; i++) d[i]= m; /*initialize d table*/
 		for(j=0; j<=m-2; j++) d[p[j]]= m-j-1;/*pattern precompiling*/
 		i=m; 
		j=m; /*pattern search*/
 		while ((j>0)&&(i<=n))
 		{
			j= m;
 			k= i;
 			while ((j>0)&&(s[k-1]==p[j-1]))
 			{
 				k= k-1;
 				j= j-1;
 			} /*while*/
 			if (j>0)
 				i=i+d[s[i-1]];
 			} /*while*/
 		*pos=i-m; /*pos=k*/
 	return j==0;
 } /*bm_search*/
