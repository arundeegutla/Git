import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeSet;

import javax.swing.text.GapContent;

import java.awt.Point;
import java.lang.reflect.Array;

public class imperfectgps {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPos = in.nextInt();
        int interval = in.nextInt();

        TreeSet<Position> actual = new TreeSet<>();
        ArrayList<Position> gps = new ArrayList<>();
        for (int i = 0; i < numPos; i++)
            actual.add(new Position(new Point(in.nextInt(), in.nextInt()), in.nextInt()));

        gps.add(actual.first());
        gps.add(actual.last());

        for (int i = interval; i < actual.last().time; i += interval) {
            Position lower = actual.floor(new Position(null, i));
            Position higher = actual.ceiling(new Position(null, i));
            int deltaY = higher.location.y - lower.location.y;
            int deltaX = higher.location.x - lower.location.x;

            gps.add(new Position(new Point(lower.location.x), i))

        }

        ArrayList<Position> list = new ArrayList<>(actual);





    }

}

class Position implements Comparable<Position> {

    int time;
    Point location;
    Position(Point location, int time)
    {
        this.location = location;
        this.time = time;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(time);
    }

    @Override
    public boolean equals(Object obj) {
        return ((Position)obj).time == time;
    }
    @Override
    public int compareTo(Position o) {
        return this.time - o.time;
    }
}