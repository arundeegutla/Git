import java.util.Scanner;
public class ornaments {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (true) {
            double r = in.nextInt();
            double h = in.nextInt();
            double s = in.nextInt();
            if(r==0&&h==0&&s==0)break;
 
            double radians = Math.acos(r/h);
            double rope = (2*(Math.sqrt((h*h)-(r*r)))) + (2*Math.PI*r) - (2*(radians*r));
            System.out.printf("%.2f\n", (1+(s/100))*rope);

        }
    }
}
