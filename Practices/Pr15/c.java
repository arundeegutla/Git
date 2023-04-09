import java.sql.Time;
import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numPeople = in.nextInt();
        int numCars = in.nextInt();
    
        Driver[] times = new Driver[numPeople];
        for (int i = 0; i < times.length; i++)
            times[i] = new Driver(in.nextInt());
        Arrays.sort(times);
        
        PriorityQueue<Car> q = new PriorityQueue<>();
        for (int i = 0; i < Math.min(numCars, numPeople); i++)
            q.add(new Car(i).addDriver(times[i]));
        
        int home = numPeople;
        long totalTime = 0;

        while (home > 0) {
            Car fastest = q.poll();
            
        }


    }
}

class Driver {
    int time;
    Driver(int time)
    {
        this.time = time;
    }
}

class Car implements Comparable<Car>{

    Driver d;
    int num;
    Car(int num)
    {
        this.num = num;
    }
    public Car addDriver(Driver d)
    {
        this.d = d;
        return this;
    }
    @Override
    public int compareTo(Car o) {
        return this.d.time - o.d.time;
    }
}
