public class testing {
    public static void main(String[] args) {
        int numCases = 50;

        for (int i = 0; i < numCases; i++)
        {
            System.out.println(10 + " " + (int)(Math.random()*24) * 15 + " " + (int)(Math.random()*100+1));
            for (int j = 0; j < 10; j++) {
                System.out.println((int)(Math.random()*1000+1) + " " + (int)(Math.random()*24) * 15);
            }
        }
    }
}
