//author -> @rajeshjsaharan
 class Soultion {
    public static int strstr(String haystack, String needle){
        int haystackLength = haystack.length();
        int needleLength = needle.length();
       // sliding window approach
        int needleIndex = 0;
       for (int i = 0; i < haystackLength ; i++){
        if (haystack.charAt(i) == needle.charAt(needleIndex)){
            //if it matches increment needleIndex by one to match next char
            needleIndex ++; 
        }
        else{
            i = i - needleIndex; //set i to next index from previous one
            needleIndex = 0; //reset the needleINdex to zero
        }
        if (needleIndex == needleLength){
            return i - needleIndex +1; //first occurance of substring or needle
        }
       } 

    return -1;
    }
}
public class Main {
    public static void main(String[] args) {
    int result = Soultion.strstr("israjeshbad", "bad");
   
    System.out.println(result);
    }
}