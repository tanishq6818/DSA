
//Permutations
public static void permutations(String str,String permutation){
      if(str.length()==0){
          System.out.println(permutation);
          return;
      }
      for(int i=0;i<str.length();i++){
          char currchar=str.charAt(i);
          String newstr=str.substring(0,i)+str.substring(i+1);
          permutations(newstr,permutation+currchar);
      }
  }


//N-queen
class Solution {
    public boolean isSafe(int row,int col,char[][] board){
        //horizontally
        for(int i=0;i<board.length;i++){
            if(board[row][i]=='Q')  return false;
        }
        //vertically
        for(int j=0;j<board[0].length;j++){
            if(board[j][col]=='Q')  return false;
        }
        //upperright
        int r=row;
        for(int c=col;c<board.length && r>=0;r--,c++){
            if(board[r][c]=='Q')  return false;
        }
        //upperleft
        r=row;
        for(int c=col;c>=0 && r>=0;r--,c--){
            if(board[r][c]=='Q')  return false;
        }
        //downleft
        r=row;
        for(int c=col;c>=0 && r<board.length;r++,c--){
            if(board[r][c]=='Q')  return false;
        }
        //downright
        r=row;
        for(int c=col;c<board.length && r<board.length;r++,c++){
            if(board[r][c]=='Q')  return false;
        }
        return true;
    }
    public void saveboard(List<List<String>> allboards,char[][] board){
        String row="";
        List<String> newboard=new ArrayList<>();
        for(int i=0;i<board.length;i++){
            row="";
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='Q'){
                    row+="Q";
                }
                else{
                    row+=".";
                }
            }
            newboard.add(row);
        }
        allboards.add(newboard);
    }
    public void helper(List<List<String>> allboards,char[][] board,int col){
        if(col==board.length){
            saveboard(allboards,board);
            return;
        }
        for(int row=0;row<board.length;row++){
            if(isSafe(row,col,board)){
                board[row][col]='Q';
                helper(allboards,board,col+1);
                board[row][col]='.';
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> allboards=new ArrayList<>();
        char[][] board=new char[n][n];
        helper(allboards,board,0);
        return allboards;
    }
}
