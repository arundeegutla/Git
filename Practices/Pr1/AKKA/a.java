import java.util.*;

public class a
{
    public static void main(String[] args) 
    {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();
        for (int i = 0; i < n; i++)
        {
            String eq = in.nextLine();

            String[] eqParts = eq.split(" ");

            int start = startBase(eqParts);
            char op = eqParts[1].charAt(0);

            StringBuilder output = new StringBuilder();
            long num1, num2, res;

            if (start == 1)
            {
                num1 = eqParts[0].length();
                num2 = eqParts[2].length();
                res = eqParts[4].length();

                if (check(res, num1, num2, op))
                {
                    output.append(start);
                    start++;
                }
            }

            while (start <= 36)
            {
                num1 = Long.parseLong(eqParts[0], start);
                num2 = Long.parseLong(eqParts[2], start);
                res = Long.parseLong(eqParts[4], start);

                if (check(res, num1, num2, op))
                {
                    if (start == 36)
                        output.append('0');
                    else if (start > 9 && start < 36)
                        output.append((char) (start - 10 + 'a'));
                    else
                        output.append(start);
                }
                
                start++;

            }

            if (output.length() == 0)
                System.out.println("invalid");
            else
                System.out.println(output);

        }

    }

    public static int startBase(String[] eqP)
    {
        String check = eqP[0] + eqP[2] + eqP[4];
        int res = 1;

        char[] arr = check.toCharArray();
        Arrays.sort(arr);
        char high = arr[arr.length - 1];

        if (high >= 'a' && high <= 'z')
            res = (int) (high - 'a') + 11;
        else
            res = (int) (high - '0') + 1;

        String reg = "1";
        res = (check.replaceAll(reg, "").length() == 0) ? 1 : res;

        return res;
    }

    public static boolean check(long res, long num1, long num2, long op)
    {
        long check = -1;
        if (op == '+')
            check = num1 + num2;
        else if (op == '*')
            check = num1 * num2;
        else if (op == '/')
            check = (num1 % num2 == 0) ? (num1 / num2) : -1;
        else if (op == '-')
            check = num1 - num2;

        if (res == check)
            return true;

        return false;
    }
}
