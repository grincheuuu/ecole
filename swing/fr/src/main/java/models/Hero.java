package models;

class Hero extends Coordonnes
{
    private String  name;
    private String  type;
    private int     level = 1;
    private int     experience = 0;
    private int     attack;
    private int     defense;
    private int     hitPoint;
    protected String        type_attack = null;
    private Artefact        something = null;


    public Hero(String p_name, String p_type, int p_attack, int p_def, int p_hitPoint, String p_type_attack)
    {
        super(4, 4);
        this.name = p_name;
        this.type = p_type;
        this.attack = p_attack;
        this.defense = p_def;
        this.hitPoint = p_hitPoint;
        this.type_attack = p_type_attack;
    }

    public String       getName()
    {
        return this.name;
    }

    public int          getHeroLevel()
    {
        return this.level;
    }

    public String          getType()
    {
        return this.type;
    }

    public int    receved_attack(int ennemis_attack)
    {
        this.hitPoint -= (ennemis_attack - defense);
        if (hitPoint <= 0)
            return (1);
        return (0);
    }
    public void     setAttack(int n)
    {
        this.attack += n;
    }
    public void     setDef(int n)
    {
        this.defense += n;
    }
    public void     addArtefact(Artefact p_something)
    {
        something = p_something;
        something.equipArtefact(this, level);
    }
}