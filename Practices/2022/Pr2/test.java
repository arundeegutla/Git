public class test {
    public static void main(String[] args) {

        int min = 1;
        int max = 2;
        for (int i = 0; i < 100000; i++) {
            int b = (int)(Math.random()*(max-min+1)+min);  
            if (b == 1) {
                System.out.print("B");
            } else 
                System.out.print("R");

        }
    }
}
