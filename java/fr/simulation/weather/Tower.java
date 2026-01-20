package fr.simulation.weather;
import java.util.List;
import java.util.ArrayList;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;

public class Tower
{
    protected List<Flyable> observers = new ArrayList<Flyable>();
    public BufferedWriter          b;

    public void    register(Flyable p_flyable)
    {
        observers.add(p_flyable);
        try
        {
            b.write("Tower says: ");
            b.write(p_flyable.getType());
            b.write("#");
            b.write(p_flyable.getName());
            b.write("(");
            String  id = Long.toString(p_flyable.getId());
            b.write(id);
            b.write(") registered to weather tower.");
            b.newLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
//        System.out.println("Tower says: " + p_flyable.getType() + "#" + p_flyable.getName()
//         + "(" + p_flyable.getId() + ")" + " registered to weather tower.");
    }
    public void    unregister(Flyable p_flyable)
    {
        observers.remove(p_flyable);
        try
        {
            b.write("Tower says: ");
            b.write(p_flyable.getType());
            b.write("#");
            b.write(p_flyable.getName());
            b.write("(");
            String  id = Long.toString(p_flyable.getId());
            b.write(id);
            b.write(") unregistered from weather tower.");
            b.newLine();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
//        System.out.println("Tower says: " + p_flyable.getType() + "#" + p_flyable.getName()
//         + "(" + p_flyable.getId() + ")" + " unregistered from weather tower.");
    }
    public void    conditionChanged()
    {
        List<Flyable>   temp = new ArrayList<Flyable>(observers);
        for (Flyable fly: temp)
        {
            fly.updateCondition();
        }
    }
    
    public void setB(BufferedWriter bw)
    {
        b = bw;
    }
}