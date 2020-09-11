int kmp(string &s, string &t) {
	int a = s.size();
	int b = t.size();

	string u = s + '#' + t;
	int pi[u.size()] = {0};
	int n = u.size();
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && u[i] != u[j]) j = pi[j - 1];
		if (u[i] == u[j]) ++j;
		pi[i] = j;
	}
	return *max_element(pi + a + 1, pi + n);

}
