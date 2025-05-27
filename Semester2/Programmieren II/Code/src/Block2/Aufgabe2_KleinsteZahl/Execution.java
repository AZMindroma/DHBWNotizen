package Block2.Aufgabe2_KleinsteZahl;

public class Execution {
    public static void main(String[] args) {
        KleinsteZahl array = new KleinsteZahl(new int[]{4, 8, 19, 2, 6, 45});

        System.out.println(array.getSmallestNumber());
    }
}
