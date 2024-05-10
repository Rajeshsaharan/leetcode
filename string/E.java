import java.util.Arrays;

public class E {
    // author --> rajeshjsahran
    public static String addStrings(String num1, String num2) {
        int difference = Math.abs(num2.length() - num1.length());
        if (num2.length() > num1.length()) {
            num1 = "0".repeat(difference) + num1;
        } else {
            num2 = "0".repeat(difference) + num2;
        }
        String total = "";
        int carry = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            int num1unit = num1.charAt(i) - '0'; // convert char to int
            int num2unit = num2.charAt(i) - '0'; // num2unit
            System.out.println(carry);
            int sum = num1unit + num2unit + carry;
            String value = String.valueOf(sum);
            // System.out.println(value);
            if (sum >= 10 && i != 0) {
                total = value.charAt(1) + total;
                carry = 1;
            } else {
                total = value + total;
                carry = 0;
            }
        }
        return total;
    }

    public static void main(String[] args) {
        String num1 = "123456789";
        String num2 = "987654321";
        String result = addStrings(num1, num2);
        System.out.println(result);

    }

}
