public class Hello{ //author - > @rajeshjsaharan 
    public static String verticalScanning(String[] arr){

        for (int i = 0; i < arr[0].length(); i++){
            char c = arr[0].charAt(i);
                for (int j = 1; j < arr.length; j++ ){
                if (i == arr[j].length() || arr[j].charAt(i) != c){
                    return arr[0].substring(0, i);
                    //System.out.println(result);
                }
                }
        };
        return arr[0];
        }
//------------------------------------------------------------//
    public static String horizintalScrolling(String[] arr){
         //for horizintal scanning for array
    String perfix = arr[0];
    //System.out.println(perfix);
    for (int x = 1 ; x < arr.length; x++){
       while(arr[x].indexOf(perfix) != 0){
        perfix = perfix.substring(0, perfix.length() -1);
       }
    }
    return perfix; }


    public static void main(String[] args){
    
    String[] arr =  {   "flower",
                        "flow",
                        "flat"
    };

    //for vertical scanning of array
    var result = verticalScanning(arr);
    System.out.println(result);

    var result2 = horizintalScrolling(arr);
    System.out.println(result2);
   



   

    };
}