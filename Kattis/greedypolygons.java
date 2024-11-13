import java.util.Scanner;

public class greedypolygons {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        while (N-->0) {
            double n = in.nextInt();
            double s = in.nextInt();
            double d = in.nextInt()*in.nextInt();
            double area = 0;
            area += s*n;
            area *= s/(2*Math.tan(Math.toRadians(180/n)));
            area /= 2;            
            area += ((1.0/n)*Math.PI*(d*d))*n + (d*s*n);
            System.out.println(area);
        }
    }
}

// 2
// 3 8 1 1
// 4 5 2 2
