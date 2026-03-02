package models;
import java.lang.Math;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

class E_Troll extends Ennemis
{
    private Observer    yeux;
    private Artefact    something = null;
//    private static final Logger logger = LoggerFactory.getLogger(E_Troll.class);

    E_Troll(int p_y, int p_x)
    {
        super(p_y, p_x, "troll", 25, 0, 110, 1500, "cogne");
        int nb = (int) (Math.random() * 100);
        if (nb % 6 == 0)
            something = new Armor(2);
        else if (nb % 5 == 0)
            something = new Weapon(2);
        else if (nb % 9 == 0)
            something = new Helm(2);
//        if (something != null)
//           logger.info("{} artefact : {}", this.getType(), something.getTypeArtefact());
    }
    
    @Override
    public void      lvlUp()
    {
        this.lvl += 1;
        this.attack += 4;
        this.def += 0;
        this.hitPoint += 5;
        this.giveExperience = 200;
    }

    @Override
    public void    registerObserver(Observer p_yeux)
    {
        this.yeux = p_yeux;
        yeux.registerEnnemis(this);
    }

    @Override
    boolean         testArtefact()
    {
        if (something == null)
            return false;
//        logger.info("{} artefact : {}", this.getType(), something.getTypeArtefact());
        return true;
    }

    @Override
    Artefact    setArtefact()
    {
        return something;
    }
}