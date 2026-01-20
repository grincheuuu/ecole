package fr.simulation.aircraft;
import fr.simulation.weather.*;

public class WeatherProvider //singleton
{
    private static WeatherProvider  Wprovider;
    private String[]    weather = {"SNOW", "SUN", "RAIN", "FOG"};
    private int         i = 0;

    private WeatherProvider()
    {
    }

    public static WeatherProvider  getWeatherProvider()
    {
        if (Wprovider == null)
            Wprovider = new WeatherProvider();
        return Wprovider;
    }

    public String      getCurrentWeather(Coordinates p_coordinates)
    {
        int index = (p_coordinates.getLongitude() + p_coordinates.getLatitude() + p_coordinates.getHeight() + i) % 4;
        if (index < 0 || index > 100)
            index = 3;
        return weather[index];
    }

    public void     seti(int n)
    {
        i *= n;
        i += n / 2;
    }
}