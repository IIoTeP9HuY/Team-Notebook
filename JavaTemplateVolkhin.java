import java.io.*;
import java.util.StringTokenizer;

public class Main implements Runnable {
    void solve() {
        int a = nextInt(), b = nextInt();
        int c = a + b;
        writer.println(c);
    }


    private BufferedReader reader;
    private PrintStream writer;
    private StringTokenizer st;

    public static void main(String[] args) {
        new Main().run();
    }

    @Override
        public void run() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintStream(System.out);
            solve();
            writer.close();
        }

    String next() {
        if (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(reader.readLine());
            } catch (IOException e) {

            }
        }

        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }
}

