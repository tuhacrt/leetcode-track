function sortArrayByParity(nums: number[]): number[] {
  const { length: n } = nums; 
  const res = Array.of<number>();
  
  nums.forEach(v => v % 2 === 0 ? res.unshift(v) : res.push(v));
  
  return res;
};