import java.util.Scanner;

/**
 * g
 */
public class g {

    static String penninsula;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        penninsula = in.nextLine();

        int left = 0, sum = 0, max = 0;

        int maxLeft = 0, maxRight = 0;

        int dist = 0;

        int b = 0;
        int r = 0;

        for(int i = 0; i < penninsula.length(); i++)
        {

            if (penninsula.charAt(i) == 'B') {
                b++;
            } else  r++;

            int diff = b-r;

            sum = diff < 0 ? -diff : diff;

            if (sum == 0) {
                // System.out.println(left + " + " + dist);

                for (int j = 0; j < dist+1 && left < penninsula.length(); j++) {

                    if (penninsula.charAt(left) == 'B') {
                        b--;
                    } else r--;
                    left++;
                }

                // System.out.println(penninsula.substring(left, i) + " " + penninsula.substring(i));
                

            } else if(sum > max){
                maxLeft = left;
                maxRight = i;
                max = sum;
                dist = i - left;
                // System.out.println("Max " + max + " dist" + dist);
            }
        }

        System.out.println(maxLeft+1 + " " + (maxRight+1));

        // System.out.println(penninsula.substring(maxLeft, maxRight));
        in.close();
    }


    


}