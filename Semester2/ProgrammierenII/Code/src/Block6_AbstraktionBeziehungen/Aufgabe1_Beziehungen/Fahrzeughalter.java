package Block6_AbstraktionBeziehungen.Aufgabe1_Beziehungen;

public class Fahrzeughalter {
    private Fahrzeug fz;
    private String name;

    public Fahrzeughalter(String name) {
        this.name = name;
    }

    public void setFahrzeug(Fahrzeug fz) {
        this.fz = fz;
    }

    public Fahrzeug getFahrzeug() {
        return fz;
    }

    public String toString() {
        return String.format("Das Fahrzeug von %s ist ein %s mit %d Rädern.", name, fz.gibFahrzeugart(), fz.gibAnzahlRaeder());
    }
}
