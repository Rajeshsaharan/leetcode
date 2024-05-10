import java.util.Arrays;
import java.util.List;

public class Text {

    public static String reverseVowels(String s) {
        char[] chararray = s.toCharArray();
        List<Character> list = Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U');
        // two pointer solution
        int start = 0;
        int end = s.length() - 1;
        while (start < end) {
            if (list.contains(chararray[start]) && list.contains(chararray[end])) {
                char temp = chararray[start];
                chararray[start] = chararray[end];
                chararray[end] = temp;
                start++;
                end--;
            } else if (list.contains(chararray[start])) {
                end--;
            } else if (list.contains(chararray[end])) {
                start++;
            } else {
                start++;
                end--;
            }
        }

        return new String(chararray);

    }

    public static void main(String[] args) {

        String result = reverseVowels("leetcods");
        System.out.println(result);

    }

}
