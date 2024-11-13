import java.util.Scanner;

/**
 * cat
 */
public class cat {

    public static void main(String[] args) {
        String meow = "meow";
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
       loop : while (numCases-->0) {
            int length = in.nextInt();
            in.nextLine();
            String line = in.nextLine().toLowerCase();


            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < line.length(); i++)
                if (i == 0 || line.charAt(i) != line.charAt(i-1))
                    ans.append(line.charAt(i));

            line.matches(line)
            
            if(ans.toString().equals(meow))
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}