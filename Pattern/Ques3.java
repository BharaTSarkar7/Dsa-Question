package Pattern;

import java.util.Scanner;

public class Ques3 {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("Enter the rows : ");
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                for (int j = n; j > i; j--) {
                    System.out.print(" ");
                }
                for (int k = 0; k <= i; k++) {
                    System.out.print("*");
                }
                System.out.println();
            }
        }

    }
}
