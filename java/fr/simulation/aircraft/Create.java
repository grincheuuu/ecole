package fr.simulation.aircraft;
import fr.simulation.weather.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;

public class Create
{
    ArrayList<String>   texte;

    public Create(ArrayList<String> p_texte)
    {
        this.texte = p_texte;
    }

    public void createSimulation()
    {
        try
        {
            BufferedWriter   bw = new BufferedWriter(new FileWriter("simulation.txt"));
/**            bw.write("hello");
            bw.newLine();
            bw.write("word");*/
            simulationAction(bw);
            bw.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
            return;
        }
        catch (Exception e)
        {
            e.printStackTrace();
            return;            
        }
    }

    private void    simulationAction(BufferedWriter bw)
    {
        AircraftFactory     aFactory = AircraftFactory.getAircraftFactory();
        WeatherTower        wtower = new WeatherTower();
        Iterator<String>    it = texte.iterator();
        int                 i = 0;
        int                 nombreIteration = 0;

        wtower.setB(bw);    
        while (it.hasNext())
        {
            String      ligne = it.next();
            String[]    tab = ligne.split(" ");
            if (i == 0)
            {
                nombreIteration = Integer.parseInt(ligne);
            }
            else
            {
                Coordinates p_coordinates = new Coordinates(Integer.parseInt(tab[2]),
                Integer.parseInt(tab[3]), Integer.parseInt(tab[4]));
                
                Flyable a = aFactory.newAircraft(tab[0], tab[1], p_coordinates);
                a.registerTower(wtower);
                a.setB(bw);
            }
            i++;
        }
        i = 0;
        for (int h = 0; h < nombreIteration; h++)
        {
            wtower.conditionChanged();
        }
    }
}