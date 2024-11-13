import java.util.Arrays;
import java.util.Stack;

/**
 * largestRec84
 */
public class largestRec84 {

    public static void main(String[] args) {


        System.out.println(largestRectangleArea(new int[] {3,2,6,5,1,2}));


    }

    public static int largestRectangleArea(int[] heights) 
    {   

        int max_area = 0;

        for (int i = 0; i < heights.length; i++) {
            if (heights[i] > max_area) {
                max_area = heights[i];
            }
        }

        int[] nextLowestArray = new int[heights.length];
        int[] prevLowestArray = new int[heights.length];
        Arrays.fill(nextLowestArray, 1);
        Arrays.fill(prevLowestArray, 1);


        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < heights.length; i++)
        {

            while (!stack.isEmpty() && heights[stack.peek()] > heights[i]) {
                nextLowestArray[stack.peek()] = i - stack.peek();
                stack.pop();
            }

            stack.add(i);
        }

        while(!stack.isEmpty()){
            nextLowestArray[stack.peek()] = heights.length - stack.pop();
        }

        for (int i = (heights.length - 1); i >= 0 ; i--)
        {
            while (!stack.isEmpty() && heights[stack.peek()] > heights[i]) {
                prevLowestArray[stack.peek()] = stack.peek() - i;
                stack.pop();
            }
            stack.add(i);
        }

        while(!stack.isEmpty()){
            prevLowestArray[stack.peek()] = stack.pop() + 1;
        }


        for (int i = 0; i < nextLowestArray.length; i++) 
        {

            if (nextLowestArray[i] < 0) {
                continue;
            }

            int width = (nextLowestArray[i] + prevLowestArray[i]) - 1;

            if (heights[i] * width > max_area) {
                max_area = heights[i] * width;
            }
        }

        return max_area;
    }
}