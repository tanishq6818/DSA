//PATTERNS

class Main {
    public static void main(String[] args) {
      //Pattern1:
      // *****
      // *****
      // *****
      // *****
      for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                System.out.print("*");
            }
            System.out.println();
        }
      
      //Pattern2:
      // *****
      // *   *
      // *   *
      // *****
      
      for(int i=0;i<4;i++){
            for(int j=0;j<5;j++){
                if(i==0 || i==3 || j==0 || j==4)
                    System.out.print("*");
                else
                    System.out.print(" ");
            }
            System.out.println();
        }
      //Pattern3:
      //     *
      //    **
      //   ***
      //  ****
      for(int i=0;i<4;i++){
            for(int j=0;j<4-i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<i;j++){
                System.out.print("*");
            }
            System.out.println();
        }
      
// 123
// 12
// 1


      for(int i=1;i<=4;i++){
            for(int j=1;j<=4-i;j++){
                System.out.print(j);
            }
            System.out.println();
        }
        
    }
}

//Butterfly pattern 
      
// *    *
// **  **
// ******
// ******
// **  **
// *    *
      

public static void main(String[] args) {
        int n=4;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                System.out.print("*");
            }
            for(int j=0;j<2*(n-i-1);j++){
                System.out.print(" ");
            }
            for(int j=0;j<i;j++){
                System.out.print("*");
            }
            System.out.println();
        }
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n-i-1;j++){
                System.out.print("*");
            }
            for(int j=0;j<2*i;j++){
                System.out.print(" ");
            }
            for(int j=0;j<n-i-1;j++){
                System.out.print("*");
            }
            System.out.println();
        }
        
    }

//    ****
//   ****
//  ****
// ****

 public static void main(String[] args) {
        int n=4;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            for(int j=0;j<n;j++){
                System.out.print("*");
            }
            
            System.out.println();
        }
        
    }
   
//   0 
//  0 1 
// 0 1 2 

public static void main(String[] args) {
        int n=4;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            for(int j=0;j<i;j++){
                System.out.print(j+" ");
            }
            
            System.out.println();
        }
        
    }

//    0
//   101
//  21012
// 3210123


 public static void main(String[] args) {
        int n=4;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n-i-1;j++){
                System.out.print(" ");
            }
            for(int j=i;j>=0;j--){
                System.out.print(j);
            }
            for(int j=1;j<=i;j++){
                System.out.print(j);
            }
            System.out.println();
        }
        
    }
