import java.util.*;


public class ranklist
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        while(numCases-- > 0)
        {
            int numTeams = in.nextInt();
            
            int[] teams = new int[numTeams];
            for(int i = 0; i < numTeams; i++) {
                in.next();
                teams[i] = in.nextInt();
            }
            
            Arrays.sort(teams);
            
            int diff = 0;
            for(int i = 0; i < teams.length; i++)
                diff += Math.abs((i+1) - teams[i]);
            
            System.out.println(diff);
        }
    }
}