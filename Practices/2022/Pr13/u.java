import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class u {
    public static void main(String[] args) {
        System.out.println(solution("(bar)"));
        // Scanner in = new Scanner(System.in);

        // char[][] leets = {{'0', 'O'}, {'1', 'L'}, {'2', 'Z'}, {'3', 'E'}, {'5', 'S'}, {'6', 'B'}, {'7', 'T'}, {'8', 'B'}};

        // int numBads = in.nextInt();
        // int numStrings = in.nextInt();
        // in.nextLine();

        // ArrayList<String> bads = new ArrayList<>();
        // for (int i = 0; i < numBads; i++)
        //     bads.add(in.nextLine());

        
        // loop : while (numStrings-- > 0) {
        //     String str = in.nextLine();

        //     for (char[] leet : leets)
        //         str = str.replaceAll(leet[0] + "", leet[1] + "");

        //     for (String bad : bads) {
        //         if (str.indexOf(bad) >= 0) {
        //             System.out.println("INVALID");
        //             continue loop;
        //         }
        //     }

        //     System.out.println("VALID");

        // }

    }

    public static String solution(String inputString) {
        Stack<Integer> stack = new Stack<>();
        
        StringBuilder str = new StringBuilder(inputString);
        
        for (int i = 0; i < inputString.length(); i++) {
            if (inputString.charAt(i) == ')' && !stack.isEmpty()) {
                int start = stack.pop();
                StringBuilder part = new StringBuilder(str.substring(start + 1, i)).reverse();
                
                str.replace(start+1, i, part.toString());
            } else if (inputString.charAt(i) == '(') {
                stack.push(i);
            }
        }
        
        System.out.println(str.toString());
        String ret = str.toString().replaceAll("\\(", "");
    
        
        return ret;
    }
    
}
