package Block5_Vererbung.Aufgabe2_Polymorphismus;

public class Aufrufe {
    public static void main(String[] args) {
        Fahrzeug fahrzeug = new Fahrzeug(16);
        Pkw pkw = new Pkw(4, 5);
        Motorrad motorrad = new Motorrad();

        System.out.println(fahrzeug);
        System.out.println(pkw);
        System.out.println(motorrad);

        System.out.println();

        Fahrzeug[] fahrzeuge = new Fahrzeug[] {
                new Fahrzeug(16), new Pkw(4, 5), new Motorrad() };
        for (Fahrzeug f : fahrzeuge)
        {
            System.out.println(f);
        }
    }
}
