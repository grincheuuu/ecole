package fr.simulation.aircraft;
import fr.simulation.weather.Flyable;
import fr.simulation.weather.Tower;
import fr.simulation.weather.WeatherTower;

public class Baloon extends Aircraft implements Flyable
{
    private String          type = "Baloon";
    private WeatherTower    weathertower;

    public Baloon(long p_id, String p_name, Coordinates p_coordinates)
    {
        super(p_id, p_name, p_coordinates);
//        System.out.println("Baloon creation");
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