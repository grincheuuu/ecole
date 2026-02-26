package models;
import  java.util.List;
import  java.util.ArrayList;

public class Create
{
        private Observer        yeux;
        private HeroFactory     HFactory = HeroFactory.getNewHeroFactory();
        private Hero            me;
        private Map             map;
        private MajGame         majGame = null;

        public  Create()
        {
        }

        public void    doCreate()
        {
                System.out.println( "Hello World!" );
                this.yeux = new Observer();
                this.me = HFactory.newHero("BARBAR", "anduin");
                yeux.register_hero(me);
                this.map = new Map(yeux);
        }

        public void     registerMg(MajGame p_mg)
        {
                this.majGame = p_mg;
                majGame.MajGameRegister(yeux);
        }

        public MapTile.Tile[][]     getMap()
        {
                return map.get_map();
        }

        public int      getWidth()
        {
                return map.getWidth();
        }
}