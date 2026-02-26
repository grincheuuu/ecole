package models;

class Weapon extends Artefact
{
    Weapon(int p_ennemis_type)
    {
        super("Weapon", p_ennemis_type);
    }

    @Override
    public void    equipArtefact(Hero p_me, int lvl)
    {
        int n;
        this.me = p_me;
        n = (type_ennemis + 1) * lvl;
        me.setAttack(n);
    }
    
    @Override
    public void    unequipArtefact(int lvl)
    {
        int n;
        n = (type_ennemis + 1) * lvl;
        me.setAttack(-n);
        me = null;
    }
}