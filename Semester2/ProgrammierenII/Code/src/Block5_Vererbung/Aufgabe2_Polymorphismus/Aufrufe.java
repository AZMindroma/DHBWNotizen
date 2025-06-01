package Block5_Vererbung.Aufgabe2_Polymorphismus;

public class Aufrufe {
    public static void main(String[] args) {
        Fahrzeug fahrzeug = new Fahrzeug("allgemeines Fahrzeug", 16);
        Pkw pkw = new Pkw(4, 5);
        Motorrad motorrad = new Motorrad();

        System.out.println("Das Fahrzeug ist ein " + fahrzeug.gibFahrzeugart() + " mit " + fahrzeug.gibAnzahlRaeder() + " Rädern.");
        System.out.println("Das Fahrzeug ist ein " + pkw.gibFahrzeugart() + " mit " + pkw.gibAnzahlRaeder() + " Rädern und " + pkw.gibAnzahlTueren() + " Türen.");
        System.out.println("Das Fahrzeug ist ein " + motorrad.gibFahrzeugart() + " mit " + motorrad.gibAnzahlRaeder() + " Rädern.");
    }
}
