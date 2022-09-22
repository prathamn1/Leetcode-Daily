class Solution:
    def reverseWords(self, s: str) -> str:
        words=s.split()
        for i in range(len(words)):
            words[i]=words[i][::-1]
            if(i!=len(words)-1):
                words[i]+=' '
        return ''.join(words)
        