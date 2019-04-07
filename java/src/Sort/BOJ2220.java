import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;


public class BOJ2220 {

    public static void main(String[] args) throws Exception {
        int arr[]=new int[100001];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        for(int i=1;i<=n;i++){
            arr[i]=i;
            if(i!=1){
                int j = i-1;
                swap(arr,i,j);
                for(;j>1;j=j/2){
                    swap(arr,j,j/2);
                }
            }
        }

        for(int i=1;i<=n;i++)
            bw.write(Integer.toString(arr[i])+" ");
        bw.flush();
        bw.close();
    }
    static void swap(int arr[],int a,int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;

    }
}