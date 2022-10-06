class TimeMap {
public:
    unordered_map<string,vector<int>>time_stamp;
    unordered_map<string,unordered_map<int,string>>data;
    TimeMap() {  
    }
    
    void set(string key, string value, int timestamp) {
        time_stamp[key].push_back(timestamp);
        data[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        int k=lower_bound(time_stamp[key].begin(),time_stamp[key].end(),timestamp)-time_stamp[key].begin();
        string ans;
        // cout<<k<<"  "<<time_stamp[key].size()<<endl;
        // for(auto i:time_stamp[key]) {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        if(k<time_stamp[key].size() and time_stamp[key][k]==timestamp) {
            ans=data[key][time_stamp[key][k]];
        }else {
            if(k==0) {
                ans="";
            }else{
                ans=data[key][time_stamp[key][k-1]];
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */