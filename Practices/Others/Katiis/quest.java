import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeMap;

public class quest {

    public static TreeMap<Integer, PriorityQueue<Quest>> map;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numInputs = in.nextInt();

        map = new TreeMap<>();

        for (int i = 0; i < numInputs; i++)
        {
            String inputType = in.next();

            if (inputType.equals("add")) {
                int energy = in.nextInt();

                if (map.containsKey(energy)) {
                    map.get(energy).add(new Quest(in.nextInt()));
                } else {
                    PriorityQueue<Quest> temp = new PriorityQueue<>();
                    temp.add(new Quest(in.nextInt()));
                    map.put(energy, temp);
                }
            }

            else {

                int query = in.nextInt();
                Integer highest = map.floorKey(query);

                long totatGold = 0;

                while(query > 0 && highest != null){
                    
                    totatGold = totatGold + map.get(highest).poll().gold;

                    if (map.get(highest).size() == 0) {
                        map.remove(highest);
                    }

                    query = query - highest;
                    highest = map.floorKey(query);

                }

                System.out.println(totatGold);

            }

            in.nextLine();
        }


        in.close();

    }
}

class Quest implements Comparable<Quest>{
    int gold;
    public Quest(int gold){
        this.gold = gold;
    }
    @Override
    public int compareTo(Quest o) {
        return o.gold - this.gold;
    }
    @Override
    public String toString() {
        return "Quest " + gold;
    }
}