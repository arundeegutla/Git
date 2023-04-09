import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class prob11 {

    public static ArrayList<BigInteger> twos;
    public static BigInteger zero = new BigInteger("0");
    public static BigInteger one = new BigInteger("1");
    public static BigInteger two = new BigInteger("2");
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        twos = new ArrayList<>();

        twos.add(one);

        BigInteger total = twos.get(twos.size() - 1);
        
        for (int i = 1; i <= 1000; i++) {
            total = total.multiply(two);
            twos.add(new BigInteger(total.toString()));
        }


        StringBuilder output = new StringBuilder();

        for (int cases = 0; cases < numCases; cases++){

            int until = in.nextInt();
            BigInteger n = twos.get(until);

            int numQueris = in.nextInt();
            in.nextLine();

            String encrypted = in.nextLine();

            Word root = new Word(new StringBuilder(encrypted), zero, n);

            buildTree(root);
            // printTree(root, "");

            for (int i = 0; i < numQueris; i++) 
            {
                BigInteger at =  new BigInteger(in.nextLine(), 2);
                output.append(getDecrepted(at, root) + (i != numQueris - 1 ? " " : "\n"));
            }

        
        }

        System.out.println(output.toString());

        in.close();

    }

    private static char getDecrepted(BigInteger at, Word root) {
        
        if (root.str.length() == 1) {
            return root.str.charAt(0);
        }

        BigInteger half = (root.start.add(root.end)).divide(two);
        if (at.compareTo(half) >= 0) {
            return getDecrepted(at, root.right);
        }

        return getDecrepted(at, root.left);
    }

    // private static void printTree(Word root, String level) {

    //     if (root == null) {
    //         return;
    //     }

    //     System.out.println(level + " " + root.str + " [" + root.start + ", " + root.end + "] ");
    //     printTree(root.left, level + "   ");
    //     printTree(root.right, level + "   ");

    // }

    private static void buildTree(Word root) {

        if (root.str.length() == 1) {
            return;
        }

        Stack<Integer> stack = new Stack<>();

        int first = 0;
        int second = -1;

        for (int i = 0; i < root.str.length(); i++) {

            if (root.str.charAt(i) == '#') {
                stack.push(i);

            }else if (root.str.charAt(i) == '$') {
                stack.pop();
                if (stack.isEmpty()) {
                    second = i;
                    break;
                }
            }
        }


        BigInteger half = (root.start.add(root.end)).divide(two);

        root.left = new Word(new StringBuilder(root.str.substring(first+1, second)), root.start, half);
        root.right = new Word(new StringBuilder(root.str.substring(second + 1, root.str.length())), half.add(one), root.end);

        buildTree(root.left);
        buildTree(root.right);
        
    }
}


class Word {

    BigInteger start;
    BigInteger end;
    StringBuilder str;
    Word left;
    Word right;

    public Word(StringBuilder str, BigInteger start, BigInteger end)
    {
        this.str = str;

        this.start = start;
        this.end = end;

        this.left = null;
        this.right = null;
    }

}