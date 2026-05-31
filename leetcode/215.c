void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int*nums,int left,int right){
    int i=left+rand()%(right-left+1);

    int pivot=nums[i];
    swap(&nums[i],&nums[left]);

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

int findKthLargest(int* nums, int numsSize, int k) {
    srand(time(NULL));
    int left=0,right=numsSize-1;
    int target=numsSize-k;

    while(1){
        int i=partition(nums,left,right);
        if(i==target) return nums[i];
        if(i>target) right=i-1;
        else
        left=i+1;
    }
}

//基准值就是最终的目标值，只是要看基准点随即情况，也许一次，也许n次
//左边<=pivot,右边>=pivot。 所以基准的位置是相对数组升序之后的准确位置
//只是基准的左边和右边也许是乱序的
//因为大体是按照升序排的，所以找第k大，就是找第numSize-k小。
//循环执行，类似二分查找，每次缩小范围，i<target去右边找，i>target去左边找
