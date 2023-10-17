import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class pyro {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        ArrayList<Integer> list = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>();
        int num;
        while ((num = in.nextInt()) != -1) {
            list.add(num);
            set.add(num);
        }

        for (int at = 0; at < list.size(); at++) {
            int count = 0;
            int curNum = list.get(at);

            for (int i = 0; i <= 18; i++) {
                int thisNum = curNum ^ (1<<i);
                if (thisNum > curNum && set.contains(thisNum))
                    count++;
            }

            for (int i = 0; i <= 18; i++) {
                for (int j = i+1; j <= 18; j++) {
                    int thisNum = curNum ^ (1<<i) ^ (1<<j);
                    if (thisNum > curNum && set.contains(thisNum))
                        count++;
                }
            }

            System.out.println(curNum+":"+count);
        }
    }
}
