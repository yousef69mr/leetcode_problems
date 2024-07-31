function isSubsequence(s: string, t: string): boolean {
  let i,
    j = 0;

  if (s.length === 0) return true;
  if (t.length === 0) return false;

  for (i = 0; i < t.length; i++) {
    if (s[j] === t[i]) {
      j++;

      if (j === s.length) {
        return true;
      }
    }
  }

  return false;
}

console.log(isSubsequence("abc", "ahbgdc"));
console.log(isSubsequence("axc", "ahbgdc"));
