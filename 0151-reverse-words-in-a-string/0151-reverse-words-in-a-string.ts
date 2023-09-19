function reverseWords(s: string): string {  
  return s.split(' ').filter(({length})=>length).reverse().join(' ');
};