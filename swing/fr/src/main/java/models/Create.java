package models;
import  java.util.List;
import  java.util.ArrayList;

public class Create
{
    public void    doCreate()
    {
        System.out.println( "Hello World!" );
//        EnnemisFactory  EFactory = EnnemisFactory.getEnnemisFactory();
        Observer        yeux = new Observer();
//        List<Ennemis>   liste = new ArrayList<Ennemis>();
//        Ennemis         temp;
        HeroFactory     HFactory = HeroFactory.getNewHeroFactory();
        Hero            me = HFactory.newHero("Barbar", "anduin");

        yeux.register_hero(me);
        Map             map = new Map(yeux);

//        map.getObserver(yeux);
/*        temp = EFactory.newEnnemis("Troll");
        temp.registerObserver(yeux);
        liste.add(temp);
        temp = EFactory.newEnnemis("Squelette");
        temp.registerObserver(yeux);
        liste.add(temp);
        temp = EFactory.newEnnemis("Vampire");
        temp.registerObserver(yeux);
        liste.add(temp);
        temp = EFactory.newEnnemis("Hydre");
        temp.registerObserver(yeux);
        liste.add(temp);*/
    }
}