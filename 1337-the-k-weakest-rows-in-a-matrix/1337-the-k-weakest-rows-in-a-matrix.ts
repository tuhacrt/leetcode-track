function kWeakestRows(mat: number[][], k: number): number[] {
  const counts = Array(mat.length).fill([0, 0]);
  mat.forEach((r, i) => counts[i] = [i, r.reduce((acc, cur) => acc += cur)], 0);
  counts.sort(([ai, ac], [bi, bc]) => ac !== bc ? ac - bc : ai - bi);
  return counts.slice(0, k).map(([i,_]) => i);
};