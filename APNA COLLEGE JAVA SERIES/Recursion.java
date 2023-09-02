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
	public static void main(String[] args) {
		int n=3;
		towerofHanoi(n,'A','B','C');
	}
}
