public class Solution {

    // author :- @rajeshsharan
    public static char[] reverseString(char[] s) {
        int start = 0;
        int end = s.length - 1;
        while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
        ;

        return s;
    }

    public static void main(String[] args) {
        char[] s = { 'h', 'e', 'l', 'l', 'o' };
        char[] result = reverseString(s);
        System.out.println(result);
    }

}
