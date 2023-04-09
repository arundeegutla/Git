import java.util.Scanner;

/**
 * dallas
 */
public class dallas {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCases = in.nextInt();

        for (int i = 0; i < numCases; i++) {
            int numNames = in.nextInt();
            in.nextLine();

            String[] names = new String[numNames];

            for (int j = 0; j < numNames; j++) {
                names[j] = in.nextLine();
            }

            int numMatches = in.nextInt();
            in.nextLine();

            String[] matches = new String[numMatches];

            for (int j = 0; j < numMatches; j++) {
                matches[j] = in.nextLine();
            }

            System.out.println("List #" + (i+1) + ":");





            for (int j = 0; j < numMatches; j++) {

                boolean found = false;

                for (String string : names) {

                    int prevIndex = -1;

                    for (int j2 = 0; j2 < matches[j].length(); j2++) {

                        int indexOf = string.indexOf(matches[j].charAt(j2), prevIndex+1);

                        if (indexOf == -1 || indexOf < prevIndex) {
                            break;
                        }


                        if(j2 == matches[j].length() - 1) found = true;
                        prevIndex = indexOf;
                    }

                    if (found) {
                        System.out.println(matches[j] + ": FOUND");
                
                        break;
                    }

                }

                if (!found) {
                    System.out.println(matches[j] + ": NOT FOUND");
                }

            }


            System.out.println();


        }

        in.close();

    }
}