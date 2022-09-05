import java.util.Scanner
public class hangman {
    public static void main(String[] args) {
        System.out.println("Hello and welcome to Hangman!");    
        System.out.println("Let's begin by explaining the rules. A random word will be chosen and you will be given a certain number of tries to guess the word"); 
        String notused = "abcdefghijklmnopqrstuvwxyz"
        String [] wordlist = new String[] { "apple", "fruit", "baseball", "basketball", "green", "red"};
        String random = wordslist[(int) (Math.random * wordlist.length)]; 
        System.out.println("The word has " + random.length() + " letters")

        char [] letters = new char[random.length()]
        for (int i = 0; i < letters.length; i++){
            letters[i] = '.'; 
        }
        int chances = 5
        Scanner scanner = new Scanner(System.in)

        while (chances > 0){
            System.out.print("Your chances: ")

            for (int i = 0; i < chances; i++){
                System.out.print("0")
            }
            System.out.println();
            System.out.println("Input: ")
            String input = scanner.nextLine()

            char letter = input.charAt(0)

            boolean isCorrect = false

            for (int i = 0; i < random.length(); i++){
                char l = random.charAt(i);

                if (l == letter) {
                    letters[i] = l; 
                    isCorrect = true;
                }
            }
            if (!isCorrect){
                lives--; 
            }

            boolean isFinished = true; 

            System.out.println("The word is: ");
            for (int i = 0; i < letters.length(), i++){
                if (letters[i] == '.'){
                    isFinished = false;
                }
                System.out.print(letters[i])
            }
            System.out.println();
            notUsed = notUsed.replace(letters, ".")
            System.out.println("Not used: " + notUsed);
            System.out.println("-----------------------"); 
            if (isFinished){
                System.out.println("You won!");
                break; 
            }
        }
        if (lives == 0){
            System.out.println("You lost! The word was: " + randomWord);
        }
        System.out.println("Thanks for playing!")
    }
}