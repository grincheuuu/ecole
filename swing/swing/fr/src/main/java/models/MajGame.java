package models;

public class MajGame
{
    Observer    yeux = null;
    private Artefact    objet = null;
    
    public MajGame()
    {}

    public String   move(String ing)
    {
        int[]   old_coordonnes = yeux.heros.getCoordonnes();

        if (ing.equals("w"))
        {
            yeux.heros.changeCoordonnes(0, -1);
        }
        if (ing.equals("a"))
        {
            yeux.heros.changeCoordonnes(-1, 0);            
        }
        if (ing.equals("d"))
        {
            yeux.heros.changeCoordonnes(1, 0);
        }
        if (ing.equals("s"))
        {
            yeux.heros.changeCoordonnes(0, 1);            
        }
        if (testCoordonnees() == 1)
            return "win";
        if (maybeFight() == 1)
            return "loose";
        if (maybeFight() == 2)
            return "choose artefact";
        modifMap(old_coordonnes);
        return "game_continue";
    }

    public void         artefactSelection(int i)
    {
        if (i == 0)
        {
            if (this.objet == null)
            {
                System.out.println("artefact == null");
//                modifMap(old_coordonnes);
                return;
            }
            yeux.heros.addArtefact(this.objet);
        }
//        modifMap(old_coordonnes);
    }

    public void            MajGameRegister(Observer p_oeil)
    {
        this.yeux = p_oeil;
    }

    private int     testCoordonnees()
    {
//        System.out.println("TestCoordonnees");
        if (yeux.heros.getCoordonnes()[0] < 0 || yeux.heros.getCoordonnes()[1] < 0)
            return 1;
        if (yeux.heros.getCoordonnes()[0] >= yeux.map.getWidth() || yeux.heros.getCoordonnes()[1] >= yeux.map.getWidth())
            return 1;
        return 0;
    }

    private int maybeFight()
    {
//        System.out.println("Maybe fight");
        MapTile.Tile monster = yeux.map.getMapTile(
            yeux.heros.getCoordonnes()[0],
            yeux.heros.getCoordonnes()[1]
        );

        if (monster == MapTile.Tile.TERRAIN)
        {
//            System.out.println("terrain");
            return 0;
        }
        return Fight(yeux.heros.getCoordonnes()[0], yeux.heros.getCoordonnes()[1]);
    }

    private int    Fight(int x, int y)
    {
        Ennemis     vilain = yeux.getVilain(x, y);

//        System.out.println("Fight");
        System.out.println(vilain.getType());
        while (yeux.heros.getHitoint() > 0 && vilain.getHitoint() > 0)
        {
            vilain.heroAttackVilain(yeux.heros.getAttack());
            if (vilain.getHitoint() <= 0)
            {
                if (yeux.heros.heroLvlUp(vilain.getGiveExperience()) == true)
                {
                    System.out.println("heros lvl up");
                }
                if (vilain.testArtefact() == true)
                {
                    this.objet = vilain.setArtefact();
                    artefactSelection(0);
//                    return 2;
                }
                return 0;
            }
            yeux.heros.vilainAttackHero(vilain.getAttack());
            if (yeux.heros.getHitoint() <= 0)
                return 1;
        }
        return 0;
    }

    private void     modifMap(int[] old_coordonnes)
    {
        yeux.map.setMap(old_coordonnes[0], old_coordonnes[1], MapTile.Tile.TERRAIN);
        if (yeux.heros.getType().equals("BARBAR"))
            yeux.map.setMap(yeux.heros.getCoordonnes()[0], yeux.heros.getCoordonnes()[1], MapTile.Tile.BARBAR);
        else if (yeux.heros.getType().equals("MAGE"))
            yeux.map.setMap(yeux.heros.getCoordonnes()[0], yeux.heros.getCoordonnes()[1], MapTile.Tile.MAGE);
        else
            yeux.map.setMap(yeux.heros.getCoordonnes()[0], yeux.heros.getCoordonnes()[1], MapTile.Tile.ORC);
    }
}