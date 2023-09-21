function productExceptSelf(nums: number[]): number[] {
  const { length: len } = nums;
  const products = new Array(len).fill(1);
  let [ prefix, postfix ] = [1, 1];
  
  for (let i = 0; i < len; i++) {
    products[i] *= prefix;
    products[len - 1 - i] *= postfix;
    prefix *= nums[i];
    postfix *= nums[len - 1 - i];
  }
  
  return products;
};
