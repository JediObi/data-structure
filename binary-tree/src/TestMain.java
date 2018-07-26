import java.lang.StringBuilder;
public class TestMain{

    public static void test(StringBuilder stringBuilder){
        System.out.println("test "+stringBuilder.toString());
        stringBuilder = new StringBuilder("what is it now?");
        System.out.println("test "+stringBuilder.toString());
    }

    public static void main(String[] args) {
        StringBuilder stringBuilder = new StringBuilder("it is string builder");
        System.out.println("main "+stringBuilder.toString());
        test(stringBuilder);
        System.out.println("main "+stringBuilder.toString());
    }
}