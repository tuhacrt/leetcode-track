function longestConsecutive(nums: number[]): number {
  if (nums.length === 0) return 0;
  let sort = [1];
  
  nums.sort((a, b) => a - b);
  nums.forEach((v, i, a) => {
    const diff = v - a[i - 1];
    if (diff === 0) sort;
    else if (diff === 1) sort[sort.length - 1]++;
    else sort.push(1);
  })
  return Math.max(...sort);
};