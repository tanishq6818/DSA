public class Main
{
  public static void permutations(String str,String permutation){
      if(str.length()==0){
          System.out.println(permutation);
          return;
      }
      for(int i=0;i<str.length();i++){
          char currchar=str.charAt(i);
          String ne=str.substring(0,i)+str.substring(i+1);
          permutations(ne,permutation+currchar);
      }
  }
  public static void main(String args[]){
      permutations("abc","");
  }
}


public static int Total_paths_in_a_matrix(int i,int j,int n,int m){
      if(i==n||j==m)    return 0;
      if(i==n-1 && j==m-1)  return 1;
      int down=Total_paths_in_a_matrix(i+1,j,n,m);
      int right=Total_paths_in_a_matrix(i,j+1,n,m);
      return down+right;
  }

  //placetiles across nxm over 1xm tiles;
    //See video 19 for more understanding
  public static int placeTiles(int n,int m){
      if(n==m)  return 2;
      if(n<m)   return 1;
      int horizontally=placeTiles(n-1,m);
      int vertically=placeTiles(n-m,m);
      return horizontally+vertically;
  }

public static int numberofguests(int n){
      if(n==1){
          return 1;
      }
      //single
      int single=numberofguests(n-1);
      //pair
      int pair=(n-1)*numberofguests(n-2);
      return pair+single;
  }

//Subset finding..

public static void printsubset(ArrayList<Integer> set){
      for(int i=0;i<set.size();i++){
          System.out.print(set.get(i)+" ");
      }
      System.out.println();
  }
  public static void subsets(int n,ArrayList<Integer> set){
      if(n==0){
          printsubset(set);
          return;
      }
      
      //add hoga
      set.add(n);
      subsets(n-1,set);
      
      //remove hoga
      set.remove(set.size()-1);
      subsets(n-1,set);
      
  }
