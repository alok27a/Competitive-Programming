class Solution {
    public String firstPalindrome(String[] words) {
        int i,j,n=words.length;
        System.out.println(n);
        for(i=0;i<n;i++){
            String temp=reverseFind(words[i]);
            if(words[i].equals(temp)==true)
            {
                return  words[i];
            }
            // System.out.println(reverseFind(words[i]));
        }
        return "";
    }
    
    public String reverseFind(String str){
        StringBuffer sbr = new StringBuffer(str);
        // To reverse the string
        sbr.reverse();
        return sbr.toString();
        
    }
}