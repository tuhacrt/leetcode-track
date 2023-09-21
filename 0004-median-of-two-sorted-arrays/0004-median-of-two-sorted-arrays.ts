function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
  const number = nums1.concat(nums2);
  number.sort((a, b) => a - b);
  const { length } = number;
  const half = Math.floor(length / 2);
  return length % 2 === 0 
    ? (number[half] + number[half - 1]) / 2 
    : number[half];
};