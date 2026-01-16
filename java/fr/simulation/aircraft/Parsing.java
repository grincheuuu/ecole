package fr.simulation.aircraft;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;


//import fr.simulation.weather;

public class Parsing
{
    ArrayList<String>   texte;

    public Parsing(ArrayList<String> p_texte)
    {
        try
        {
            this.texte = p_texte;
        }
        catch (Exception e)
        {
            System.out.println("getMessage");
            System.out.println(e.getMessage());
            System.out.println(" ");
            System.out.println("toString");
            System.out.println(e.toString());
            System.out.println(" ");
            System.out.println("printStackTrace");
            e.printStackTrace();
        }
    }
    public boolean goodParsing()
    {
        Iterator<String>    it = texte.iterator();
        int                 i = 0;
    
        while (it.hasNext())
        {
            String ligne = it.next();
            int nombre = 0;
            if (i == 0)
            {
                try
                {
                    nombre = Integer.parseInt(ligne);
                    if (nombre < 0 || nombre > 1000)
                        throw new Exception("Bad first number");
//                    System.out.println(nombre);
                }
                catch (NumberFormatException e)
                {
                    e.printStackTrace();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                    return false;
                }
            }
            else
            {
                String[]    tab = ligne.split(" ");
                try
                {
                    if (tab.length != 5)
                        throw new Exception("Exception : error arguments scenario");
                    if (tab[0].compareTo("Baloon") != 0 && tab[0].compareTo("Helicopter") != 0 && tab[0].compareTo("JetPlane") != 0)
                        throw new Exception("Exception : unknow aircraft");
                    /** Une String n’est PAS un tableau de char , Une String est un objet
                     *  Pour accéder à un caractère d’une String, on utilise : charAt(index) */
                    if (!Character.isLetter(tab[1].charAt(0)) || !Character.isDigit(tab[1].charAt(1)))
                        throw new Exception("Bad name for the aircraft");
                    int longitude = Integer.parseInt(tab[2]);
                    int latitude = Integer.parseInt(tab[3]);
                    int height = Integer.parseInt(tab[4]);
                    if (height < 0 || height > 100)
                        throw new Exception("Bad height");
                }
                catch (NumberFormatException e)
                {
                    e.printStackTrace();
                }
                catch (Exception e)
                {
                    e.printStackTrace();
                }
//                for (String str : tab)
//                    System.out.println(str);
            }
//            System.out.println(ligne);
            i++;
        }
        return (true);
    }
}