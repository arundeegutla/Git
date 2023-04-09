import java.util.Scanner;

public class reconnaissance {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numTrucks = in.nextInt();

        Truck[] trucks = new Truck[numTrucks];

        for (int i = 0; i < numTrucks; i++)
            trucks[i] = new Truck(in.nextInt(), in.nextInt());

        System.out.println(TreSearch(trucks, 0, Integer.MAX_VALUE, null));

        in.close();

    }


    private static double TreSearch(Truck[] trucks, double low, double high, Double parent) {

        double mid1 = low + (high - low) / 3;
        double mid2 = mid1 + (high - low) / 3;

        double result1 = getDistance(trucks, mid1);
        double result2 = getDistance(trucks, mid2);

        if (result1 > result2) low = mid1;
        else high = mid2;

        if (parent != null && Math.abs(parent - result1) < 0.000000001) return parent;

        parent = result1;
        return TreSearch(trucks, low, high, parent);
        
    }


    private static double getDistance(Truck[] trucks, double x) {

        double top = Integer.MIN_VALUE;
        double bottom = Integer.MAX_VALUE;
        
        for (int i = 0; i < trucks.length; i++) {
            double thisTruck = trucks[i].getPosition(x);
            top = Math.max(top, thisTruck);
            bottom = Math.min(bottom, thisTruck);
        }

        return Math.abs(top - bottom);
        
    }
}

class Truck {

    int yIntercept;
    int slope;

    public Truck(int yIntercept, int slope){
        this.yIntercept = yIntercept;
        this.slope = slope;
    }

    public double getPosition(double x) {
        return (slope * x) + yIntercept;
    }
}