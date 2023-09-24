const last = <T>(xs: Array<T>) => xs.length ? xs[xs.length - 1] : -1;

function maximumSumOfHeights(maxHeights: number[]): number {
  const n = maxHeights.length;
  const left = new Array(n + 1).fill(0);
  let stack = [-1];
  let [res, cur] = [0, 0];
  
  maxHeights.forEach((x, i) => {
    while (stack.length > 1 && x <= maxHeights[last(stack)]) {
      let j = stack.pop();
      cur -= maxHeights[j] * (j - last(stack));
    }
    cur += x * (i - last(stack));
    stack.push(i);
    left[i] = cur;
  })
  
  stack = [n];
  cur = 0;
  for (let i = n - 1; i >= 0; i--) {
    const x = maxHeights[i];
    while (stack.length > 1 && x <= maxHeights[last(stack)]) {
      let j = stack.pop();
      cur -= maxHeights[j] * -(j - last(stack));
    }
    cur += x * -(i - last(stack));
    stack.push(i);
    res = Math.max(res, left[i] + cur - maxHeights[i]);
  }
  
  return res;
};