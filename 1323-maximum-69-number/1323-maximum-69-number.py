class Solution:
    def maximum69Number (self, num: int) -> int:
        num_string=list(str(num));
        for i in range(len(num_string)):
            if(num_string[i]=='6'):
                num_string[i]='9'
                break
        large=''.join(num_string)
        return int(large)