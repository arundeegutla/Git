import java.util.*;

/**
 * mostArea
 */
public class mostArea {

    public static void main(String[] args) {
        System.out.println(maxArea(new int[] {1,8,6,2,5,4,8,3,7}));
    }

    public static int maxArea(int[] height) {
        int max = 0;
        int left = 0;
        int right = height.length - 1;

        while(left < right && left < height.length && right < height.length) {
            max = Math.max(max, Math.min(height[left], height[right]) * (right - left));
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }

        return max;
    }
}
