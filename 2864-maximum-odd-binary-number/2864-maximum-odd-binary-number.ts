function maximumOddBinaryNumber(s: string): string {
  const count = s.split('').filter(x => x === '1').length;
  return '1'.repeat(count - 1) + '0'.repeat(s.length - count) + '1';
};