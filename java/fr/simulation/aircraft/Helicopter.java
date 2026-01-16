package fr.simulation.aircraft;
import fr.simulation.weather.*;

public class Helicopter extends Aircraft implements Flyable
{
    private String          type = "Helicopter";
    private WeatherTower    weathertower;

    public Helicopter(long p_id, String p_name, Coordinates p_coordinates)
    {
        super(p_id, p_name, p_coordinates);
    }

    @Override
    public void updateCondition()
    {
    }

    @Override
    public void    registerTower(WeatherTower p_tower)
    {
        this.weathertower = p_tower;
        p_tower.register(this);
    }

    public String  getType()
    {
        return type;
    }
    public long     getId()
    {
        return id;
    }
    public String   getName()
    {
        return name;
    }
}