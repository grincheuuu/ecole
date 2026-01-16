package fr.simulation.aircraft;
import fr.simulation.weather.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

public class Create
{
    ArrayList<String>   texte;

    public Create(ArrayList<String> p_texte)
    {
        this.texte = p_texte;
    }
    public void createSimulation()
    {
        AircraftFactory  AFactory = AircraftFactory.getAircraftFactory();
        WeatherTower     Wtower = new WeatherTower();
        List<Flyable>    flyables = new ArrayList<Flyable>(); 
        Iterator<String>    it = texte.iterator();
        int                 i = 0;
        int                 nombreIteration = 0;

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
                Coordinates p_coordinates = new Coordinates(Integer.parseInt(tab[2]), Integer.parseInt(tab[3]), Integer.parseInt(tab[4]));

                Flyable a = AFactory.newAircraft(tab[0], tab[1], p_coordinates);
                flyables.add(a);
                a.registerTower(Wtower);
                try
                {

                }
                catch (Exception e)
                {

                }
            }
            i++;
        }
        i = 0;
        for (int h = 0; h < nombreIteration; h++)
        {
            switch(i)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    i = 0;
                default:
                    break;
                    
            }
        }


    }
}