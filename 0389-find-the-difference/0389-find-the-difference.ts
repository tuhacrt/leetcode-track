function findTheDifference(s: string, t: string): string {
  const map = new Map();
  t.split('').forEach(x => map.set(x, (map.get(x) || 0) + 1));
  s.split('').forEach(x => map.get(x) === 1 
                      ? map.delete(x) 
                      : map.set(x, map.get(x) - 1));
  return [...map][0][0];
};