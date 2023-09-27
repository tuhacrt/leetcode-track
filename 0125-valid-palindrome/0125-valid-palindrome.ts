function isPalindrome(s: string): boolean {
  const parsed = s.toLowerCase().split('').filter(x => x.match(/[a-zA-Z0-9]/g));
  return parsed.join('') === parsed.reverse().join('');
};