package Block6_AbstraktionBeziehungen.Aufgabe1_Beziehungen;

public class Pkw extends Fahrzeug {
    private int anzahlTueren;

    public Pkw(int anzahlRaeder, int anzahlTueren) {
        super("Pkw", anzahlRaeder);
        this.anzahlTueren = anzahlTueren;
    }

    public int gibAnzahlTueren() {
        return anzahlTueren;
    }

    public String toString() {
        return super.toString() + String.format(" Der %s hat %d Türen.", this.gibFahrzeugart(), this.anzahlTueren);
    }
}
