package fr.simulation.weather;
import java.io.BufferedWriter;
import java.io.FileWriter;

public interface Flyable
{
    public abstract void    updateCondition();
    public abstract void    registerTower(WeatherTower p_tower);
    public void     setB(BufferedWriter bw);
    public String   getType();
    public long     getId();
    public String   getName();
}