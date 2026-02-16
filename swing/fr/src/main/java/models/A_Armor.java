package models;

class Armor extends Artefact
{
    Armor(int p_ennemis_type)
    {
        super("Armor", p_ennemis_type);
    }

    @Override
    public void    equipArtefact(Hero p_me, int lvl)
    {
        int     n;
        this.me = p_me;
        n = lvl * type_ennemis;
        me.setDef(n);
    }

    @Override
    public void    unequipArtefact(int lvl)
    {
        int     n;
        n = lvl * type_ennemis;
        me.setDef(-n);
        me = null;
    }
}