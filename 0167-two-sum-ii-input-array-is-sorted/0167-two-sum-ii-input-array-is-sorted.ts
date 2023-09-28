function twoSum(numbers: number[], target: number): number[] {
  const len = numbers.length;
  let [slow, fast] = [0, len - 1];
  while (slow < fast) {
      const curr = numbers[slow] + numbers[fast];
      if (curr === target) return [slow + 1, fast + 1];
      else if (curr > target) fast -= 1;
      else slow += 1;
  }
  return [-1, -1];
};