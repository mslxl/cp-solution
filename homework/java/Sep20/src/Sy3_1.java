import java.time.*;
public class Sy3_1 {
    public static void main(String[] args) {
        LocalDate date = LocalDate.now();
        int year = date.getYear();
        int month = date.getMonthValue();
        int today = date.getDayOfMonth();
        System.out.println(month + " " + year);
        date = date.minusDays(today-1);
        DayOfWeek weekday = date.getDayOfWeek();
        int value = weekday.getValue();
        System.out.println("SUN MON TUE WED THU FRI SAT");
        for(int i = 0;i < value&&value < 7;i++)
            System.out.print("    ");
        while(date.getMonthValue() == month)
        {
            System.out.printf("%3d",date.getDayOfMonth());
            if(date.equals(LocalDate.now()))
                System.out.print("*");
            else
                System.out.print(" ");
            date = date.plusDays(1);
            if(date.getDayOfWeek().getValue() == 7)
                System.out.println();
        }
    }
}