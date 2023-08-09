import java.util.HashMap;
import java.util.Scanner;

/**
 * d
 */
public class d {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int max = 1;
        HashMap<Character, Integer> cards = new HashMap<>();

        for (int i = 0; i < 5; i++) {
            char card = in.next().charAt(0);
            if (cards.containsKey(card)) {
                cards.put(card, cards.get(card) + 1);
                if (cards.get(card) > max) {
                    max = cards.get(card);
                }
            }else {
                cards.put(card, 1);
            }
        }

        System.out.println(max);

        in.close();
    }
}