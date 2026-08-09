class SmallestInfiniteSet {
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
    int cur = 1;

public:
    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!pq.empty()) {
            int x = pq.top();
            pq.pop();
            s.erase(x);
            return x;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur && !s.count(num)) {
            pq.push(num);
            s.insert(num);
        }
    }
};