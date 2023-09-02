public class Main
{
    public static int calc(int x,int n){
        if(n==0){
            return 1;
        }
        if(x==0){
            return 0;
        }
        if(n%2==0){
            return calc(x,n/2)*calc(x,n/2);
        }
        else{
            return calc(x,n/2)*calc(x,n/2)*x;
        }
    }

	
   public static void towerofHanoi(int n,char a,char b,char c){
        if(n==1){
            System.out.println("Transfer disk:"+n+" from "+a+" to "+c);
            return;
        }
        towerofHanoi(n-1,a,c,b);
        System.out.println("Transfer disk:"+n+" from "+a+" to "+c);
        towerofHanoi(n-1,b,a,c);
        
    }

	
    public static void strrev(String str,int idx){
        if(idx==0){
            System.out.println(str.charAt(idx));
            return ;
        }
        System.out.println(str.charAt(idx));
        strrev(str,idx-1);
    }


	
    public static int first=-1;
    public static int last=-1;
    public static void firstlastoccur(String str,int idx,char element){
        if(idx==str.length()){
            System.out.println(first);
            System.out.println(last);
            return;
        }
        char currstr=str.charAt(idx);
        if(currstr==element){
	        if(first==-1)
	            {
	                first=idx;
	            }
	        else{
	            last=idx;
	        }
        }
        firstlastoccur(str,idx+1,element);
    }


	
    public static boolean isSorted(int arr[],int idx){
        if(idx==arr.length-1){
            return true;
        }
        if(arr[idx]<=arr[idx+1]){
            return isSorted(arr,idx+1);
        }
        else{
            return false;
        }
    }


	
    public static void moveallX(int idx,String str,String newstr,int count){
        if(idx==str.length()){
            for(int i=0;i<count;i++){
                newstr+='x';
            }
            System.out.println(newstr);
            return;
        }
        char ch=str.charAt(idx);
        if(ch=='x'){
            count++;
            moveallX(idx+1,str,newstr,count);
        }
        else{
            newstr+=ch;
            moveallX(idx+!,str,newstr,count);
        }
    }

	public static boolean[] map=new boolean[26];
    public static void removeduplicates(int idx,String str,String newstr){
        if(idx==str.length()){
            System.out.println(newstr);
            return;
        }
        char ch=str.charAt(idx);
        if(map[ch-'a']){
            return removeduplicates(idx+1,str,newstr);
        }
        else{
            newstr+=ch;
            map[ch-'a']=true;
            return removeduplicates(idx+1,str,newstr);
        }
        
    }

	
	public static void main(String[] args) {
		int n=3;
		towerofHanoi(n,'A','B','C');
	}
}
