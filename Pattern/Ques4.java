package Pattern;

import java.util.Scanner;

public class Ques4 {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("Enter the rows : ");
            int n = in.nextInt();
            for (int i = n; i > 0; i--) {
                for (int j = 0; j < n-i; j++) {
                    System.out.print(" ");
                }
                for (int k = i; k > 0; k--) {
                    System.out.print("*");
                }
                System.out.println();
            }
        }
    }
}
