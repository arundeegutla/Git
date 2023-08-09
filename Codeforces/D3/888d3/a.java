import java.util.Scanner;

/**
 * a
 */
public class a {

    public static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int t = in.nextInt();
        while(t-->0){
            int n = in.nextInt(), m = in.nextInt(), k = in.nextInt(), h = in.nextInt();
            int[] people = new int[n];
            for(int i = 0; i < n; i++)
                people[i] = in.nextInt();
            
            int c = 0;
            loop:for(var x : people){
                for(int i = 1; i <= m; i++){
                    for(int j = 1; j <= m; j++){
                        if(i==j) continue;
                        if(((k*i) - (k*j) == h-x)) {
                            c++;
                            continue loop;
                        }
                    }
                }
            }
            System.out.println(c);
        }

    }
}