public class ques {

    public void decreasing(int n) {
        // base case:
        if (n == 0)
            return;

        System.out.println(n);
        decreasing(n - 1);
    }

    public void increasing(int n) {
        // base case:
        if (n == 0) {
            return;
        }

        increasing(n - 1);
        System.out.println(n);
    }

    public void decreasingInc(int n) {
        // base case:
        if (n == 0)
            return;

        // if even
        if (n % 2 == 0)
            System.out.println(n);
        decreasingInc(n - 1);
        if (n % 2 != 0) {
            System.out.println(n);
        }
    }

    public int factorial(int n) {
        return n == 0 ? 1 : n * factorial(n - 1);
    }

    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
