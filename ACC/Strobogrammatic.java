package ACC;
import java.util.*;
public class Strobogrammatic {
    public static void main(String[] args) {
        int flag=1;
        Scanner sc = new Scanner(System.in);
        String num = sc.next();
        String str = "";
        for (int i = 0; i < num.length(); i++) {
            if (num.charAt(i) == '0')
                str += '0';
            else if (num.charAt(i) == '1')
                str += '1';
            else if (num.charAt(i) == '6')
                str += '9';
            else if (num.charAt(i) == '9')
                str += '6';
            else if (num.charAt(i) == '8')
                str += '8';
            else{
                System.out.println("Not Strobogrammatic");
                flag=0;
                break;
            }
        }
        StringBuffer str1 = new StringBuffer(str);
        str1.reverse();
        str = str1.toString();
        if(flag==1)
        {
            if (num.equals(str))
            System.out.println("is Strobogrammatic");
        else
            System.out.println("Not Strobogrammatic");
        }
        sc.close();
    }
}