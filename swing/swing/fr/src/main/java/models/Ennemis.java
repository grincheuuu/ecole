package models;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public abstract class Ennemis extends Coordonnes
{
    protected String    type;
    protected int     lvl = 1;
    protected int     attack;
    protected int     def;
    protected int     hitPoint;
    protected int     giveExperience;
    protected String  typeAttack;
    private static final Logger logger = LoggerFactory.getLogger(Ennemis.class);

    protected Ennemis (int p_x, int p_y, String p_type, int p_attack, int p_def, int p_hitpoint, int p_xp, String p_typeAttack)
    {
        super(p_x, p_y);
        this.type = p_type;
        this.attack = p_attack;
        this.def = p_def;
        this.hitPoint = p_hitpoint;
        this.giveExperience = p_xp;
        this.typeAttack = p_typeAttack;
    }

    public abstract void        lvlUp();
    public abstract void        registerObserver(Observer yeux);
    abstract boolean            testArtefact();
    abstract Artefact           setArtefact();

    public String   getType()
    {
        return type;
    }
    public int     getGiveExperience()
    {
        return this.giveExperience;
    }

    public String       getType_attack()
    {
        return this.typeAttack;
    }

    public int          getAttack()
    {
        return this.attack;
    }

    public int          getDefense()
    {
        return this.def;
    }

    public int          getHitoint()
    {
        return this.hitPoint;
    }

    void        heroAttackVilain(int degats)
    {
        logger.debug("vilain attack hit point = {}", this.hitPoint);
        if (this.def <= degats)
            this.hitPoint += this.def - degats;
        logger.debug(" vilain attack hit point = {}", this.hitPoint);
    }
}