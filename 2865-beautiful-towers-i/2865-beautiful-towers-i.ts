function maximumSumOfHeights(maxHeights: number[]): number {
  const n = maxHeights.length;
  let ans = 0;
  
  maxHeights.forEach((x, i) => {
    let cur = x;
    let v = x;
    
    for (let j = i - 1; j >= 0; j--) {
      v = Math.min(v, maxHeights[j]);
      cur += v;
    }
    
    v = x;
    
    for (let j = i + 1; j < n; j++) {
      v = Math.min(v, maxHeights[j]);
      cur += v;
    }
    ans = Math.max(ans, cur);
  })
  
  return ans;
};