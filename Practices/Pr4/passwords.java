import java.util.Arrays;
import java.util.Scanner;

public class passwords {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {

            int passLength = in.nextInt();
            in.nextLine();
            String[] words = new String[passLength];
            int[] possibles = new int[passLength];

            for (int j = 0; j < passLength; j++) {
                words[j] = in.nextLine();
            }

            for (int j = passLength - 1; j >= 0; j--) {
                possibles[j] = words[j].length() * (j < passLength-1 ? possibles[j+1] : 1);
            }

            int rank = in.nextInt();

            int thisRank = 0;
            for (int j = 0; j < passLength; j++) {
                int index = 0;
                if (j == passLength-1) {
                    System.out.print(words[j].charAt((rank - thisRank) - 1));
                    break;
                }
                while(thisRank + possibles[j+1] < rank){
                    thisRank += possibles[j+1];
                    index++;
                }

                System.out.print(words[j].charAt(index));
            }

            System.out.println();

        }

    }
}
