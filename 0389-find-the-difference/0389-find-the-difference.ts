function findTheDifference(s: string, t: string): string {
  let char = 0;
  s.split('').forEach(x => char ^= x.charCodeAt(0));
  t.split('').forEach(x => char ^= x.charCodeAt(0));
  return String.fromCharCode(char);
};