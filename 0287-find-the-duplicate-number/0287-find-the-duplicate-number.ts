function findDuplicate(nums: number[]): number {
  let [slow, fast] = [nums[0], nums[nums[0]]];
  
  while (slow !== fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }
  
  slow = 0;
  
  while (slow !== fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  
  return slow;
};