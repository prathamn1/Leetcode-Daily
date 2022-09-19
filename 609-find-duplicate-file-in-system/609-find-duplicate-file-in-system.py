from collections import defaultdict
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        content=defaultdict(list)
        ans=[]
        for i in paths:
            curr_path=""
            j=0
            while i[j]!=" ":
                curr_path+=i[j]
                j+=1
            while j<len(i):
                file_name=""
                j+=1
                while i[j]!='(':
                    file_name+=i[j]
                    j+=1
                j+=1
                data=""
                while i[j]!=')':
                    data+=i[j]
                    j+=1
                content[data].append(curr_path+'/'+file_name)
                j+=1
        for i in content:
            if len(content[i])>1:
                ans.append(content[i])
        return ans
                
            
        