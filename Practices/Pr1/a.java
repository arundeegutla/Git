import java.util.Scanner;

public class a {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int numInputs = in.nextInt();
        in.nextLine();


        for (int i = 0; i < numInputs; i++)
        {
            String[] expression = in.nextLine().split(" "); 

            boolean found = false;

            for (int j = 1; j <= 36; j++) 
            {
                int x = 0, y = 0, z = 0;

                if (j == 1) 
                {
                    x = validOneBase(expression[0]);
                    y = validOneBase(expression[2]);
                    z = validOneBase(expression[4]);

                    if (x == -1 || y == -1 || z == -1) {
                        continue;
                    }
                }
                else
                {
                    try {
                        x = Integer.parseInt(expression[0], j);
                        y = Integer.parseInt(expression[2], j);
                        z = Integer.parseInt(expression[4], j);
                    } catch (Exception e) {
                        continue;
                    }
                    
                }

        
                found = checkIfValid(x, expression[1], y, z, j) && !found ? true : found;
                
            }

            if (found) {
                System.out.println();
            }else
                System.out.println("invalid");

            

        }
        in.close();
    }

    public static int validOneBase(String number)
    {
        if(number.charAt(0) != '1') return -1;
        
        int o = 0;
        int length = number.length();


        while(o < length && number.charAt(o) == '1'){
            o++;
            if (o < length && number.charAt(o) != '1') {
                return -1;
            }
        }

        return o;
    }

    public static boolean checkIfValid(double first, String operation, double second, double result, int j) {

        char base;

        if (j <= 9) {
            base = (char)(j + '0');
        } else if(j == 36){
            base = '0';
        } else{
            j -= 10;
            base = (char)(j + 'a');
        }

        if (operation.charAt(0) == '+' && first+second == result) {
            System.out.print(base);
            return true;
        }
        else if (operation.charAt(0) == '-' && first-second == result) {
            System.out.print(base);
            return true;
        }
        else if (operation.charAt(0) == '*' && first*second == result) {
            System.out.print(base);
            return true;
        }
        else if (operation.charAt(0) == '/' && (double)(first/second) == (double)result) {
            System.out.print(base);
            return true;
        }
        return false;
    }

}
