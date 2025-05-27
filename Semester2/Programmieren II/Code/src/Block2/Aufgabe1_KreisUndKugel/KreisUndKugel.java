package Block2.Aufgabe1_KreisUndKugel;

public class KreisUndKugel {
    private final double PI = 3.14159;
    private final double radius;

    public KreisUndKugel(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public double getCircumference() {
        return 2 * radius * PI;
    }

    public double getArea() {
        return PI * (radius * radius);
    }

    public double getSurface() {
        return 4 * PI * (radius * radius);
    }

    public double getVolume() {
        return ((double) 4/3) * PI * (radius * radius * radius);
    }
}
