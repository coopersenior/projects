import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class DocCheck {

    public static void spellCheck(File processingFile, File dictionaryFile) {
        HashSet<String> dictionary = new HashSet<>();
        String text = "";
        String checkedText = "";
        try {
            File myObj = new File(String.valueOf(dictionaryFile));
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String word = myReader.nextLine();
                dictionary.add(word); // add all words from file into HashSet dictionary
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error with file.");
            e.printStackTrace();
        }
        // read in processingFile and check if in dictionary
        try {
            File myObj = new File(String.valueOf(processingFile));
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String word = myReader.nextLine();
                text += word;
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error with file.");
            e.printStackTrace();
        }
        String[] words = text.split("((?=[^a-zA-Z])|(?<=[^a-zA-Z]))");
        for (String word : words) {
            boolean flag = false;
            if (word.matches("[a-zA-Z]+")) {
                for (String correctSpelling : dictionary) { // goes through all words
                    if (word.toLowerCase().equals(correctSpelling)) {  // if word equals correct spelling its good
                        flag = true; // flag is true meaning its spelled correctly
                    }
                }
                if (flag) {
                    checkedText += word;
                } else {
                    checkedText += "<" + word + ">";
                }
            } else {
                checkedText += word; // adds other formatting to keep it the same
            }
        }
        String fileName = processingFile.toString();
        String[] finalName = fileName.split("\\.");  // needs "\\" in front of "." bc "." is a reserved character
        finalName[0] += "_spellChecked.txt";
        try {
            FileWriter myWriter = new FileWriter(finalName[0]);
            myWriter.write(checkedText); // prints to renamed file
            myWriter.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public static void wordCount(File processingFile) {
        HashMap<String, Integer> countPerWord = new HashMap<>();
        HashMap<Integer, HashSet<String>> wordsPerCount = new HashMap<>();
        String text = "";
        try {
            File myObj = new File(String.valueOf(processingFile));
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                text += myReader.nextLine();
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error with file.");
            e.printStackTrace();
        }
        String[] everything = text.split("((?=[^a-zA-Z])|(?<=[^a-zA-Z]))");
        String wordsOnly = "";
        for (int i = 0; i < everything.length; i++) {
            if (everything[i].matches("[a-zA-Z]+")) {
                wordsOnly += everything[i].toLowerCase() + ",";
            }
        }
        String[] words = wordsOnly.split(",");
        int count;
        for (String word : words) {
            count = 1;
            if (countPerWord.containsKey(word)) {
                count += countPerWord.get(word);
            }
            countPerWord.put(word, count);
        }
        Arrays.sort(words);
        String currentWord = "";
        String printer = "Alphabetic order word count:\n";
        for (String word : words) {
            if (!word.equals(currentWord)) {
                printer += word + ": " + countPerWord.get(word) + "\n";
            }
            currentWord = word;
        }
        for (String word : countPerWord.keySet()) {
            if (!wordsPerCount.containsKey(countPerWord.get(word))) {
                wordsPerCount.put(countPerWord.get(word), new HashSet<>());
            }
            wordsPerCount.get(countPerWord.get(word)).add(word);
        }
        String printLine = "";
        for (int num : wordsPerCount.keySet()) {
            count = wordsPerCount.get(num).size();
            for (String word : wordsPerCount.get(num)) {
                printLine = word + printLine;
                if (count > 1) {
                    printLine = ", " + printLine;
                    count--;
                }
            }
            printLine = "\n" + num + ": " + printLine;
        }
        String fileName = processingFile.toString();
        String[] finalName = fileName.split("\\.");  // needs "//" in front of "." bc "." is a reserved character
        finalName[0] += "_wordCount.txt";
        try {
            FileWriter myWriter = new FileWriter(finalName[0]);
            myWriter.write(printer); // prints to renamed file
            myWriter.write("\nBy occurrence word count:");
            myWriter.write(printLine);
            myWriter.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
