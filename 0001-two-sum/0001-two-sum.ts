const twoSum = (nums: Array<number>, target: number): Array<number> => {
  const { length } = nums;
  const map = new Map();

  for (let i = 0; i < length; i++) {
    if (map.has(nums[i])) return [map.get(nums[i]), i];
    map.set(target - nums[i], i);
  }

  return [-1, -1];
}