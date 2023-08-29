/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/
import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    //String Immutable, String Builder mUtable
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
// 		System.out.println(s.length());
		for(int i=0;i<s.length();i++){
		  //  System.out.println(s.charAt(i));
		}
		String s2=sc.nextLine();
// 		if(s.compareTo(s2)==0){     //We can also use == operator but ot shows error because both are different Object.
// 		    System.out.print("Strings are equal");
// 		}
		
		if(new String("Tony")!=new String("Tony")){     //Example of ==(Thats why we use String Builder)
		  //  System.out.print("Strings are not equal");
		}
		
		String sentence="MYself Tony";
		String name=sentence.substring(7,sentence.length());
		System.out.print(name);
	}
}
