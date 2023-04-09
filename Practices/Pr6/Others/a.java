// ARUN
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class a {


    public static HashMap<String, Integer> pairs;
    public static long TRAVEL = Long.MAX_VALUE;
    public static String input;
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        pairs = new HashMap<>();

        input = in.nextLine();

        for (int i = 0; i < input.length() - 1; i++) {
            String pair = input.charAt(i) + "" + input.charAt(i+1);
            if(pairs.containsKey(pair)){
                pairs.put(pair, pairs.get(pair) + 1); 
            } else {
                pairs.put(pair, 1);
            }
        }   

        boolean[] used = new boolean[9];
        HashMap<Integer, Integer> keyAt = new HashMap<>();

        getMinimumTravel(used, 0, keyAt);

        System.out.println(TRAVEL);
        
        in.close();


    }


    public static void getMinimumTravel(boolean[] used, int k, HashMap<Integer, Integer> keyAt) {

        if (k == 9) {
            checkTravel(keyAt);
        }
        else {
            for (int i = 0; i < 9; i++) 
            {
                if (!used[i])
                {
                    used[i] = true;
                    keyAt.put(i, k);
                    getMinimumTravel(used, k+1, keyAt);
                    used[i] = false;
    
                }
            }
        }

        

    }


    public static void checkTravel(HashMap<Integer, Integer> keyAt) {

        long totaltravel = input.length();

        for (Map.Entry<String,Integer> element : pairs.entrySet()) {
            String pair = element.getKey();
            int occurances = element.getValue();

            int travel = Math.abs(keyAt.get(pair.charAt(0) - '0' - 1) - keyAt.get(pair.charAt(1) - '0' - 1));

            travel *= occurances;

            totaltravel += travel;
        }

        totaltravel += keyAt.get(input.charAt(0) - '0' - 1);
        if (totaltravel < TRAVEL) 
        {

            TRAVEL = totaltravel;
        }
    }
}
