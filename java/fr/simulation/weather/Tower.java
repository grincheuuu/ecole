package fr.simulation.weather;
import java.util.List;
import java.util.ArrayList;

public class Tower
{
    protected List<Flyable> observers = new ArrayList<Flyable>();

    public void    register(Flyable p_flyable)
    {
        observers.add(p_flyable);
        System.out.println("Tower says: " + p_flyable.getType() + "#" + p_flyable.getName()
         + "(" + p_flyable.getId() + ")" + " registered to weather tower.");
    }
    public void    unregister(Flyable p_flyable)
    {
        observers.remove(p_flyable);
        System.out.println("Tower says: " + p_flyable.getType() + "#" + p_flyable.getName()
         + "(" + p_flyable.getId() + ")" + " unregistered from weather tower.");
    }
    public void    conditionChanged()
    {
/**        for (Flyable fly: observers)
        {
            System.out.println(Flyable->p_name);
//            Flyable->p_coordinates;
        }*/
    }
}