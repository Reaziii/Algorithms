ll mrge(ll a, ll b) {
    return a ^ b;
}

void build(ll n, ll l, ll r) {
    if (l == r) {
        st[n] = arr[l];
        return ;
    }
    ll mid = (l + r) / 2;
    build(n * 2, l, mid);
    build(n * 2 + 1, mid + 1, r);
    st[n] = mrge(st[n * 2], st[n * 2 + 1]);
}


void update(ll n, ll l, ll r, ll pos, ll value) {
    if (l == r) {
        st[n] ^= value;
        return ;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid)update(n * 2, l, mid, pos, value);
    else update(n * 2 + 1, mid + 1, r, pos, value);
    st[n] = mrge(st[n * 2], st[n * 2 + 1]);

}



ll query(ll n, ll l, ll r, ll ql, ll qr) {
    if (ql > r || qr < l) return 0;

    if (ql <= l && qr >= r) return st[n];

    ll mid = (l + r) / 2;

    return mrge(query(n * 2, l, mid, ql, qr), query(n * 2 + 1, mid + 1, r, ql, qr));

}
