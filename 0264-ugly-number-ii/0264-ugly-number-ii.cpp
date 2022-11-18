//ugly numbers of 2's = [2,4,6,8,10,...]
//ugly numbers of 3's = [3,6,9,12,15,...]
//ugly numbers of 5's = [5,10,15,20,...]

// so one way is to merge them and then create a full list then just give the number at the nth index,
//but in this we would have to keep track of repetitions like 6 is coming in both and this could also be solved easily by checking if the number is already taken or not
//but the problem is that then we would have to make array of size till the 1690th ugly number which is 10**10 (not possible)


// so another approach to thought of is that we know that 1 ugly number is 1
//next can be 2*1 , 3*1 , 5*1 but we know that next will be 2*1 as it is smallest and has not been taken. then next can be 2*2,3*1,5*1 ,certainly 3 then 2*2,3*2,5*1 (4) ans so on .

//we could also use priority queue but there is no need as pointers are maintaining order

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n);
        ugly[0]=1;
        int p2=0,p3=0,p5=0;
        for(int i=1;i<n;i++) {
            //ugly[i] denotes that the previous ugly number obtained by that number.
            int curr_no=min({2*ugly[p2],3*ugly[p3],5*ugly[p5]});
            if(curr_no==2*ugly[p2]) {
                p2++;
            }
            if(curr_no==3*ugly[p3]) {
                p3++;
            }
            if(curr_no==5*ugly[p5]) {
                p5++;
            }
            ugly[i]=curr_no;
        }
        return ugly[n-1];
    }
};