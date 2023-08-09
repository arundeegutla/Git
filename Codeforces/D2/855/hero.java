import java.util.Comparator;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;

public class hero {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numCards = in.nextInt();
            Card[] deck = new Card[numCards];
            for (int i = 0; i < deck.length; i++)
                deck[i] = new Card(in.nextInt(), i);
            
            PriorityQueue<Card> pq = new PriorityQueue<>(Comparator.reverseOrder());
            HashSet<Integer> dontTakes = new HashSet<>();

            long army = 0;
            for (int i = 0; i < deck.length; i++) {
                if (deck[i].num > 0) {
                    pq.add(deck[i]);
                } else {
                    // while (!pq.isEmpty() && dontTakes.contains(pq.peek().index))
                    //     pq.poll();
                    if(!pq.isEmpty())
                    {
                        Card c = pq.poll();
                        army += c.num;
                        // for (int j = c.index + 1; j < i; j++)
                        //     dontTakes.add(j);
                    }
                }
            }

            System.out.println(army);
            
        }
    }
}


class Card implements Comparable<Card>{

    int num;
    int index;
    
    Card(int num, int index){
        this.num = num;
        this.index = index;
    }
    @Override
    public int compareTo(Card o) {
        if(this.num == o.num)
            return this.index - o.index;
        return this.num - o.num;
    }
}