public class C {
    // author - rajeshjsahran
    public static char findTheDifference(String s, String t) {
        int[] alphabet_counter = new int[26];
        for (int i = 0; i < t.length(); i++) {
            alphabet_counter[t.charAt(i) - 97]++;
        }
        for (int j = 0; j < s.length(); j++) {
            alphabet_counter[s.charAt(j) - 97]--;
        }
        for (int k = 0; k < alphabet_counter.length; k++) {
            if (alphabet_counter[k] == 1) {
                int value = k + 97;
                char result = (char) value;
                return result;
            }
        }
        return ' ';
    }

    public static void main(String[] args) {
        char result = findTheDifference("a", "aa");
        System.out.println(result);

    }

}
