import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * babelfish
 */
public class babelfish {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        HashMap<String, String> dict = new HashMap<>();

        while (in.hasNextLine()) {

            String[] words = in.nextLine().split(" ");

            if(!words[0].equals("")){

                if (words.length > 1) {
                    
                    dict.put(words[1], words[0]);
                } else {
                    if (dict.containsKey(words[0])) {
                        System.out.println(dict.get(words[0]));
                    } else {
                        System.out.println("eh");
                    }
                }
            }
            
        }

        in.close();
    }
}