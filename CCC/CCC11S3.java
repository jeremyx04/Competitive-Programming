import java.util.Scanner;

public class CCCS311 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            int mag = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();
            System.out.println(isCrystal(mag, x, y) ? "crystal" : "empty");
        }
    }

    static boolean isCrystal(int mag, int x, int y) {
        boolean crystal= false;
        int xx=(int)(x/Math.pow(5,mag-1));
        int yy=(int)(y/Math.pow(5,mag-1));
        if((yy==0&&(xx==1||xx==2||xx==3))||(yy==1&&xx==2))
            crystal=true;
        else if(mag!=1 && ((yy==1&&(xx==1||xx==3)) ||(xx==2&&yy==2))){
            crystal=isCrystal(mag-1, x%(int)Math.pow(5,mag-1), y%(int)Math.pow(5,mag-1));
        }
        return crystal;
    }
}
