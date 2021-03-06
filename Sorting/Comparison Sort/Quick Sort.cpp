//Returns the Sorted vector after using QuickSort Method.





****************************************************************
///////Quicksort 3 Partition with median pivot//////////////////


struct twopoint
{
  int left;
  int right;
};

int medianlocation(vector<int> &vec,int a,int b,int c)
{
  if(vec[a]<=vec[b])
  {
    if(vec[b]<=vec[c])
      return b;
    if(vec[a]<=vec[c])
      return c;
    return a;
  }
  if(vec[c]<=vec[b])
    return b;
  if(vec[a]<=vec[c])
    return a;
  return c;
}

twopoint Partition(vector<int> &vec,int low,int high)
{
int pivotlocation = medianlocation(vec,low,high,low+(high-low)/2);
int pivot=vec[pivotlocation];
twopoint j;
j.left=pivotlocation;
j.right=pivotlocation;

for(int i=low;i<j.left;i++)
{
  if(vec[i]>=pivot)
  {
    swap(vec[i],vec[pivotlocation]);
    j.left=i;
    j.right=i;
    pivotlocation=i;
  }
}
for(int i=j.right+1;i<=high;i++)
{
  if(vec[i]==pivot)
  {
    j.right++;
    swap(vec[i],vec[j.right]);
  }
  if(vec[i]<pivot)
  {
    swap(vec[j.left],vec[i]);
    j.left++;
    i--;
  }
}

return j;
}


void QuickSort(vector<int> &vect,int left,int right)
{
  if(left>=right)
    return;
  twopoint part = Partition(vect,left,right);
  QuickSort(vect,left,part.left-1);
  QuickSort(vect,part.right+1,right);

}



***************************************************************
////////////////QuickSort Single Pivot///////////////////////// 


int Partition(vector<int> &vec,int low,int high)
{
int pivot=vec[low];
int j=low;
for(int i=low+1;i<=high;i++)
{
  if(vec[i]<=pivot)
  {
    j++;
    swap(vec[j],vec[i]);
  }
}
swap(vec[j],vec[low]);
return j;
}


void QuickSort(vector<int> &vect,int left,int right)
{
  if(left>=right)
    return;
  int part = Partition(vect,left,right);
  QuickSort(vect,left,part-1);
  QuickSort(vect,part+1,right);

}

****************************************************************
///////////////QuickSort Single Median Pivot////////////////////


int medianlocation(vector<int> &vec,int a,int b,int c)
{
  if(vec[a]<=vec[b])
  {
    if(vec[b]<=vec[c])
      return b;
    if(vec[a]<=vec[c])
      return c;
    return a;
  }
  if(vec[c]<=vec[b])
    return b;
  if(vec[a]<=vec[c])
    return a;
  return c;
}

int Partition(vector<int> &vec,int low,int high)
{
int pivotlocation = medianlocation(vec,low,high,low+(high-low)/2);
int pivot=vec[pivotlocation];
int j=pivotlocation;
for(int i=low;i<pivotlocation;i++)
{
  if(vec[i]>=pivot)
  {
    swap(vec[i],vec[pivotlocation]);
    pivotlocation=i;
    j=pivotlocation;
  }
}
for(int i=pivotlocation+1;i<=high;i++)
{
  if(vec[i]<=pivot)
  {
    j++;
    swap(vec[j],vec[i]);
  }
}

swap(vec[j],vec[pivotlocation]);
return j;
}


void QuickSort(vector<int> &vect,int left,int right)
{
  if(left>=right)
    return;
  int part = Partition(vect,left,right);
  QuickSort(vect,left,part-1);
  QuickSort(vect,part+1,right);

}

*************************************************************