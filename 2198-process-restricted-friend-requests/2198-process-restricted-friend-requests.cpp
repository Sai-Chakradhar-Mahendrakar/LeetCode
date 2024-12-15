class DSU{
  public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n+1, -1);
    }

    int find(int i){
        if(parent[i]==-1){
            return i;
        }
        return find(parent[i]);
    }

    void unionSet(int a, int b){
        int s1 = find(a);
        int s2 = find(b);
        if(s1!=s2){
            parent[s2]=s1;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int m=requests.size();
        vector<bool> ans;

        DSU dsu(n);

        for(auto r: requests){
            int s1 = dsu.find(r[0]);
            int s2 = dsu.find(r[1]);
            bool valid = true;

            if(s1!=s2){
                for(auto res: restrictions){
                    int x = dsu.find(res[0]);
                    int y = dsu.find(res[1]);
                    if((x==s1 && y==s2) || (x==s2 && y==s1)){
                        valid=false;
                        break;
                    }
                }
            }

            ans.push_back(valid);
            if(valid){
                dsu.unionSet(s1, s2);
            } 
        }
        return ans;
    }
};