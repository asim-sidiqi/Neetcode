class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = s.split(" ")
        final=""
        for it in t:
            for c in range(len(it)):
                if(it[c].isalnum()):
                    final+=it[c]


        final = final.lower()

        l=0
        r=len(final)-1
        while(l<=r):
            if(final[l]!=final[r]): return  False
            l+=1
            r-=1
        
        return True
