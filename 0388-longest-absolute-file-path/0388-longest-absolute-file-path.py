'''
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext


so for file system like above first it is important to break it in lines('\n')
then everything depends on the number of tabs so keep traversing and use a map to store the length of the folder at the current level
'''

class Solution:
    def lengthLongestPath(self, path: str) -> int:
        ans=0
        path_len=dict()
        for i in path.splitlines():
            tabs=i.count("\t")
            name=i.lstrip('\t')
            if '.' in name:
                ans=max(ans,path_len.get(tabs-1,0)+len(name))
            else:
                path_len[tabs]=path_len.get(tabs-1,0)+len(name)+1
        return ans
