import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class D {
    // author --> rajeshjsaharan
    public static boolean wordPattern(String pattern, String s) {
        String[] stringArray = s.split(" ");
        // first check length of both arguments if it mismatch then // return false
        if (pattern.length() != stringArray.length) {
            return false;
        }
        // mapping for every pattern key
        Map<Character, String> map = new HashMap<Character, String>();
        for (int i = 0; i < pattern.length(); i++) {
            char key = pattern.charAt(i);
            // if key already exist then check value is different form previous key
            // and return false if it is
            if (map.containsKey(key)) {
                if (!map.get(key).equals(stringArray[i])) {
                    return false;
                } else {
                    // otherwise contiune loop
                    continue;
                }
            } else {
                // check if key is new then value must not be old saved mapping
                if (map.containsValue(stringArray[i])) {
                    return false;
                }
                map.put(key, stringArray[i]);
            }
        }
        return true;

    }

    public static void main(String[] args) {

        boolean result = wordPattern("abba", "dog cat cat dog");
        String s = "dog cat cat dog";
        String[] arr = s.split(" ");
        System.out.println(Arrays.toString(arr));
        System.out.println(arr.length);
        System.out.println(result);

    }
}
