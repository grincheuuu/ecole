package models;

class Helm extends Artefact
{
    Helm(int p_ennemis_type)
    {
        super("Helm", p_ennemis_type);
    }

    @Override
    public void    equipArtefact(Hero p_me, int lvl)
    {
        int n = type_ennemis + lvl;
        this.me = p_me;
        me.setDef(+2 + type_ennemis + lvl);
    }

    @Override
    public void    unequipArtefact(int lvl)
    {
        int n = type_ennemis + lvl;
        me.setDef(-2 - type_ennemis - lvl);
        me = null;
    }
}