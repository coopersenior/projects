/*
Cooper Senior
Connor Parrott
McKenna Fobes
 */
import java.io.File;

public class Driver {

    public static void main(String[] args) {
        File dictionaryFile = new File("words.txt");
        File processingFile = new File("test.txt");
        DocCheck.spellCheck(processingFile, dictionaryFile);
        DocCheck.wordCount(processingFile);
    }
}
