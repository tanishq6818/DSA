
import java.util.HashSet;
public class Main
{
   public static void uniquesubsequences(int idx,String str,String newstr,set){
       if(idx==str.length()){
           if(set.contains(newstr)){
               return;
           }
           else{
               set.add(newstr);
               System.out.println(newstr);
               return;
           }
          
       }
       char ch=str.charAt(idx);
       //Whether a char goes to the string at random : Case 1
        subsequences(idx+1,str,newstr+ch,set);
        //Whether a char dont want to go to the string at random : Case 2
        subsequences(idx+1,str,newstr,set);
   }
	public static void main(String[] args) {
		int n=3;
		HashSet<String> set=new HashSet<>;
		uniquesubsequences(0,"abc","",set);

	}
}
