
import java.util.*;
public class Main
{
  static  StringBuilder rev(StringBuilder sb){
    for(int i=0;i<sb.length()/2;i++){
           int front=i;
           int n=sb.length()-i-1;
           char frontc=sb.charAt(front);
           char backc=sb.charAt(n);
           sb.setCharAt(front,backc);
           sb.setCharAt(n,frontc);
         }
        return (sb);
  }
	public static void main(String[] args) {
	    //String Immutable, String Builder mUtable
		Scanner sc=new Scanner(System.in);
        StringBuilder sb=new StringBuilder("Tony");
        System.out.println(sb.length());
        System.out.println(sb.charAt(0));
        sb.setCharAt(0,'L');
        System.out.println(sb);
        sb.insert(0,'C');
        System.out.println(sb);
        sb.delete(3,4);          //iterate from a to n-1
        System.out.println(sb);
        sb.delete(1,3);          //iterate from a to n-1
        System.out.println(sb);
        StringBuilder sb2=new StringBuilder("h");
        sb2.append("ell");
        System.out.println(sb2);

           StringBuilder sb3=new StringBuilder("Tony");
    System.out.print(rev(sb3));
           
	}
}
