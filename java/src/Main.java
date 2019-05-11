import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main{
    public static void main(String[] args){
        superclass s = new subclass();
        s.paint();
    }
}
class superclass{
    public void paint(){
        draw();
    }
    public void draw(){
        draw();
        System.out.println("super");
    }
}

class subclass extends superclass{
    public void paint(){
        super.draw();
    }
    public void draw(){
        System.out.println("sub");
    }
}
