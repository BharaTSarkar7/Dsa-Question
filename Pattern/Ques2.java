package Pattern;

import java.util.Scanner;

public class Ques2 {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("Enter the rows : ");
            int n = in.nextInt();
            for (int i = n; i > 0; i--) {
                for (int j = i; j > 0; j--) {
                    System.out.print("*");
                }
                System.out.println();
            }
        }
    }
}
