import java.util.Scanner;
import java.util.TreeMap;

public class i {
    public static void main(String[] args) {

        TreeMap<Integer, Integer> map = new TreeMap<>();
        map.put(69, 15);        
        map.put(89, 30);        
        map.put(120, 50);
        map.get(map.floorKey(89)); // 30
    }
}
