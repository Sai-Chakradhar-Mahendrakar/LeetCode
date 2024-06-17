class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> m;
    TimeMap() {}
    
    void set(string key, string value, int timestamp){
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()){
            return "";
        }

        int s=0;
        int e=m[key].size()-1;

        while(s<=e){
            int mid=(s+e)/2;

            if(m[key][mid].first<timestamp){
                s=mid+1;
            }else if(m[key][mid].first>timestamp){
                e=mid-1;
            }else{
                return m[key][mid].second;
            }
        }
        if(e>=0){
            return m[key][e].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */