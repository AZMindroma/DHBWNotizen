package Block5_Vererbung.Aufgabe3_BruchzahlModded;

public class BruchzahlTest {
    public static void main(String[] args) {
        Bruchzahl bruch1 = new Bruchzahl(5, 7);
        Bruchzahl bruch2 = new Bruchzahl(3, 5);

        Bruchzahl added = bruch1.addiere(bruch2);
        Bruchzahl multiplied = bruch1.multipliziere(bruch2);
        Bruchzahl subtracted = bruch1.subtrahiere(bruch2);
        Bruchzahl divided = bruch1.dividiere(bruch2);
        System.out.printf("""
                        Erste Bruchzahl: %s
                        Zweite Bruchzahl: %s
                        %s + %s = %s
                        %s - %s = %s
                        %s * %s = %s
                        %s / %s = %s
                        
                        """,
                bruch1, bruch2,
                bruch1, bruch2, added,
                bruch1, bruch2, subtracted,
                bruch1, bruch2, multiplied,
                bruch1, bruch2, divided
                );

        System.out.printf("%s =? %s --> %s\n", bruch1, bruch2, bruch1.equals(bruch2));

        Bruchzahl bruch3 = new Bruchzahl(5, 7);
        Bruchzahl bruch4 = new Bruchzahl(10, 14);

        System.out.printf("%s =? %s --> %s\n", bruch1, bruch3, bruch1.equals(bruch3));
        System.out.printf("%s =? %s --> %s\n", bruch1, bruch4, bruch1.equals(bruch4));
    }
}
