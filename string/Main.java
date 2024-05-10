public class Main {
    public static int getLastWordLength(String s){
    String stripS = s.strip(); //removing leading and trailing strip
    int j = 0; //for whitespace
    int k = stripS.length();// for last word length 
    for (int i =stripS.length() -1; i >= 0; i--){
       System.out.println(stripS.charAt(i));
       if (Character.isWhitespace(stripS.charAt(i))){
            j = i; //set first whitespace index for reversed loop
            k = stripS.length() -j -1;
            break; //break the loop if whitespace found and set new k value
       }
    }
    return k;
    }

    public static void main(String[] args){
        var result = getLastWordLength("ok    is");
        System.out.println(result);

        

    }
}