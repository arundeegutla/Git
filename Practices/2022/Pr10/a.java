import java.awt.*;
import java.awt.geom.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class a {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        
        while (true) 
        {
            int radius = in.nextInt();
            int centerX = in.nextInt();
            int centerY = in.nextInt();
            int numLines = in.nextInt();

            if (radius == 0 && centerX == 0 && centerY == 0 && numLines == 0)
                break;

            Ellipse2D circle = new Ellipse2D.Double();
            circle.setFrameFromCenter(centerX, centerY, centerX + radius, centerY + radius);
            Point2D center = new Point2D.Double(circle.getCenterX(), circle.getCenterY());

            ArrayList<MyLine> lines = new ArrayList<>();

            for (int i = 0; i < numLines; i++) {
                MyLine thisLine = new MyLine(new Point(in.nextInt(), in.nextInt()), new Point(in.nextInt(), in.nextInt()), circle, radius);
                if (thisLine.line.ptLineDist(center) < radius)
                    lines.add(thisLine);
            }

            int circleEdges = 0;
            int edges = 0;
            HashSet<Point2D> vertices = new HashSet<>();

            for (int i = 0; i < lines.size(); i++)
            {
                MyLine line1 = lines.get(i);

                int verticesSize = vertices.size();
                vertices.add(line1.line.getP1());
                vertices.add(line1.line.getP2());
                circleEdges += vertices.size() - verticesSize;

                for (int j = 0; j < i; j++) {
                    MyLine line2 = lines.get(j);
                    Point2D intersection = null;

                    if (line1.line.intersectsLine(line2.line) && (intersection = line1.intersection(line2)).distance(center) < radius) {
                        vertices.add(intersection);
                        edges += 2;
                    }
                }

            }


            System.out.println(1+(edges + circleEdges + lines.size()) - vertices.size());

            
        }

        in.close();
    }
}

class MyLine {

    Point one;
    Point two;
    Line2D line;
    Double slope;
    double yIntercept;

    public MyLine(Point one, Point two, Ellipse2D circle, int radius) {
        this.one = one;
        this.two = two;
        setSlope(one, two, circle);
        getCircleLineIntersectionPoint(circle, radius);;
    }

    private void setSlope(Point one, Point two, Ellipse2D circle) {

        if (one.x == two.x){
            slope = null;
            return;
        }
        
        if (one.y == two.y){
            slope = 0.0;
            yIntercept = one.y;
            return;
        }

        slope = getSlope(one, two);
        yIntercept = getYintercept(one, slope);

    }

    public void getCircleLineIntersectionPoint(Ellipse2D circle, int radius) {


        double centerX = circle.getCenterX();
        double centerY = circle.getCenterY();

        
        if (slope == null) {

            Point2D.Double p1 = new Point2D.Double(one.x, Math.sqrt((radius*radius) - Math.pow(one.x - centerX, 2)) + centerY);
            Point2D.Double p2 = new Point2D.Double(one.x, -Math.sqrt((radius*radius) - Math.pow(one.x - centerX, 2)) + centerY);
            line = new Line2D.Double(p1, p2);
            return;
        }

        double twoAB = (-centerX)+(-centerX);
        double b2 = centerX * centerX;

        double y = yIntercept - centerY;

        double a2 = slope * slope;
        double btwoAB = 2 * (y * slope);
        double bb2 = y*y;


        a2 += 1;
        twoAB += btwoAB;
        b2 += bb2;
        b2 -= radius*radius;

        twoAB /= a2;
        b2 /= a2;
        a2 /= a2;


        double x1 = (-twoAB + Math.sqrt((twoAB * twoAB) - 4*a2*b2))/2;
        double x2 = (-twoAB - Math.sqrt((twoAB * twoAB) - 4*a2*b2))/2;

        Point2D.Double p1 = new Point2D.Double(x1, (slope * x1) + yIntercept);
        Point2D.Double p2 = new Point2D.Double(x2, (slope * x2) + yIntercept);

        line = new Line2D.Double(p1, p2);
    }

    


    public Point2D intersection(MyLine b) {

        if(b.slope == null && this.slope == null)
            return new Point2D.Double(1e9, 1e9);

        if (b.slope == null)
            return new Point2D.Double(b.one.getX(),(this.slope * b.one.getX()) + this.yIntercept);

        if(this.slope == null)
            return new Point2D.Double(one.getX(),(b.slope * one.getX()) + b.yIntercept);

        
        double intercept = this.yIntercept - b.yIntercept;
        double diff = b.slope - this.slope;
        double x = intercept / diff;


        return new Point2D.Double(x, (this.slope * x) + yIntercept);
    }

    private double getYintercept(Point one, double slope) {
        return one.y - (slope * one.getX());
    }

    private double getSlope(Point one, Point two) {
        return (two.getY() - one.getY()) / (two.getX() - one.getX());
    }


    @Override
    public String toString() {
        return line.getP1() + " " + line.getP2() + "++++++++++++++++++ " + slope + " " + yIntercept;  
    }

    @Override
    public int hashCode() {
        return line.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        return line.equals(obj);
    }
}


