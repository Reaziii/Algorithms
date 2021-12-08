
class segment_tree_with_lazy {

	long st[4000000];
	long lz[400000];

public :
	void update(int n, int s, int e, int qs, int qe, long long val) {
		if (lz[n]) {
			long l = lz[n];
			lz[n] = 0;
			st[n] += l * (e - s + 1);
			if (s != e)
				lz[n * 2] += l, lz[n * 2 + 1] += l;
		}
		if (e < qs || s > qe) return ;
		if (s >= qs && e <= qe) {
			long l = (e - s + 1) * val;
			st[n] += l;
			if (s != e)
				lz[n * 2] += val, lz[n * 2 + 1] += val;
			return ;

		}
		int mid = (s + e) / 2;
		update(n * 2, s, mid, qs, qe, val);
		update(n * 2 + 1, mid + 1, e, qs, qe, val);
		st[n] = st[n * 2] + st[n * 2 + 1];
	}


	long long query(int n, int s, int e, int qs, int qe) {
		if (lz[n]) {
			long l = lz[n];
			lz[n] = 0;
			st[n] += l * (e - s + 1);
			if (s != e)
				lz[n * 2] += l, lz[n * 2 + 1] += l;
		}
		if (e < qs || s > qe) return 0;
		if (s >= qs && e <= qe) {
			return st[n];
		}
		int mid = (s + e) / 2;

		return query(n * 2, s, mid, qs, qe) + query(n * 2 + 1, mid + 1, e, qs, qe);

	}

	void clear() {
		memset(st, 0, sizeof(st));
		memset(lz, 0, sizeof(lz));
	}
};
