// Similar to the subsequences question but we use hashmap
public class Main
{
   public static String[] keypad={".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
   public static void keycom(int idx,String str,String combinations){
       if(idx==str.length()){
           System.out.println(combinations);
           return;
       }
       char numstr=str.charAt(idx);
       String map=keypad[numstr-'0'];
       for(int i=0;i<map.length();i++){
           keycom(idx+1,str,combinations+map.charAt(i));
       }
   }
	public static void main(String[] args) {
		keycom(0,"23","");
	}
}
