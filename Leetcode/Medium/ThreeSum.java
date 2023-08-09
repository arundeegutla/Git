/**
 * 3Sum
 */
public class ThreeSum {

    public static void main(String[] args) {
        
    }

    public static List<List<Integer>> threeSum(int[] nums) {
        
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<>();

        int left = 0;
        int right = nums.length - 1;

        while(left < right && left < nums.length && nums[left] <= 0){
            int leftAndRight = nums[left] + nums[right];

            for(int i = left + 1; i < right; i++)
                if(leftAndRight + nums[i] == 0)
                    list.add(Arrays.asList(new int[] {nums[left], nums[right], nums[i]}));

        }
        
        return list;
    }
}