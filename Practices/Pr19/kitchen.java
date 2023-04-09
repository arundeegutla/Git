import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;

public class kitchen {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCups = in.nextInt();
        int[] capacities = new int[numCups];
        for (int i = 0; i < capacities.length; i++)
            capacities[i] = in.nextInt();
        int goal = in.nextInt();

        long minChange = (long) 1e12;
        
        HashMap<String, Integer> map = new HashMap<>();
        Queue<String> q = new ArrayDeque<>();

        int[] startArray = new int[numCups];
        startArray[0] = capacities[0];

        map.put(Arrays.toString(startArray), 0);
        q.add(Arrays.toString(startArray));

        while (!q.isEmpty()) {
            String str = q.poll();
            int changes = map.get(str);
            String[] stateStr = str.substring(1, str.length()-1).replaceAll(" ", "").split(",");
            int[] state = new int[numCups];
            for (int i = 0; i < state.length; i++)
                state[i] = Integer.parseInt(stateStr[i]);
            
            for (int i = 0; i < numCups; i++) {
                for (int j = 0; j < numCups; j++) {
                    if(i==j) continue;

                    int otherRemaining = capacities[j] - state[j];
                    int poured = Math.min(state[i], otherRemaining);
                    int thisChange = changes + poured;

                    int[] newState = new int[numCups];
                    for (int k = 0; k < numCups; k++) {
                        newState[k] = state[k];
                        if(k == i) newState[i] -= poured;
                        if (k == j) newState[j] += poured;
                    }
                
                    String newStateStr = Arrays.toString(newState);
                    
                    if(newState[0] == goal) {
                        minChange = Math.min(minChange, thisChange);
                    } else if (thisChange < minChange && (!map.containsKey(newStateStr) || map.get(newStateStr) > thisChange)){
                        map.put(newStateStr, thisChange);
                        q.add(newStateStr);
                    }

                }
            }
        }

        System.out.println(minChange == (long)1e12 ? ("impossible") : minChange);
        
    }
}
