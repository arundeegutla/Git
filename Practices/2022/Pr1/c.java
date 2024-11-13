import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


/**
 * c
 */
public class c {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numPeople = in.nextInt();
        in.nextLine();

        HashMap<String, ArrayList<Person>> map = new HashMap<>();
        ArrayList<Person> peps = new ArrayList<>();

        for (int i = 0; i < numPeople; i++) {
            String[] line = in.nextLine().split(" ");
            Person thiPerson = new Person(line[0]);
            thiPerson.speaking = line[1];

            for (int j = 1; j < line.length; j++) {
                String understand = line[j];

                ArrayList<Person> list = map.get(understand);
                if (list == null)
                    list = new ArrayList<>();
                
                list.add(thiPerson);
                map.put(understand, list);
            }

            peps.add(thiPerson);
        }


        for (Person person : peps) {
            ArrayList<Person> list = map.get(person.speaking);

            if (list == null)
                continue;

            for (Person p : list)
                if (!p.equals(person))
                    person.edges.add(p);
        }


        for (Person person : peps) {
            System.out.println(person);
        }

    }
}


class Person
{
    String name;
    String speaking;
    ArrayList<Person> edges;
    public Person(String name)
    {
        this.name = name;
        this.edges = new ArrayList<>();
    }
    @Override
    public int hashCode() {
        return name.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return ((Person)obj).name.equals(name);
    }

    @Override
    public String toString() {
        ArrayList<String> names = new ArrayList<>();
        for (Person p : edges)
            names.add(p.name);

        return name + " -----> " + names;
    }
}