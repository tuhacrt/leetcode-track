function isSubsequence(s: string, t: string): boolean {
  const [m, n] = [s.length, t.length];
  if (m===0 && n ===0) return true;
  let c = 0;
  for (let i = 0; i < n; i++) { 
    if (t[i] === s[c]) {
      c++;
    }
    if (c === m) return true;
  }
  return false;
};