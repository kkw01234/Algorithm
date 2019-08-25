
//import javafx.util.Pair;
import java.io.*;
import java.util.*;
public class BOJ5427 {
    static char[][] arr;
    static boolean visited[][];
    static boolean notfire[][];
    static Queue<Pair<Integer, Integer>> fireQueue = new LinkedList<>();
    static Queue<Pair<Integer, Integer>> personQueue = new LinkedList<>();
    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,1,-1};
    static int N=0, w=0, h=0;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st;
        for(int k=0;k<N;k++){

            fireQueue.clear();
            personQueue.clear();
            st = new StringTokenizer(br.readLine());
            w = Integer.parseInt(st.nextToken());
            h = Integer.parseInt(st.nextToken());
            arr = new char[h+1][w+1];
            visited = new boolean[h+1][w+1];
            notfire = new boolean[h+1][w+1];
            for(int j=0;j<h;j++) {
                String[] str = br.readLine().split("");
                for (int i = 0; i < w; i++) {
                    arr[j][i] = str[i].charAt(0);
                    if (arr[j][i] == '*') {
                        notfire[j][i] = true;
                        fireQueue.add(new Pair<>(i, j));
                    } else if (arr[j][i] == '@') {
                        visited[j][i] = true;
                        personQueue.add(new Pair<>(i, j));
                    }
                }
            }
//            print();
            int result = bfs(0);
            if(result == -1){
                bw.write("IMPOSSIBLE\n");
            }else
                bw.write(Integer.toString(result)+"\n");
        }

        bw.flush();
        bw.close();
    }
    static int bfs(int level) {
        if(personQueue.isEmpty()){
            return -1;
        }
        int fqSize = fireQueue.size();
        for(int k=0;k<fqSize;k++){
            Pair<Integer, Integer> fire = fireQueue.poll();
            for(int i=0;i<4;i++){
                int fy = fire.getValue()+dy[i];
                int fx = fire.getKey()+dx[i];
                if(fx < 0 || fy <0||fx > w-1||fy > h-1 || arr[fy][fx] == '#'){
                    continue;
                }
                if(!notfire[fy][fx]){
                    notfire[fy][fx] = true;

                    arr[fy][fx] = '*';
                    fireQueue.add(new Pair<>(fx, fy));
                }
            }
        }
        //1 사람 한후
        int pqSize = personQueue.size();
        for(int k=0;k<pqSize;k++){
            Pair<Integer, Integer> person = personQueue.poll();

            for(int i=0;i<4;i++){
                int ay = person.getValue()+dy[i];
                int ax = person.getKey()+dx[i];

                if(ax < 0 || ay <0||ax > w-1||ay > h-1){

                    return level+1;
                }
                if(arr[ay][ax] == '#' || arr[ay][ax] =='*'){
                    continue;
                }
                if(!visited[ay][ax]){
                    visited[ay][ax] = true;
                    arr[ay][ax] = '@';
                    personQueue.add(new Pair<>(ax, ay));
                }
            }
        }

//        print();


        return bfs(++level);
        //2 불에서
    }
//    static void print(){
//        for(int j=0;j<h;j++){
//            for(int i=0;i<w;i++){
//                System.out.print(arr[j][i]);
//            }
//            System.out.println();
//        }
//        System.out.println();
//    }
}

class Pair<K,V>{
    private K k;
    private V v;
    Pair(K k, V v){
        this.k =k;
        this.v=v;
    }
    K getKey(){
        return k;
    }
    V getValue(){
        return v;
    }
}
/*
7번 
이유 : 1. x,y축 헷갈림으로 인해 코드 문제
2. 메모리 초과 : fireQueue, personQueue에 모든 것이 들어가지 않기 위해서 새로운 배열 생성후 불, 사람이 거기에 이동을 한적이 있으면 Queue에 넣지 않게 해야한다.
-> 지나친데도 들어가게 되면 무한정으로 Queue에 들어가게 된다.
3. 불, 사람 : 불 먼저 움직인후, 사람을 움직이게 해야한다. => 반대의경우 불이 붙었는데도 탈출할 수 있는 반례가 있음

1
5 7
...#*
..##.
##.#.
#@...
##.#.
..##.
...#*
//correct answer:IMPOSSIBLE

*/