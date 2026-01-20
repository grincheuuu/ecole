package fr.simulation.aircraft;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.util.List;
import java.util.ArrayList;

import fr.simulation.weather.*;


public class    Simulator
{
    public static void main(String[] args)
    {
        ArrayList<String> texte = new ArrayList<String>();

        try
        {
//            System.out.println(args[0]);
            int nb = args.length;
            if (nb > 1)
                throw new Exception("Exception: bad numbers of arguments");
            FileReader fichier = new FileReader(args[0]);
            BufferedReader buf = new BufferedReader(fichier);

            String line;
            while ((line = buf.readLine()) != null)
                texte.add(line);
//            System.out.println(texte);
            buf.close();
        }
        catch (FileNotFoundException e)
        {
            System.out.println("Exception: File not found");
        }
        catch (IndexOutOfBoundsException e)
        {
            System.out.println("Exception: Index out of bound");
        }
        catch (IOException e)
        {
            System.out.println("Exception: erreur close file");
            e.printStackTrace();
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
        Parsing parse = new Parsing(texte);
        try
        {
            if (parse.goodParsing() == false)
            {
                throw new Exception("Exception: Bad parsing");
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
            return;
        }
        Create  creation = new Create(texte);
        creation.createSimulation();
    }
}