import java.util.Scanner;


public class f {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String a = in.nextLine();
        String b = in.nextLine();

        int left = 0;
        while(a.charAt(left) == b.charAt(left))
            left++;

        int right = left + 1;
        for (int i = left + 1; i < a.length(); i++)
            if(a.charAt(i) != b.charAt(i))
                right = i + 1;
        

        // System.out.println(left + " " + right + " : " + a.charAt(left) + " " + a.charAt(right - 1));

        int count = 0;
        while (left >= 0 && right <= a.length()) {
            if (new StringBuilder(a.substring(left, right)).reverse().toString().equals(b.substring(left, right)))
                count++;

            left--;
            right++;
        }
        
        System.out.println(count);

        in.close();
        
    }
    
}