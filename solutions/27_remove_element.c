int removeElement(int* nums, int numsSize, int val) {
    if (!nums) {return 0;}
    int k = 0;
    for (int i =0; i<numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}
