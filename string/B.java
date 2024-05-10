public class B {

    public static int firstUniqChar(String s) {
        char[] charArray = s.toCharArray();
        int i = 0;
        int value = -1;
        for (int j = 1; j < s.length(); j++) {
            if (charArray[i] != charArray[j]) {
                continue;
            } else {
                i++;
                value = i;
            }
        }
        return value;
    }

    public static void main(String[] args) {

        var result = firstUniqChar("loveleetcode");
        System.out.println(result);

    }
}
