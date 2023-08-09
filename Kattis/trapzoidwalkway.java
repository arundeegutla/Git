import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;
import java.util.Scanner;

public class trapzoidwalkway {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int numTraps;

        while ((numTraps = in.nextInt()) != 0) {

            ArrayList<Shape> shapes = new ArrayList<>();
            for (int i = 0; i < numTraps; i++) {

                Shape ogShape = new Shape(in.nextInt(), in.nextInt(), in.nextInt());
                Shape inverted = new Shape(ogShape.b, ogShape.a, ogShape.height);

                
                shapes.add(ogShape);
                shapes.add(inverted);
            }


            for (int i = 0; i < shapes.size(); i++) {

                Shape start = shapes.get(i);
                for (int j = 0; j < shapes.size(); j++) {
                    
                    Shape next = shapes.get(j);
                    if (start.b == next.a) {
                        start.addEdge(next);
                    }
                }
            }

            int backPorch = in.nextInt(), gazebo = in.nextInt();
            Shape start = new Shape(backPorch, backPorch, 0);

            for (Shape shape : shapes) {
                if (start.b == shape.a) {
                    start.addEdge(shape);
                }
            }

            shapes.add(start);


            System.out.printf("%.2f\n", DFS(start, gazebo, 0)/100);




        }

        in.close();

    }

    private static Double DFS(Shape start, int gazebo, double dist) {

        HashMap<Integer, Double> distances = new HashMap<>();
        Queue<Shape> q = new ArrayDeque<>();

        distances.put(start.b, (double)0);
        q.add(start);

        while (!q.isEmpty()) {
            
            Shape thisShape = q.poll();


            for (Edge e : thisShape.edges) {

                if (!distances.containsKey(e.to.b) || distances.get(e.to.b) > distances.get(thisShape.b) + e.weight) {
                    distances.put(e.to.b, distances.get(thisShape.b) + e.weight);
                    q.add(e.to);
                }
                
            }
        }

        return distances.get(gazebo);

    }

}

class Shape {
    int a;
    int b;
    int height;
    ArrayList<Edge> edges;

    public Shape(int a, int b, int height)
    {
        this.a = a;
        this.b = b;
        this.height = height;
        edges = new ArrayList<>();
    }

    public void addEdge(Shape to){
        edges.add(new Edge(this, to, getArea(to) * 2));
    }

    private double getArea(Shape to) {
        return (((double)to.a/2) + ((double)to.b)/2) * to.height;
    }

    @Override
    public String toString() {
        return edges.toString();
    }
}

class Edge{

    Shape from;
    Shape to;
    double weight;
    boolean used;

    public Edge(Shape from, Shape to, double weight)
    {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }

    @Override
    public String toString() {
        if (from.height == 0) {
            return "Start ----> {" + to.a + ", " + to.b + ", " + to.height + "}";
        }
        return "{" + from.a + ", " + from.b + ", " + from.height + "} ----> {" + to.a + ", " + to.b + ", " + to.height + "}";
     }

}