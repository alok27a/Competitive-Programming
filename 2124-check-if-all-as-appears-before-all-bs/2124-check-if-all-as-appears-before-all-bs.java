class Solution {
    public boolean checkString(String s) { 
        char[] ar = s.toCharArray();
        Arrays.sort(ar);
        String sorted = String.valueOf(ar);
        
        if(sorted.equals(s))
            return true;
        return false;
        
    }
}