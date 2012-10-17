import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;

import static java.lang.Math.exp;
import static java.lang.Math.log;
import static java.lang.Math.nextAfter;

public class Main {

    static InputReader in;
    static OutputWriter out;
    static MathContext mc = new MathContext(250);


    public static void solve() {
    }

    public static void main(String[] args) throws IOException {
        in = new InputReader(new FileInputStream("input.txt"));
        out = new OutputWriter(new FileOutputStream("output.txt"));
        //in = new InputReader(System.in);
        //out = new OutputWriter(System.out);

        long t1 = System.currentTimeMillis();

        solve();

        out.close();

        long t2 = System.currentTimeMillis();

        System.err.print("Execution time: " + (t2 - t1) / 1000.0);

    }
}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public BigInteger readLong() {
        StringBuilder sb = new StringBuilder();
        while (true) {
            int i = read();
            if (i >= '0' && i <= '9') {
                sb.append(i - '0');
            }
            else
                break;
        }
        BigInteger result = new BigInteger(sb.toString());
        return result;
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(outputStream);
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0)
                writer.print(' ');
            writer.print(objects[i]);
        }
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void close() {
        writer.close();
    }

}

