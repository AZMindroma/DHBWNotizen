package Block6_AbstraktionBeziehungen.Aufgabe1_Beziehungen;

public class Fahrzeug {
    private Fahrzeughalter halter;

    private String fahrzeugart;
    private int anzahlRaeder;

    public Fahrzeug(Fahrzeughalter halter, int anzahlRaeder) {
        this.halter = halter;
        this.anzahlRaeder = anzahlRaeder;
        this.fahrzeugart = "allgemeines Fahrzeug";
    }

    public Fahrzeug(Fahrzeughalter halter, String fahrzeugart, int anzahlRaeder) {
        this.halter = halter;
        this.fahrzeugart = fahrzeugart;
        this.anzahlRaeder = anzahlRaeder;
    }

    public Fahrzeughalter getHalter() {
        return halter;
    }

    public String gibFahrzeugart() {
        return fahrzeugart;
    }

    public int gibAnzahlRaeder() {
        return anzahlRaeder;
    }

    public String toString() {
        return String.format("Dieses Fahrzeug ist ein %s mit %d Rädern. Es gehört %s.", this.fahrzeugart, this.anzahlRaeder, this.getHalter());
    }
}
