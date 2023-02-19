/* *
   **
   ***
   ****
   *****  
 */
package Pattern;

import java.util.Scanner;

public class Ques1 {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("enter the rows : ");
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    System.out.print("*");
                }
                System.out.println();
            }
        }  catch (Exception e) {
            System.out.println(e);
        }
    }
}
