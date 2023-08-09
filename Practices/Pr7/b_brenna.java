import java.util.Scanner;

public class b_brenna {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCorrect = in.nextInt();
        in.nextLine();

        String mine = in.nextLine();
        String friend = in.nextLine();


        int numSame = 0;
        int numDiff = 0;

        for (int i = 0; i < mine.length(); i++)
            if (mine.charAt(i) == friend.charAt(i)) numSame++;
            else numDiff++;

            
        if (numSame >= numCorrect) System.out.println(numCorrect + numDiff);
        else System.out.println(numSame + (mine.length() - numCorrect)); 


        in.close();

    }
}
