


int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // This will track the index for non-val elements

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }

    }
  return k;

}
