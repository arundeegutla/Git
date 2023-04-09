import java.util.Scanner;

/**
 * f
 */
public class f {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numStrings = Integer.parseInt(in.nextLine());

        for (int i = 0; i < numStrings; i++) {
            int[] occurences = new int[26];
            String newString = in.nextLine();
            boolean isapanagram = true;
            for (int j = 0; j < newString.length(); j++) {

                if ((newString.charAt(j) >= 'a' && newString.charAt(j) <= 'z') || (newString.charAt(j) >= 'A' && newString.charAt(j) <= 'Z')) {
                    int index = newString.charAt(j) >= 'a' ? newString.charAt(j) - 'a' : newString.charAt(j) - 'A';
                    // System.out.println(newString.charAt(j) + " " + (int)newString.charAt(j));
                    occurences[index]++;
                }
                
            }

            for (int j = 0; j < occurences.length; j++) {
                if (occurences[j] < 1) {
                    if (isapanagram) {
                        System.out.print("missing ");
                        isapanagram = false;
                    }
                    System.out.print((char)(j + 'a'));
                }
            }

        
            if (isapanagram) {
                System.out.println("pangram");
            } else System.out.println();
        }

        in.close();
    }
}