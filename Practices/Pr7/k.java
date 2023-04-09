import java.util.Scanner;

public class k {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();

        Node root = new Node();

        String LONGEST = "";

        for (int i = 0; i < str.length(); i++) {

            StringBuilder maxSameString = new StringBuilder();
            Node thisNode = root;

            for (int j = i; j < str.length(); j++) {
                if (thisNode.trie[str.charAt(j) - 'a'] != null)
                    maxSameString.append(str.charAt(j));
                else
                    thisNode.trie[str.charAt(j) - 'a'] = new Node();
                thisNode = thisNode.trie[str.charAt(j) - 'a'];
            }

            String thisMax = maxSameString.toString();
            if (LONGEST.length() < thisMax.length() || (LONGEST.length() == thisMax.length() && LONGEST.compareTo(thisMax) > 0)) {
                LONGEST = thisMax;
            }
        }

        System.out.println(LONGEST);

    }
}

class Node {

    Node[] trie;
    public Node(){
        trie = new Node[26];
    }

}