package controler;
import models.MajGame;
import models.Create;
import models.MapTile;
import view.Input;
import java.util.Scanner;

public class GameControler
{
    private Create      begin;
    private MajGame     majGame = null;
    private Input       input;
    private MapTile.Tile[][]    map;

    public GameControler(Create p_begin, Input in)
    {
        this.begin = p_begin;
        this.map = begin.getMap();
        this.input = in;
    }

    public void     scan()
    {
        Scanner sc = new Scanner(System.in);
        this.majGame = new MajGame();
        int         i = 0;

        begin.registerMg(majGame);
        try
        {
            printMap();
            while (true)
            {
                String  inp = sc.next();
                if (inp.equals("w") || inp.equals("a") || inp.equals("d") || inp.equals("s"))
                {
                    String  state = this.majGame.move(inp);
                    if(state.equals("win"))
                    {
                        input.PrintResult("win");
                        throw new Exception("WIN");
                    }
                    if(state.equals("loose"))
                    {
                        input.PrintResult("loose");
                        throw new Exception("LOOSE");
                    }
                    if(state.equals("choose artefact"))
                    {
                        input.PrintResult("choose artefact");
                        i = 1;
                    }
                    printMap();
                }
                if (inp.equals("q"))
                {
                    throw new Exception("inp = null");
                }
            }
        }
        catch (Exception e)
        {
            sc.close();
        }
    }

    private void        printMap()
    {
        int     w = begin.getWidth();
        int[]   tab = new int[w];

        for (int y = 0; y < w; y++)
        {
            for (int x = 0; x < w; x++)
            {
                tab[x] = map[y][x].ordinal();
            }
            input.output(tab);
        }        
    }
}

/*                if (i == 1)
                {
                    System.out.println("YOU WIN AN ARTEFACT : do you want to equip him");
                    System.out.println("tape : YES or NO");
                    if (inp.equals("YES") || inp.equals("yes"))
                    {
                        this.majGame.artefactSelection(0);
                    }
                    if (inp.equals("NO")|| inp.equals("no"))
                    {
                        this.majGame.artefactSelection(1);
                    }
                    i = 0;
                }*/