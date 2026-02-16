package models;
import java.util.List;
import java.util.ArrayList;

public class Observer
{
    protected List<Ennemis>     allEnnemis = new ArrayList<Ennemis>();
    protected Map               map = null;
    protected Hero              heros = null;

    public void register_hero(Hero p_me)
    {
        heros = p_me;
        System.out.println("Observer : new Hero register: " + heros.getName());
    }
    public void unregister(Hero p_me)
    {
        heros = null;
    }

    public void register_map(Map p_map)
    {
        map = p_map;
        System.out.println("Observer : new Map created: width : " + map.getWidth());
    }

    public void herolLevelUp()
    {
        map.map_regenerate(heros.getHeroLevel());
    }

    public void registerEnnemis(Ennemis p_vilain)
    {
        allEnnemis.add(p_vilain);
        System.out.println("Observer : new Ennemis register: " + p_vilain.getType());
    }

    public void unregister(Ennemis p_vilain)
    {
        allEnnemis.remove(p_vilain);
        System.out.println("Observer : destroy Ennemis unregister: " + p_vilain.getType());
    }

    public void     EnnemisLvlUp()
    {
        for (Ennemis vilain: allEnnemis)
        {
            vilain.lvlUp();
        }
    }
}