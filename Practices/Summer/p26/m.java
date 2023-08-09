import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

/**
 * m
 */
public class m {

    public static void main(String[] args) {

        HashMap<String, String> map = new HashMap<>();
        map.put("iu", "q");
        map.put("ei", "w");
        map.put("uan", "r");
        map.put("ue", "t");
        map.put("un", "y");
        map.put("sh", "u");
        map.put("ch", "i");
        map.put("uo", "o");
        map.put("ie", "p");
        map.put("ong", "s");map.put("iong", "s");
        map.put("ai", "d");
        map.put("en", "f");
        map.put("eng", "g");
        map.put("ang", "h");
        map.put("an", "j");
        map.put("uai", "k");map.put("ing", "k");
        map.put("uang", "l");map.put("iang", "l");
        map.put("ou", "z");
        map.put("ia", "x");map.put("ua", "x");
        map.put("ao", "c");
        map.put("zh", "v");map.put("ui", "v");
        map.put("in", "b");
        map.put("iao", "n");
        map.put("ian", "m");

        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            String[] arr = in.nextLine().split(" ");
            ArrayList<String> strs = new ArrayList<>();
            for(String s : arr){
                String ans = "";
                
                if(s.length() == 1) 
                    ans = s.charAt(0) + "" + s.charAt(0) + "";
                else if(s.length() == 2) 
                    ans = s.charAt(0) + "" + s.charAt(1) + ""; 
                else if(map.containsKey(s))
                    ans = s.charAt(0) + map.get(s);
                else for(int i = 0; i < s.length(); i++){
                    String piynin = s.charAt(i)+"";
                    while (i+1 < s.length() && map.containsKey(piynin+s.charAt(i+1)))
                        piynin += s.charAt(++i)+"";
                    ans += map.getOrDefault(piynin, piynin);
                }
                strs.add(ans);
            }

            for (int i = 0; i < strs.size(); i++) {
                System.out.print(strs.get(i) + (i==strs.size()-1?"\n":" "));
            }
        }
    }
}