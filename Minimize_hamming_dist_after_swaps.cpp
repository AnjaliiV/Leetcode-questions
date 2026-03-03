class Solution {
public:
    vector<int> parent, rank;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unionSet(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return;

        if(rank[pa] < rank[pb])
            parent[pa] = pb;
        else if(rank[pa] > rank[pb])
            parent[pb] = pa;
        else{
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        parent.resize(n);
        rank.assign(n, 0);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        for(auto &a : allowedSwaps)
            unionSet(a[0], a[1]);

        vector<vector<int>> components(n);
        for(int i = 0; i < n; i++)
            components[find(i)].push_back(i);

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(components[i].empty()) continue;

            vector<int> svals, tvals;

            for(int idx : components[i]){
                svals.push_back(source[idx]);
                tvals.push_back(target[idx]);
            }

            sort(svals.begin(), svals.end());
            sort(tvals.begin(), tvals.end());

            int matches = 0;
            int p1 = 0, p2 = 0;

            while(p1 < svals.size() && p2 < tvals.size()){
                if(svals[p1] == tvals[p2]){
                    matches++;
                    p1++;
                    p2++;
                }
                else if(svals[p1] < tvals[p2]){
                    p1++;
                }
                else{
                    p2++;
                }
            }

            ans += (svals.size() - matches);
        }

        return ans;
    }
};