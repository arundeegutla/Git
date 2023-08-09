import java.util.HashSet;
import java.util.Scanner;

public class summertrip {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String events = in.nextLine();

        int count = 0;

        for (int i = 0; i < events.length(); i++) {
            
            HashSet<Character> set = new HashSet<>();
            
            int nextIndex = events.indexOf(events.charAt(i) + "", i+1);
            String newString = "";

            if (nextIndex > 0)
                newString = events.substring(i+1, nextIndex);
            else
                newString = events.substring(i+1);


            for (int j = 0; j < newString.length(); j++)
                set.add(newString.charAt(j));
    
            count += set.size();
            
        }

        System.out.println(count);

        in.close();
    }


}
