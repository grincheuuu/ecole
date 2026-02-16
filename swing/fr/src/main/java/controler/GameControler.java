package controler;
import java.util.Scanner;

public class GameControler
{
    public GameControler()
    {
    }

    public void     scan()
    {
        Scanner sc = new Scanner(System.in);
/**        System.out.print("mouvement : ");
        String  input = sc.next();
        System.out.println(input);
        System.out.print("mouvement : ");
        String  input2 = sc.next();
        System.out.println(input2);
        String  inp = sc.next();
        for (int i = 0; i < 3; i++)
        {
            System.out.print("action : ");
            String  inp = sc.next();
            int     nombre = (int)inp;
            System.out.println(inp);
            System.out.println(nombre);          
        }
        sc.close();*/
        try
        {
            while (true)
            {
                String  inp = sc.next();
                System.out.println(inp);  
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
}