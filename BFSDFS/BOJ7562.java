import javafx.util.Pair;
import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ7562 {
    static int[] dx = {1,2,1,2,-1,-2,-1,-2};
    static int[] dy = {2,1,-2,-1,-2,-1,2,1};
    static boolean[][] visited;
    static int I;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        int N = Integer.parseInt(br.readLine());

        for(int i=0;i<N;i++){
            I = Integer.parseInt(br.readLine());
            visited = new boolean[I+1][I+1];
            String str = br.readLine();
            StringTokenizer st = new StringTokenizer(str);
            Pair<Integer, Integer> first;
            Pair<Integer, Integer> second;
            int x=0, y=0;
            while(st.hasMoreTokens()){
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
            }
            first = new Pair<>(x, y);
            str = br.readLine();
            st = new StringTokenizer(str);
            while(st.hasMoreTokens()){
                x = Integer.parseInt(st.nextToken());
                y = Integer.parseInt(st.nextToken());
            }
            second = new Pair<>(x, y);
            int result = bfs(first, second);
            bw.write(Integer.toString(result)+"\n");
        }



        bw.flush();
        bw.close();
    }
    static int bfs(Pair<Integer, Integer> a, Pair<Integer, Integer> b){
        Queue<Pair<Integer, Integer>> q= new LinkedList<>();
        q.add(a);
        int level = 0;
        while(!q.isEmpty()){
            int qsize = q.size();
            for(int i=0;i<qsize;i++){
                int x = q.peek().getKey();
                int y = q.peek().getValue();
                q.remove();
                if(x == b.getKey() && y == b.getValue()){
                    q.clear();
                    break;
                }
                for(int j=0;j<8;j++){
                    if(x+dx[j] < 0 || y + dy[j]<0 || x+dx[j] > I-1 || y+dy[j] > I-1){
                        continue;
                    }
                    if(!visited[x+dx[j]][y+dy[j]]){
                        visited[x+dx[j]][y+dy[j]] = true;
                        q.add(new Pair<>(x+dx[j], y+dy[j]));
                    }
                }
            }
            level++;
        }
        return level-1;
    }

}