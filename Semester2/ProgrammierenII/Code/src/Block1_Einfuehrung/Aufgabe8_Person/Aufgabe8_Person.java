package Block1_Einfuehrung.Aufgabe8_Person;

public class Aufgabe8_Person {
    public static void main(String[] args) {
        Person person1 = new Person("AZ", "Mindroma", 19, "m");
        Person person2 = new Person("Emma", "Nightcore", 18, "w");

        System.out.printf("%s %s - %d Jahre Alt - Geschlecht: %s", person1.getVorname(), person1.getNachname(), person1.getAlter(), person1.getGeschlecht());
        System.out.println();
        System.out.printf("%s %s - %d Jahre Alt - Geschlecht: %s", person2.getVorname(), person2.getNachname(), person2.getAlter(), person2.getGeschlecht());

    }
}
