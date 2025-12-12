
void heapup(int *arr,int n){
    int i=n;
    while(i>0 && arr[i]>arr[(i-1)/2]){
        int temp=arr[i];
        arr[i]=arr[(i-1)/2];
        arr[(i-1)/2]=temp;
        i=(i-1)/2;
    }
}

void heapdown(int *arr,int n,int i){
    while(2*i+1<n){
        int lar=i,l=2*i+1,r=2*i+2 ;
        if(arr[lar]<arr[l]) lar =l;
        if(r<n && arr[lar]<arr[r]) lar =r;
        if(lar==i) break;
        int temp = arr[i];
        arr[i]=arr[lar];
        arr[lar]=temp;
        i = lar;
    }
}

void buildheap(int *arr,int n){
    for(int i=n/2 -1;i>=0;i--){
        heapdown(arr,n,i);
    }
}


int findKthLargest(int* nums, int numsSize, int k) {
    buildheap(nums,numsSize);
    int t;
    int n=numsSize;
    for(int i=0;i<k;i++){
        t=nums[0];
        nums[0]=nums[--n];
        heapdown(nums,n,0);
    }
    return t;
}