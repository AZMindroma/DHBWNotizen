package Block1_Einfuehrung.Aufgabe8_Person;

public class Person {
    private String vorname;
    private String nachname;
    private int alter;
    private String geschlecht;

    public Person(String vorname, String nachname, int alter, String geschlecht) {
        this.vorname = vorname;
        this.nachname = nachname;
        this.alter = alter;
        this.geschlecht = geschlecht;
    }

    public String getVorname() {
        return vorname;
    }

    public void setVorname(String vorname) {
        this.vorname = vorname;
    }

    public String getNachname() {
        return nachname;
    }

    public void setNachname(String nachname) {
        this.nachname = nachname;
    }

    public int getAlter() {
        return alter;
    }

    public void setAlter(int alter) {
        this.alter = alter;
    }

    public String getGeschlecht() {
        return geschlecht;
    }

    public void setGeschlecht(String geschlecht) {
        this.geschlecht = geschlecht;
    }
}
