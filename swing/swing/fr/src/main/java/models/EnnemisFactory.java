package models;

public class EnnemisFactory
{
    private static EnnemisFactory          me;
    private static long     id = 1;

    private EnnemisFactory()
    {
    }

    public static EnnemisFactory    getEnnemisFactory()
    {
        if (me == null)
        {
            me = new EnnemisFactory();
        }
        return me;
    }

    public Ennemis      newEnnemis(String p_type, int p_x, int p_y)
    {
        switch (p_type)
        {
            case "Hydre":
                return new E_Hydre(p_x, p_y);
            case "Squelette":
                return new E_Squelette(p_x, p_y);
            case "Troll":
                return new E_Troll(p_x, p_y);
            case "Vampire":
                return new E_Vampire(p_x, p_y);
            default:
                System.out.println("bad ennemis");
        }
        return null;
    }
}