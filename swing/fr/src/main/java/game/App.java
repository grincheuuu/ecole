package game;
import models.*;
import controler.*;


public class App 
{
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );
        Create  begin = new Create();
        begin.doCreate();
        GameControler   gc = new GameControler();
        gc.scan();
    }
}
