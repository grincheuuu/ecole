package fr.simulation.aircraft;

class WeatherProvider //singleton
{
    private String[]    weather;

    private WeatherProvider()
    {
        weather = new String[4];
        weather[0] = "RAIN";
        weather[1] = "FOG";
        weather[2] = "SUN";
        weather[3] = "SNOW";
    }
    public String      getCurrentWeather(Coordinates p_coordinates)
    {
        return "fgf";
    }
}