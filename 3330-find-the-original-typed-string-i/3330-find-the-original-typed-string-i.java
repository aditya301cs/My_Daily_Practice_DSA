class Solution {
    public int possibleStringCount(String word) {
        int result = 1; 
        int i = 0;
        
        while (i < word.length()) {
            int count = 1;
            while (i + count < word.length() && word.charAt(i) == word.charAt(i + count)) {
                count++;
            }
            if (count > 1) {
                result += count - 1; 
            }
            i += count; 
        }
        
        return result;
    }
}
