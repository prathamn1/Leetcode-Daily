//great problem for binary search , actually the method of sorting and then checking which subarry of indices of size k are adjacent does not work .
//so binary search is a great choice where we find the whether m boquets could be make till this day and if possible then answer could be below this range or if not possible then surely we increase the l to increase the day limit

class Solution {
public:
    bool can_make_m_boquets(vector<int>&bloom,int day_limit,int m,int k) {
        int adjacent=0;
        for(auto i:bloom) {
            if(i<=day_limit) {
                adjacent++;
                if(adjacent==k) {
                    adjacent=0;
                    m-=1;
                }
            }else {
                adjacent=0;
            }
            if(m==0) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        if(bloom.size()<(long long int)m*k) {
            return -1;
        }
        int low=*min_element(bloom.begin(),bloom.end());
        int high=*max_element(bloom.begin(),bloom.end());
        while(low<high) {
            int mid=low+(high-low)/2;
            if(can_make_m_boquets(bloom,mid,m,k)) {
                high=mid;
            }else {
                low=mid+1;
            }
        }
        return low;
    }
};