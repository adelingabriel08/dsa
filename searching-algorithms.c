// binary search => only for ordered arrays
void BinarySearch()
{
      int a[n]; /*the searching array*/
      int x; /*the searched element*/
      int left,right; /*the limits of the searching interval*/
      int m; /*the index of the selected element*/
      left=0; right=n;
      while(left<right){
           m=(left+right)/2;
           if(a[m]<x)
              left=m+1;
           else
              right=m;
      }
       if(right>=n)
            {/*the array doesn’t contain the searched element*/};
       if(right<n)
       if(a[right]==x)
          {/*the element was found*/}
       else {/*the array doesn’t contain the searched element*/}
}

/*interpolation search, just numbers*/
void InterpolationSearch(){
    int interpolation_search(element a[],int last, int x){
    int m,left,right;
    left=0;
    right=last-1; /*1.4.2.1.m*/
    do{
        m=left+((x-a[left].key)*(right-left))/
        (a[right].key-a[left].key);
        if (x>a[m].key) left=m+1;
        else right=m-1;
    }
    while((left<=right)&&(a[m].key!=x)&&(a[right].key!=a[left].key)
    &&(x>=a[left].key)&&(x<=a[right].key));
    if (a[m].key==x) return m;
    else return last;
}
