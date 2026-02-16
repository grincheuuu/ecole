package models;

public abstract class Ennemis extends Coordonnes
{
    protected String    type;
    protected int     lvl = 1;
    protected int     attack;
    protected int     def;
    protected int     hitPoint;
    protected int     giveExperience;
    protected String  typeAttack;

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

    public String   getType()
    {
        return type;
    }
    public int[]     getStat()
    {
        int[]    stat = {this.attack, this.def, this.hitPoint, this.giveExperience};
        return stat;
    }
    public String    getTypeAttack()
    {
        return typeAttack;
    }
}