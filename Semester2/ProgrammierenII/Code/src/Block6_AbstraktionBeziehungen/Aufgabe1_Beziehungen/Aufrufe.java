package Block6_AbstraktionBeziehungen.Aufgabe1_Beziehungen;

public class Aufrufe {
    public static void main(String[] args) {
        Fahrzeughalter halter = new Fahrzeughalter("AZMindroma");
        Fahrzeug fahrzeug = new Fahrzeug(halter, 16);
        Motorrad motorrad = new Motorrad(halter);
        Pkw pkw = new Pkw(halter, 4, 6);

        System.out.println(fahrzeug);
        System.out.println(motorrad);
        System.out.println(pkw);

        halter.setFahrzeug(fahrzeug);
    }
}
