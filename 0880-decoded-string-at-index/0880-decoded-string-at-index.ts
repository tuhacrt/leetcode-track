function decodeAtIndex(s: string, k: number): string {
  const n = s.length;
  let K = BigInt(k);
  let size = BigInt(0);
  
  for (let c of s.split('')) {
    if (c.match(/\d/)) size = size * BigInt(c);
    else size++;
  }
  console.log(size);
  
  for (let i = n - 1; i >= 0; --i) {
    const c = s[i];
    K %= size;
    if (K === BigInt(0) && c.match(/[a-z]/)) return c;
    
    if (c.match(/\d/)) size /= BigInt(c);
    else size--;
  }
  
  return '';
};

