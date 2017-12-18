//Returns the index of key if found in already sorted vector, returns -1 if not found//



int BinarySearchRecursive(vector<int> &vect,int low,int high,int key)
{
    if(high<low)
        return -1;
    int mid = low  + (high-low)/2;
    if(vect[mid]==key)
        return mid;
    else if(key<vect[mid])
    {
        BinarySearchRecursive(vect,low,mid-1,key);
    }
    else
    {
        BinarySearchRecursive(vect,mid+1,high,key);
    }
}

int BinarySearchIterative(vector<int> &vect,int low,int high,int key)
{
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(vect[mid]==key)
            return mid;
        else if(key<mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
