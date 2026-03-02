package models;
import java.util.List;
import java.util.ArrayList;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Observer
{
    protected List<Ennemis>     allEnnemis = new ArrayList<Ennemis>();
    protected Map               map = null;
    protected Hero              heros = null;
    private static final Logger logger = LoggerFactory.getLogger(Observer.class);

    public void register_hero(Hero p_me)
    {
        heros = p_me;
        heros.addObserver(this);
        logger.info("Observer : new Hero register: {}", heros.getName());
    }
    public void unregister(Hero p_me)
    {
        heros = null;
    }

    public void register_map(Map p_map)
    {
        map = p_map;
        logger.info("Observer : new Map created: width : {}", map.getWidth());
    }

    public void hero_level_up()
    {
        map.map_regenerate(heros.getHeroLevel());
        EnnemisLvlUp();
    }

    public void registerEnnemis(Ennemis p_vilain)
    {
        allEnnemis.add(p_vilain);
        logger.info("Observer : new Ennemis register: {}", p_vilain.getType());
    }

    public void unregister(Ennemis p_vilain)
    {
        allEnnemis.remove(p_vilain);
        logger.info("Observer : destroy Ennemis unregister: {}", p_vilain.getType());
    }

    public void     EnnemisLvlUp()
    {
        for (Ennemis vilain: allEnnemis)
        {
            vilain.lvlUp();
        }
    }

    public Ennemis      getVilain(int y, int x)
    {
        for (Ennemis vilain: allEnnemis)
        {
            if (vilain.getCoordonnes()[0] == y && vilain.getCoordonnes()[1] == x)
                return vilain;
        }
        return null;
    }
}