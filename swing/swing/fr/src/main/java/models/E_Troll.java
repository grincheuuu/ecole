package models;
import java.lang.Math;

class E_Troll extends Ennemis
{
    private Observer    yeux;
    private Artefact    something = null;

    E_Troll(int p_x, int p_y)
    {
        super(p_x, p_y, "troll", 25, 0, 110, 800, "cogne");
        int nb = (int) (Math.random() * 100);
        if (nb % 6 == 0)
            something = new Armor(2);
        else if (nb % 5 == 0)
            something = new Weapon(2);
        else if (nb % 9 == 0)
            something = new Helm(2);
        if (something != null)
            System.out.println(this.getType() + " artefact : " + something.getTypeArtefact());
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
        System.out.println(" artefact : " + something.getTypeArtefact());
        return true;
    }

    @Override
    Artefact    setArtefact()
    {
        return something;
    }
}