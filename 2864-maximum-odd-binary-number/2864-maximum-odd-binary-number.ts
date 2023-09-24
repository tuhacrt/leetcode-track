function maximumOddBinaryNumber(s: string): string {
  const count = s.match(/1/g).length;
  return '1'.repeat(count - 1) + '0'.repeat(s.length - count) + '1';
};