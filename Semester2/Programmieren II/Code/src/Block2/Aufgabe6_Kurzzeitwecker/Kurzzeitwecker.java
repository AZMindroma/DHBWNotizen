package Block2.Aufgabe6_Kurzzeitwecker;

import java.util.Timer;
import java.util.TimerTask;

public class Kurzzeitwecker {
    private int minute;
    private int second;
    private int tenthSecond;

    public void setAlarm(int newMinute, int newSecond, int newTenthSecond) {
        this.minute = newMinute;
        this.second = newSecond;
        this.tenthSecond = newTenthSecond;
    }

    public void countdown() {
        Timer tenthSecondTimer = new Timer();
        TimerTask tenthSecondTask = new TimerTask() {

            @Override
            public void run() {
//                if (tenthSecond > 0) {
//                    tenthSecond--;
//                    System.out.println(minute + ":" + second + ":" + tenthSecond);
//                }
//                else {
//                    if (second == 0) {
//                        second = 60;
//                        minute--;
//                    } else {
//                        if (minute < 0) {
//                            return;
//                        } else {
//                            tenthSecond = 10;
//                            second--;
//                        }
//
//                    }
//                }
                if (tenthSecond > 0) {
                    tenthSecond--;
                } else {
                    tenthSecond = 9;
                    if (second > 0) {
                        second--;
                    } else {
                        if (minute > 0) {
                            minute--;
                            second = 59;
                        } else {
                            tenthSecondTimer.cancel();
                            return;
                        }
                    }
                }
                // System.out.println(minute + ":" + second + ":" + tenthSecond);
                System.out.printf("%02d:%02d:%02d\n", minute, second, tenthSecond);

            }
        };

        tenthSecondTimer.schedule(tenthSecondTask, 0, 100);
    }
}
