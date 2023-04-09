import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class flex {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int width = in.nextInt();
        int numPartitions = in.nextInt();
        
        int[] partitions = new int[numPartitions + 2];
        partitions[0] = 0;
        partitions[numPartitions + 1] = width;
        for (int i = 1; i <= numPartitions; i++)
            partitions[i] = in.nextInt();
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0; i < partitions.length; i++) {
            for (int j = i + 1; j < partitions.length; j++) {
                set.add(partitions[j] - partitions[i]);
            }
        }

        ArrayList<Integer> list = new ArrayList<>(set);
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + (i == list.size() - 1 ? "\n" : " "));
        }
    }
}
