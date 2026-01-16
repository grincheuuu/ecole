package fr.simulation.weather;

public interface Flyable
{
    public abstract void    updateCondition();
    public abstract void    registerTower(WeatherTower p_tower);
    String          getType();
    public long     getId();
    public String   getName();
}