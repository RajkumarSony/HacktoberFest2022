
import java.util.Scanner;  // Import the Scanner class

public class Main
{
	public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);  // Create a Scanner object
    String string_main=sc.nextLine();    //take input for main string
    String substring= sc.nextLine();    //take input for substring which is supposed to be replaced   
    String new_substring= sc.nextLine();       //take input for new substring 

    System.out.println(string_main.replaceAll(substring,new_substring));     //print thenew string
 
}
}
