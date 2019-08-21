import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class BOJ1838 {

    public static void main(String[] args) throws Exception {
        Vector<Indexplus> arr = new Vector<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        String str = br.readLine();
        st= new StringTokenizer(str);
        for(int i=0;i<n;i++){
            Indexplus plus = new Indexplus(i,Integer.parseInt(st.nextToken()));
            arr.add(plus);
        }

        Collections.sort(arr);
        int max = 0;
        for(int i=0;i<n;i++){
            int a=arr.get(i).index-i;
            if(max<a){
                max =a;
            }

        }


        bw.write(Integer.toString(max));
        bw.flush();
        bw.close();


    }

    static class Indexplus implements Comparable<Indexplus> {
        public int index;
        public int value;

        public Indexplus(int index,int value){
            this.index=index;
            this.value=value;
        }

        @Override
        public int compareTo(Indexplus o) {
            if(this.value>o.value){
                return 1;
            }else if(this.value==o.value){
                return 0;
            }else
                return -1;
        }

    }
}