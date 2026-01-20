package fr.simulation.weather;
import fr.simulation.aircraft.Coordinates;
import fr.simulation.aircraft.*;

public class WeatherTower extends Tower
{
    private static WeatherProvider     wprovider = WeatherProvider.getWeatherProvider();

    public String  getWeather(Coordinates p_coordinates)
    {
        return wprovider.getCurrentWeather(p_coordinates);
    }

    public void    changeWeather()
    {
        wprovider.seti(2);
    }

}