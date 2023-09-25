function findTheDifference(s: string, t: string): string {
  const reduceSum = (acc: number, cur: string) => acc + cur.charCodeAt(0);
  const sum1 = s.split('').reduce(reduceSum, 0);
  const sum2 = t.split('').reduce(reduceSum, 0);
  return String.fromCharCode(sum2 - sum1);
};