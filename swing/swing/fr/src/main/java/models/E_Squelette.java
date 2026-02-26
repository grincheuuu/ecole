package models;
import java.lang.Math;

class E_Squelette extends Ennemis
{
    private Observer    yeux;
    private Artefact    something = null;
    
    E_Squelette(int p_x, int p_y)
    {
        super(p_x, p_y, "squelette", 10, 0, 80, 500, "frappe");
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
        this.attack += 2;
        this.def += 1;
        this.hitPoint += 5;
        this.giveExperience = 150;
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