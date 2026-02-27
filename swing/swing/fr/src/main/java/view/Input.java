package view;
import models.*;
import controler.*;
import java.util.HashMap;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Input
{
    HashMap<Integer, String>    tuile;
    private static final Logger logger = LoggerFactory.getLogger(Input.class);

    Input()
    {
        this.tuile = new HashMap<>();
        tuile.put(0, "🌌");
        tuile.put(1, "🦇");
        tuile.put(2, "🧌");
        tuile.put(3, "👿");
        tuile.put(4, "🐲");
        tuile.put(5, "🧟");
        tuile.put(6, "🧔");
        tuile.put(7, "🧙");
    }

    void    beginGame()
    {
        Create  begin = new Create();
        begin.doCreate();
        System.out.println("");
        System.out.println("----------------------------");
        System.out.println("  WELCOME IN THIS GAME");
        System.out.println("-----------------------------");
        GameControler   gc = new GameControler(begin, this);
        gc.scan();
        System.out.println("----------------------------");
        System.out.println("  SEE YOU SOON");
        System.out.println("-----------------------------");
    }

    public void    output(int[] tab)
    {
        for (Integer i: tab)
        {
            String  tile = tuile.get(i);
            System.out.print(tile);
        }
        System.out.println();
    }

    public void     PrintResult(String everything)
    {
        System.out.println(everything);
    }
}