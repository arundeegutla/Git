import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.Point;

/**
 * t
 */
public class t {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPulses = in.nextInt();

        int maxHeight = 1;
        int maxWidth = 1;

        HashSet<Pulse> horizontals = new HashSet<>();
        HashSet<Pulse> verticals = new HashSet<>();

        while (numPulses-- > 0){
            Pulse newPulse = new Pulse(numPulses, in.next().charAt(0), in.nextInt(), in.nextInt(), in.nextInt());
            if (newPulse.horizontal){
                horizontals.add(newPulse);
                maxHeight = Math.max(maxHeight, (int)newPulse.pulse.getY1());
            }
            else {
                verticals.add(newPulse);
                maxWidth = Math.max(maxWidth, (int)newPulse.pulse.getX1());
            }
        }

        HashSet<Point> intersecions = new HashSet<>();
        int time = 0;

        while (!horizontals.isEmpty() && !verticals.isEmpty()) {
            time++;

            ArrayList<Pulse> removeH = new ArrayList<>();
            ArrayList<Pulse> removeV = new ArrayList<>();

            for (Pulse pulse : horizontals) {
                if (time < pulse.timeToStart)
                    continue;

                pulse.movePulse();
                
                if (pulse.trailing.getX() > maxWidth)
                    removeH.add(pulse);
            }

            for (Pulse pulse : verticals) {
                if (time < pulse.timeToStart)
                    continue;

                pulse.movePulse();

                if (pulse.trailing.getY() > maxHeight)
                    removeV.add(pulse);
            }

            for (Pulse pulse : removeH)
                horizontals.remove(pulse);

            for (Pulse pulse : removeV)
                verticals.remove(pulse);

            for (Pulse pulse : horizontals)
                for (Pulse other : verticals)
                    if(pulse.intersects(other))
                        intersecions.add(new Point(pulse.number, other.number));
        }
        

        System.out.println(intersecions.size());
    
    }
}

class Pulse implements Comparable<Pulse> {

    Line2D pulse;
    Point2D leading;
    Point2D trailing;
    int number;
    int timeToStart;
    boolean horizontal;

    Pulse(int number, char direction, int timeToStart, int length, int cell){
        this.horizontal = direction == 'h';
        this.timeToStart = timeToStart;

        if (horizontal) {
            leading = new Point(0, cell);
            trailing = new Point(-length, cell);
            pulse = new Line2D.Double(leading, trailing);
        } else {
            leading = new Point(cell, 0);
            trailing = new Point(cell, -length);
            pulse = new Line2D.Double(leading, trailing);
        }
        
        this.number = number;
    }

    public boolean intersects(Pulse other) {
        if (this.trailing.equals(other.leading) || this.leading.equals(other.trailing))
            return false;

        return pulse.intersectsLine(other.pulse);
    }

    public void movePulse()
    {
        if (horizontal) {
            leading.setLocation(leading.getX() + 1, leading.getY());
            trailing.setLocation(trailing.getX() + 1, trailing.getY());
        } else {
            leading.setLocation(leading.getX(), leading.getY() + 1);
            trailing.setLocation(trailing.getX(), trailing.getY() + 1);
        }
        pulse.setLine(leading, trailing);
    }

    @Override
    public int hashCode() {
        return this.number;
    }

    @Override
    public boolean equals(Object obj) {
        return ((Pulse)obj).number == number;
    }

    @Override
    public int compareTo(Pulse o) {
        return this.timeToStart - o.timeToStart;
    }
    
    @Override
    public String toString() {
        return (horizontal ? 'h' : 'v') + " " + timeToStart +  "  "  + leading + ", " + trailing;
    }
}