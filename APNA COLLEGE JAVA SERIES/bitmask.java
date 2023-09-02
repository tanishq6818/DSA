
import java.util.*;
public class Main
{
	public static void main(String[] args) {
	    //Get the 3rd bit of a number n(0101)
	   // 0101
	   //3 2 1 0
	   // Bit Mask:1<<i
	   // Operation:And
	   int n=5;
	   int pos=1;
	   int bitmask=1<<pos;
	   if((bitmask & n)==0){
	       System.out.println("bit was zero");
	   }
	   else{
	       System.out.println("bit was one");
	    }
	 //Set the 2nd bit of a number n(0101)
	   // Bit Mask:1<<i
	   // Operation:Or
	   pos=1;
	   bitmask=1<<pos;
	   int num=bitmask | n;
	   System.out.println(num);
	   
	    //Clear the 3nd bit of a number n(0101)
	   // Bit Mask:1<<i
	   // Operation:Or
	   pos=2;
	   bitmask=1<<pos;
	   num=~(bitmask) & n;
	   System.out.println(num);
	   
	   //Update/Toggle the bit according to the Operation
	   oper=1//update to 1 else 0
	   pos=1;
	   if(oper==1){
	       bitmask=1<<pos;
	       num=(bitmask) | 1;
	   }
	   else{
	       bitmask=1<<pos;
	       num=~(bitmask) & 1;
	   }
	    System.out.println(num);
}
}   
