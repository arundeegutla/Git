import java.util.Scanner;

public class babylonian {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();
        in.nextLine();

        for (int i = 0; i < numCases; i++) {

            String[] babNumber = in.nextLine().replaceAll(",", ", ").split(",");

            int exp = babNumber.length - 1;

            long total = 0;
            for (int j = 0; j < babNumber.length; j++)
            {
                total += convertToInt(babNumber[j]) * Math.pow(60, exp);
                exp--;
            }

            System.out.println(total);

        }

        in.close();

    }

    private static Integer convertToInt(String substring) {

        int number = 0;
        int exp = 0;

        for (int i = substring.length() - 1; i >= 0; i--) {
            if (Character.isDigit(substring.charAt(i))) {
                number += (int)(substring.charAt(i) - '0') * Math.pow(10, exp);
                exp++;
            }
        }

        return number;
    }
}