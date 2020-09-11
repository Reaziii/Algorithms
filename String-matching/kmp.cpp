vector<int> kmp(string &s) {
	n = s.size();
	vector<int> pi(n + 10, 0);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) ++j;
		pi[i] = j;
	}
	pi.insert(pi.begin(), 0);
	return pi;
}
