package models;

public abstract class Artefact
{
    protected String  type;
    protected int     type_ennemis; // 1 = squellete 2 = vampire 3 = troll 4 = hydre
    protected Hero    me = null;

    public Artefact(String p_type, int p_ennemis_type)
    {
        this.type = p_type;
        this.type_ennemis = p_ennemis_type;
    }

    public abstract void    equipArtefact(Hero p_me, int lvl);
    public abstract void    unequipArtefact(int lvl);

    public String   getTypeArtefact()
    {
        return type;
    }
}