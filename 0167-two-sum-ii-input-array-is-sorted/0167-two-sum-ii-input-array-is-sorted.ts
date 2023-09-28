function twoSum(nums: number[], target: number): number[] {
  const { length: n } = nums;
  let [l, r] = [0, n - 1];
  
  while (l < r) {
    const curr = nums[l] + nums[r];
    
    if (curr === target) return [l + 1, r + 1];
    
    if (curr < target) l++;
    else r--;
  }
  
  return [-1, -1];
};