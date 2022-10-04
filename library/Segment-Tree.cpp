#include<bits/stdc++.h>
using namespace std;

template<typename Info>
class SegTree {
public:
    int n;
    vector<Info> info;

    SegTree(int _n) {
        n = _n;
        info = vector<Info>(4 * n + 1);
    }

    SegTree(const vector<Info> &init) : SegTree(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) -> void {
            if(l == r) {
                info[p] = init[l];
                return;
            } 
            int m = l + (r - l) / 2;
            build(2 * p + 1, l, m);
            build(2 * p + 2, m + 1, r);
            pull(p);
        };
        build(0, 0, n - 1);
    }

    void pull(int p) {
        info[p] = info[2 * p + 1] + info[2 * p + 2];
    }

    void modify(int p, int l, int r, int x, const Info& v) {
        if(r == l) {
            info[p] = v;
            return;
        }

        int m = l + (r - l) / 2;
        if(x <= m) {
            modify(2 * p + 1, l, m, x, v);
        } else {
            modify(2 * p + 2, m + 1, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info& v) {
        modify(0, 0, n - 1, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if(y < l or r < x) {
            return Info();
        }

        if(x <= l and r <= y) {
            return info[p];
        }

        int m = l + (r - l) / 2;
        return rangeQuery(2 * p + 1, l, m, x, y) + rangeQuery(2 * p + 2, m + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(0, 0, n - 1, l, r);
    }
};

template<typename Info, typename Tag>
class LazySegTree {
public:
    int n;
    vector<Info> info;
    vector<Tag> tag;

    LazySegTree(int _n) {
        n = _n;
        info = vector<Info>(4 * n + 1);
        tag = vector<Tag>(4 * n + 1);
    }

    LazySegTree(const vector<Info> &init) : LazySegTree(init.size()) {
        function<void(int, int, int)> build = [&](int p, int l, int r) -> void {
            if(r == l) {
                info[p] = init[l];
                return;
            }
            int m = l + (r - l) / 2;
            build(2 * p + 1, l, m);
            build(2 * p + 2, m + 1, r);
            pull(p);
        };
        build(0, 0, n - 1);
    }

    void pull(int p) {
        info[p] = info[2 * p + 1] + info[2 * p + 2];
    }

    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }

    void push(int p) {
        apply(2 * p + 1, tag[p]);
        apply(2 * p + 2, tag[p]);
        tag[p] = Tag();
    }

    void modify(int p, int l, int r, int x, const Info &v) {
        if(r == l) {
            info[p] = v;
            return;
        }

        int m = l + (r - l) / 2;
        push(p);
        if(x <= m) {
            modify(2 * p + 1, l, m, x, v);
        } else {
            modify(2 * p + 2, m + 1, r, x, v);
        }
        pull(p);
    }

    void modify(int p, const Info &v) {
        modify(0, 0, n - 1, p, v);
    }

    Info rangeQuery(int p, int l, int r, int x, int y) {
        if(y < l or r < x) {
            return Info();
        }

        if(x <= l and r <= y) {
            return info[p];
        }

        int m = l + (r - l) / 2;
        push(p);
        return rangeQuery(2 * p + 1, l, m, x, y) + rangeQuery(2 * p + 2, m + 1, r, x, y);
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(0, 0, n - 1, l, r);
    }

    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if(y < l or r < x) {
            return;
        }

        if(x <= l and r <= y) {
            apply(p, v);
            return;
        }

        int m = l + (r - l) / 2;
        push(p);
        rangeApply(2 * p + 1, l, m, x, y, v);
        rangeApply(2 * p + 2, m + 1, r, x, y, v);
        pull(p);
    }

    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(0, 0, n - 1, l, r, v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
