package Block2_Grundlagen.Aufgabe4_Quersumme;

public class Quersumme {
    private int number;

    public Quersumme(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public int getQuersumme() {
        int quersumme = 0;

        while (number > 0) {
            quersumme += number % 10;
            number = number / 10;
        }

        return quersumme;
    }
}
