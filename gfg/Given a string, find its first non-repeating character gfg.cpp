char nonrepeatingCharacter(string s)
{
  int n = s.size();
  vector<int>alpha(26, 0);
  for (int i = 0; i < n; i++) {
    alpha[(int)s[i] - 97]++;
  }

  for (int i = 0; i < n; i++) {
    if (alpha[(int)s[i] - 97] == 1) {
      return s[i];
    }
  }
  return '$';
}
