package Block6_AbstraktionBeziehungen.Aufgabe1_Beziehungen;

public class Pkw extends Fahrzeug {
    private int anzahlTueren;

    public Pkw(Fahrzeughalter halter, int anzahlRaeder, int anzahlTueren) {
        super(halter,"Pkw", anzahlRaeder);
        this.anzahlTueren = anzahlTueren;
    }

    public int gibAnzahlTueren() {
        return anzahlTueren;
    }

    public String toString() {
        return String.format("Dieses Fahrzeug ist ein %s mit %d Rädern und %d Türen. Es gehört %s.", this.gibFahrzeugart(), this.gibAnzahlRaeder(), this.gibAnzahlTueren(), this.getHalter());
    }
}
