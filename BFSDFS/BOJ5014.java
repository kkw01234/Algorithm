
import java.io.*;
import java.util.*;

public class BOJ5014 {
    static ArrayList<Integer> visited = new ArrayList<>();
    static int F=0,S=0,G=0,U=0,D=0;
    static int[] tb = new int[2];
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str);
        while(st.hasMoreTokens()){
            F = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());
            G = Integer.parseInt(st.nextToken());
            U = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());
        }
        for(int i=0;i<F+1;i++){ //1부터하기 위함
            visited.add(1000001);
        }//초기화
        tb[0] = U;
        tb[1] = -D;
        int result = bfs(S, G);
        if(result >= 0)
            bw.write(Integer.toString(result));
        else
            bw.write("use the stairs");
        bw.flush();
        bw.close();
    }
    static int bfs(int start, int end){
        visited.set(S, 0);
        Queue<Integer> q= new LinkedList<>();
        q.add(start);
        boolean complete = false;
        while(!q.isEmpty()){
            int qsize = q.size();
            for(int k =0;k<qsize;k++){
                int x = q.peek();
                q.remove();
                if(x == end){
                    complete = true;
                    break;
                }
                for(int i=0;i<2;i++){
                    int dx = x+tb[i];
                    if(dx <= 0 || dx > F) {
                        continue;
                    }
                    if(visited.get(dx) > visited.get(x)+1) {
                        visited.set(dx, visited.get(x) + 1);
                        q.add(dx);
                    }
                }
            }
        }
        if(complete)
            return visited.get(end);
        else
            return -1;
    }

}
