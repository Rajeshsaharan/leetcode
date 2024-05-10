import java.util.Arrays;
import java.util.List;

public class A {

    public static boolean canConstruct(String ransomNote, String magazine) {
        if (ransomNote.length() > magazine.length())
            return false;
        // intilization of an empty array with 26 length
        int[] alphabets_counter = new int[26]; // {0, 0, 0---0}
        // System.out.println(alphabets_counter);
        for (int i = 0; i < magazine.length(); i++) {
            // for finding index of alphabets we subtract from 97 or ASCi code of A
            alphabets_counter[magazine.charAt(i) - 97]++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            if ((alphabets_counter[ransomNote.charAt(i) - 97] == 0)) {
                return false;
            }
            alphabets_counter[ransomNote.charAt(i) - 97]--;
        }
        ;
        return true;
    }

    public static void main(String[] args) {
        var result = canConstruct("aa", "ab");
        System.out.println(result);

    }

}