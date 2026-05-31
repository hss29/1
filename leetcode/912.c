void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int*nums,int left,int right){
    int i=left+rand()%(right-left+1);
    int pivot=nums[i];
    swap(&nums[left],&nums[i]);
    
    i=left+1;
    int j=right;
    while(1){
        while(i<=j&&nums[i]<pivot) i++;
        while(i<=j&&nums[j]>pivot) j--;
        if(i>=j) break;
        swap(&nums[i],&nums[j]);
        j--;
        i++;
    }
    swap(&nums[left],&nums[j]);
    return j;
}

void quickSort(int*nums,int left,int right){
    int order=1;
    for(int i=left;i<right;i++){
        if(nums[i]>nums[i+1]){
            order=0;
            break;
        }
    }
    if(order)
    return;

    int i=partition(nums,left,right);
    quickSort(nums,left,i-1);
    quickSort(nums,i+1,right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    srand(time(NULL));
    quickSort(nums,0,numsSize-1);
    *returnSize=numsSize;
    return nums;    
}

//在215的基础上加一个优化，本质是一样的
//优化：如果数组本身是升序的，就不需要排序
