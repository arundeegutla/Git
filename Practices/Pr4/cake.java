import java.util.Scanner;

/**
 * cake
 */
public class cake {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCakes = in.nextInt();

        for (int i = 0; i < numCakes; i++) {
            System.out.println(getPerimeter(in.nextInt()));
        }


    }

    private static int getPerimeter(int area) {

        double x = Math.sqrt(area);
        double y = 0;

        if(x != (int)x){
            x = Math.ceil(x) + 1;
            while((double)area/x != (int)(area/x)){
                x--;
            }
            y = (int)area/x;
        }  else 
            y = x;


        double p = 2 * (x + y);
            
        return (int)p;

    }
}