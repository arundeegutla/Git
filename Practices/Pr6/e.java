import java.util.Scanner;
import java.util.Stack;

public class e {

    public static int[] heights;
    public static int[] hits;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int totalCount = 0;

        int numPeople = in.nextInt();
        heights = new int[numPeople];
        hits = new int[numPeople];

        for (int i = 0; i < numPeople; i++) {
            heights[i] = in.nextInt();
        }

        Stack<Integer> nextGreatestHeight = new Stack<>();

        for (int i = 0; i < numPeople; i++)
        {

            while(!nextGreatestHeight.isEmpty() && nextGreatestHeight.peek() < heights[i])
            {
                totalCount++;
                nextGreatestHeight.pop();
            }
            nextGreatestHeight.add(heights[i]);

        }   

        Stack<Integer> prevGreatestHeight = new Stack<>();

        for (int i = (numPeople - 1); i >= 0; i--)
        {
            while(!prevGreatestHeight.isEmpty() && prevGreatestHeight.peek() < heights[i])
            {
                totalCount++;
                prevGreatestHeight.pop();
            }
            prevGreatestHeight.add(heights[i]);

        }

        System.out.println(totalCount);

        in.close();

    }

}