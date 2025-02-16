#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if (nums1Size < m+n || nums2Size < n || n == 0){
        return;
    } else if (m == 0) {
        memcpy(nums1, nums2, n * sizeof(int));
        return;
    }

    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while (i>= 0 || j >= 0) {
        if (j<0) {
            nums1[k] = nums1[i];
            i--;
        } else if (i < 0) {
            nums1[k] = nums2[j];
            j--;
        } else if (nums1[i] >= nums2[j]) {
            nums1[k] = nums1[i];
            i --;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}
