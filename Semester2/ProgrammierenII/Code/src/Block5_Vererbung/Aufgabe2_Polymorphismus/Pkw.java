package Block5_Vererbung.Aufgabe2_Polymorphismus;

public class Pkw extends Fahrzeug {
    private int anzahlTueren;

    public Pkw(int anzahlRaeder, int anzahlTueren) {
        super("Pkw", anzahlRaeder);
        this.anzahlTueren = anzahlTueren;
    }

    public int gibAnzahlTueren() {
        return anzahlTueren;
    }
}
