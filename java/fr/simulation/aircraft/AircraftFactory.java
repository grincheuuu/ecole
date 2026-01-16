package fr.simulation.aircraft;

import fr.simulation.weather.Flyable;
import fr.simulation.weather.Tower;
import fr.simulation.weather.WeatherTower;

public class AircraftFactory //singleton
{
    private static AircraftFactory  AFactory;
    private static long              id = 1;

    private AircraftFactory()
    {
    }

    public static AircraftFactory   getAircraftFactory()
    {
        if (AFactory == null)
        {
            AFactory = new AircraftFactory();
        }
        return AFactory;
    }

    public Flyable    newAircraft(String p_type, String p_name, Coordinates p_coordinates)
    {
        try
        {
            if (p_type.equals("Baloon"))
            {
                id++;
                return new Baloon(id, p_name, p_coordinates);
            }
            else if (p_type.equals("Helicopter"))
            {
                id++;
                return new Helicopter(id, p_name, p_coordinates);
            }
            else if (p_type.equals("JetPlane"))
            {
                id++;
                return new JetPlane(id, p_name, p_coordinates);
            }
            else
                throw new Exception("aircraft doesn't exist");
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        
        return null;
    }
}