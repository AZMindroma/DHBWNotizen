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
                        %s / %s = %s""",
                bruch1.zeigeAn(), bruch2.zeigeAn(),
                bruch1.zeigeAn(), bruch2.zeigeAn(), added.zeigeAn(),
                bruch1.zeigeAn(), bruch2.zeigeAn(), subtracted.zeigeAn(),
                bruch1.zeigeAn(), bruch2.zeigeAn(), multiplied.zeigeAn(),
                bruch1.zeigeAn(), bruch2.zeigeAn(), divided.zeigeAn()
                );
    }
}
