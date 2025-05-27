package Block2.Aufgabe6_Kurzzeitwecker;

public class Execution {
    public static void main(String[] args) {
        Kurzzeitwecker w = new Kurzzeitwecker();
        w.setAlarm(1, 12, 4);
        w.countdown();
    }
}
