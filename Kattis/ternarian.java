import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;

public class ternarian {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        in.nextLine();

        for (int cases = 0; cases < numCases; cases++) 
        {

            HashSet<Long> left = new HashSet<>();
            HashSet<Long> right = new HashSet<>();
            String weight = convertToBase3(in.nextInt());

            for (int i = 0; i < weight.length(); i++) {
                
                for (int j = 0; j < (int)(weight.charAt(i) - '0'); j++) {
                    balance(left, right, (long)Math.pow(3, i));
                }
                
            }
            
            ArrayList<Long> leftList = new ArrayList<>(left);
            ArrayList<Long> rightList = new ArrayList<>(right);
            
            Collections.sort(leftList, Comparator.reverseOrder());
            Collections.sort(rightList, Comparator.reverseOrder());

            System.out.print("left pan:");
            printList(leftList);

            System.out.print("right pan:");
            printList(rightList);

            if (cases != numCases - 1) {
                System.out.println();
            }

        }

        in.close();

    }

    private static void printList(ArrayList<Long> list) {
        for (long num : list) {
            System.out.print(" " + num);
        }
        System.out.println();
    }

    private static void balance(HashSet<Long> left, HashSet<Long> right, long weight) {

        if (right.contains(weight)) {
            right.remove(weight);
            left.add(weight);
            right.add(weight * 3);
        } else if (left.contains(weight)) {
            left.remove(weight);
        } else {
            right.add(weight);
        }

    }

    private static String convertToBase3(int nextInt) {

        StringBuilder str = new StringBuilder();

        while (nextInt > 0) {
            str.append(nextInt%3);
            nextInt /= 3;
        }

        return str.toString();
    }


}
