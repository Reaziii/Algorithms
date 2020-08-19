int arr[N];
int blocks[10000];
int blk_size;
int n;

void update(int idx, int val) {
	int blk_n = idx / blk_size;
	blocks[blk_n] += val;
	blocks[blk_n] -= arr[idx];
	arr[idx] = val;
}

int query(int l, int r) {
	int lb = l / blk_size;
	int rb = r / blk_size;
	int sum = 0;
	if (lb == rb) {
		for (int i = l; i <= r; i++) sum += arr[i];
		return sum;
	}


	for (int i = lb + 1; i < rb; i++) sum += blocks[i];

	for (int i = l; i <= (lb + 1)*blk_size - 1; i++) sum += arr[i];
	for (int i = (rb) * blk_size; i <= r; i++) sum += arr[i];

	return sum;
}



void pre_proces() {
	fri(n) {
		blocks[i / blk_size] += arr[i];
	}
}
