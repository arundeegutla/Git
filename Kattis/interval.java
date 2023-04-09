import java.util.PriorityQueue;
import java.util.Scanner;

public class interval {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numSlots = in.nextInt();

        PriorityQueue<Slot> slots = new PriorityQueue<>();

        for (int i = 0; i < numSlots; i++)
            slots.add(new Slot(in.nextInt(), in.nextInt()));

        Slot prevSlot = slots.poll();   
        long numToKeep = 1;

        while (!slots.isEmpty()) {
            Slot thisSlot = slots.poll();

            if (prevSlot.end <= thisSlot.start) {
                numToKeep++;
                prevSlot = thisSlot;
            } else if (prevSlot.end > thisSlot.end) {
                prevSlot = thisSlot;
            }
        }

        System.out.println(numToKeep);
        in.close();
    }
}

class Slot implements Comparable<Slot>{

    int start;
    int end;

    public Slot(int start, int end){
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Slot anotherSlot) {
        if (this.start == anotherSlot.start) {
            return this.end - anotherSlot.end;
        }
        return this.start - anotherSlot.start;
    }

    @Override
    public String toString() {
        // TODO Auto-generated method stub
        return "{" + start + " " + end + "}";
    }
}
