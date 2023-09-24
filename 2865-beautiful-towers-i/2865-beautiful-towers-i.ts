const atEnd = <T>(xs: Array<T>): T => xs[xs.length - 1];

function maximumSumOfHeights(maxHeights: number[]): number {
  const n = maxHeights.length;
  const suffix = new Array(n + 1).fill(0);
  let mq = [n]
  let s = 0;
  
  for (let i = n - 1; i > 0; i--) {
    const x = maxHeights[i];
    
    while (mq.length > 1 && x <= maxHeights[atEnd(mq)]) {
      let j = mq.pop();
      s -= maxHeights[j] * (atEnd(mq) - j) // revert the add before
    }
    s += x * (atEnd(mq) - i); // i to mq[mq.length - 1] - 1 are valued x;
    suffix[i] = s;
    mq.push(i);
  }
  
  let ans = s;
  mq = [-1]
  let prefix = 0;
  
  maxHeights.forEach((x, i) => {
    while (mq.length > 1 && x <= maxHeights[atEnd(mq)]) {
      let j = mq.pop();
      prefix -= maxHeights[j] * (j - atEnd(mq));
    }
    prefix += x * (i - atEnd(mq));
    ans = Math.max(ans, prefix + suffix[i + 1]);
    mq.push(i)
  })
  
  return ans;
};