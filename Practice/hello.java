import java.util.Scanner;//scanner class import 

public class hello {

    public static int Sum(int[] arr) {
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        return sum;
    }

    public static void main(String[] args) {

        // user input
        // it is taken with the help of the scanner class
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int n = sc.nextInt();

        int[] arr = new int[n];
        // taking input of the elements in the array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // passing the array to the function
        int sum = Sum(arr);
        System.out.println("The sum of the elements is = " + sum);
    }

}