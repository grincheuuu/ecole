package models;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

class Hero extends Coordonnes
{
    private String  name;
    private String  type;
    private int     level = 1;
    private int     experience = 0;
    private int     lvlExperienceUp;
    private int     attack;
    private int     defense;
    private int     hitPoint;
    protected String        type_attack = null;
    private Artefact        something = null;
    private static final Logger logger = LoggerFactory.getLogger(Hero.class);


    public Hero(String p_name, String p_type, int p_attack, int p_def, int p_hitPoint, String p_type_attack)
    {
        super(4, 4);
        this.name = p_name;
        this.type = p_type;
        this.attack = p_attack;
        this.defense = p_def;
        this.hitPoint = p_hitPoint;
        this.type_attack = p_type_attack;
        this.lvlExperienceUp = calculLvlExperienceUp(1);
        logger.debug("hero lvl xp : {}", this.lvlExperienceUp);
    }

    private int         calculLvlExperienceUp(int lvl)
    {
        return (lvl * 1000 + (lvl - 1) * (lvl - 1) * 450);
    }

    public String       getName()
    {
        return this.name;
    }

    public String       getType()
    {
        return this.type;
    }

    public String       getType_attack()
    {
        return this.type_attack;
    }

    public int          getAttack()
    {
        return this.attack;
    }

    public int          getDefense()
    {
        return this.defense;
    }

    public int          getHitoint()
    {
        return this.hitPoint;
    }

    public int          getHeroLevel()
    {
        return this.level;
    }

    public void     setAttack(int n)
    {
        this.attack += n;
    }
    public void     setDef(int n)
    {
        this.defense += n;
    }
    void     addArtefact(Artefact p_something)
    {
        logger.debug("attack = {}  def =  {}", this.attack, this.defense);
        something = p_something;
        something.equipArtefact(this, level);
        logger.debug("  attack = {}  def =  {}", this.attack, this.defense);
    }

    boolean    heroLvlUp(int xp)
    {
        this.experience += xp;
        if (this.experience >= this.lvlExperienceUp)
        {
            this.level += 1;
            this.lvlExperienceUp = calculLvlExperienceUp(this.level);
            logger.debug("hero lvl up :{}", this.lvlExperienceUp);
            return true;
        }
        return false;
    }

    void    vilainAttackHero(int degats)
    {
        logger.debug("vilain attack hit point = {}", this.hitPoint);
        if (this.defense <= degats)
            this.hitPoint += this.defense - degats;
        logger.debug(" vilain attack hit point = {}", this.hitPoint);
        logger.debug("Debug message");
    }

}