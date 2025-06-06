package Block2_Grundlagen.Aufgabe1_KreisUndKugel;

public class Execution {

    public static void main(String[] main) {
        KreisUndKugel circle1 = new KreisUndKugel(5);
        KreisUndKugel circle2 = new KreisUndKugel(7.2);

        KreisUndKugel sphere1 = new KreisUndKugel(4);
        KreisUndKugel sphere2 = new KreisUndKugel(8.9);

        System.out.printf("Kreis mit Radius %f:\nUmfang: %f, Fläche: %f", circle1.getRadius(), circle1.getCircumference(), circle1.getArea());
        System.out.println();
        System.out.printf("Kreis mit Radius %f:\nUmfang: %f, Fläche: %f", circle2.getRadius(), circle2.getCircumference(), circle2.getArea());

        System.out.println();
        System.out.println();

        System.out.printf("Kugel mit Radius %f:\nOberfläche: %f, Volumen: %f", sphere1.getRadius(), sphere1.getSurface(), sphere1.getVolume());
        System.out.println();
        System.out.printf("Kugel mit Radius %f:\nOberfläche: %f, Volumen: %f", sphere2.getRadius(), sphere2.getSurface(), sphere2.getVolume());

    }

}
