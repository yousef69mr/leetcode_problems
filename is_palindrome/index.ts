function isPalindrome(s: string): boolean {
  const trimedStr = s
    .replaceAll(/[^a-zA-Z0-9]/g, "")
    .toLocaleLowerCase()
    .trim();

  if (trimedStr === "") {
    return true;
  }

  let i,
    j,
    mid = trimedStr.length / 2;

  for (i = 0, j = trimedStr.length - 1; i <= mid && j >= mid; i++, j--) {
    if (trimedStr[i] !== trimedStr[j]) {
      return false;
    }
  }
  console.log(trimedStr);
  return true;
}

isPalindrome("A man, a plan, a canal: Panama");
isPalindrome("race a car");
isPalindrome("0P");
