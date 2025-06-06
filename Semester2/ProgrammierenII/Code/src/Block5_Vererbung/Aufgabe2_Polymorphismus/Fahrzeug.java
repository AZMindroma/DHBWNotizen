package Block5_Vererbung.Aufgabe2_Polymorphismus;

public class Fahrzeug {
    private String fahrzeugart;
    private int anzahlRaeder;

    public Fahrzeug(String fahrzeugart) {
        this.fahrzeugart = fahrzeugart;
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
}
