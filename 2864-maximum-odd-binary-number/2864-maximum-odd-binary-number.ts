const count =  (xs: Array<string>, y: string) => {
  return xs.filter(x => x === y).length;
}

function maximumOddBinaryNumber(s: string): string {
  const ctn1 = count(s.split(''), '1');
  return Array(ctn1 - 1).fill('1').join('') + 
         Array(s.length - ctn1).fill('0').join('') + 
         '1';
};