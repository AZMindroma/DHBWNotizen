package Block6_AbstraktionBeziehungen.Aufgabe1_Beziehungen;

public class Fahrzeug {
    private String fahrzeugart;
    private int anzahlRaeder;

    public Fahrzeug(int anzahlRaeder) {
        this.anzahlRaeder = anzahlRaeder;
        this.fahrzeugart = "allgemeines Fahrzeug";
    }

    public Fahrzeug(String fahrzeugart, int anzahlRaeder) {
        this.fahrzeugart = fahrzeugart;
        this.anzahlRaeder = anzahlRaeder;
    }

    public String gibFahrzeugart() {
        return fahrzeugart;
    }

    public int gibAnzahlRaeder() {
        return anzahlRaeder;
    }

    public String toString() {
        return String.format("Das Fahrzeug ist ein %s mit %d Rädern.", this.fahrzeugart, this.anzahlRaeder);
    }
}
