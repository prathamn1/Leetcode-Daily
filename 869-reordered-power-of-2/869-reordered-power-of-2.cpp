class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string sn=to_string(n);
        sort(sn.begin(),sn.end());
        int power2=1;
        for(int i=1;i<31;i++) {
            string check=to_string(power2);
            sort(check.begin(),check.end());
            if(check==sn) {
                return true;
            }
            power2*= 2;
        }
        return false;    
    }
};
 // in this question change teh given n into string and sort it and now traverse for every power of 2 in the given constraint range and convert it into string and sort it and check whether it's equal to our n string. because if it's equal that means they both have same digits which means we could reorder n to make it a power of 2