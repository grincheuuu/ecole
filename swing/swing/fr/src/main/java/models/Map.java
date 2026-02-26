package models;
import java.util.Arrays; // pour imprimer les strings sinon impression adresse
import java.lang.Math;

public class Map
{
    private int         width = 0;
    private int         width_deux = 0;
    private int         level_hero = 1;
    private Observer    yeux = null;
/*    public enum Tile 
    {
        TERRAIN, VAMPIRE, TROLL, SQUELETTE, HYDRE, ORC, BARBAR, MAGE
    }*/
    private MapTile.Tile[][]  real_map = null;
    EnnemisFactory      EFactory = EnnemisFactory.getEnnemisFactory();

    public Map(Observer oeil)
    {
        this.width = (level_hero - 1) * 5 + 10 - (level_hero % 2);
        yeux = oeil;
        yeux.register_map(this);
        createMap();
        System.out.println();
//        createMapDeux(5);
//        System.out.println();
        ft_print_map(this.real_map);
    }

    private void    createMap()
    {
        int         center = (width / 2);
        MapTile.Tile[][]  map = new MapTile.Tile[width][width];

        for (int y = 0; y < width; y++)
        {
            for (int x = 0; x < width; x++)
            {
                map[x][y] = ft_random_monster(x, y);
                if ((x == center) && (y == center))
                {
                    String  hero = yeux.heros.getType();
                    if (hero.equals("BARBAR"))
                        map[y][x] = MapTile.Tile.BARBAR;
                    else if (hero.equals("ORC"))
                        map[y][x] = MapTile.Tile.ORC;
                    else
                        map[y][x] = MapTile.Tile.MAGE;
                }
//                System.out.print(map[i][j] + " ");
            }
//            System.out.println();
//            System.out.println(Arrays.toString(real_map[i]));
        }
        if (this.real_map == null)
            this.real_map = map;
        else
            this.real_map = ft_copie_map(real_map, map);
    }

    private MapTile.Tile[][]  ft_copie_map(MapTile.Tile[][] real_map, MapTile.Tile[][] map)
    {
        MapTile.Tile[][]      concatMap = map;
        int             old_width = (level_hero - 1 - 1) * 5 + 10 - ((level_hero - 1) % 2);
        int             width = (level_hero - 1) * 5 + 10 - (level_hero % 2);
        int             dif_width = (width - old_width) / 2;
        int             new_width_max = width - dif_width;

        System.out.println("old width " + old_width + " width " + width + " dif width " + dif_width + " new width max " + new_width_max);
        for (int y = 0; y < width; y++)
        {
            if (y >= dif_width && y < new_width_max)
            {
                for (int x = dif_width; x < new_width_max; x++)
                {
                    concatMap[y][x] = real_map[y - dif_width][x - dif_width];
                }
            }
//            System.out.println(Arrays.toString(concatMap[y]));
        }
//        System.out.println();
        return concatMap;
    }

    private MapTile.Tile    ft_random_monster(int p_x, int p_y)
    {
        int     n = (int) (Math.random() * 100);

        if (n < 50 || n % 2 == 0)
            return MapTile.Tile.TERRAIN;
        else
        {
            if (n % 3 == 0 && level_hero >= 4)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Hydre", p_x, p_y));
                return MapTile.Tile.HYDRE;
            }
            else if((n + 1) % 5 == 0 && level_hero >= 3)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Troll", p_x, p_y));
                return MapTile.Tile.TROLL;
            }
            else if(n % 5 == 0 && level_hero >= 2)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Vampire", p_x, p_y));
                return MapTile.Tile.VAMPIRE;
            }
            else
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Squelette", p_x, p_y));
                return MapTile.Tile.SQUELETTE;
            }
        }
    }

    private void  ft_print_map(MapTile.Tile[][] map)
    {
        int w = this.width;

        for (int y = 0; y < w; y++)
        {
            for (int x = 0; x < w; x++)
            {
                System.out.print(map[y][x].ordinal() + " ");
            }
            System.out.println();
        }
    }

    public void     getObserver(Observer oeil)
    {
        yeux = oeil;
        yeux.register_map(this);
    }

    public int      getWidth()
    {
        return width;
    }

    public void     map_regenerate(int level)  ///
    {
        this.level_hero = level;
        this.width = (level_hero - 1) * 5 + 10 - (level_hero % 2);
        System.out.println("map_regenerate width " + getWidth());
        createMap();
    }

    public MapTile.Tile     getMapTile(int x, int y)
    {
        return real_map[y][x];
    }

    public MapTile.Tile[][]     get_map()
    {
        return real_map;
    }

    void        setMap(int x, int y, MapTile.Tile someone)
    {
        real_map[y][x] = someone;
    }

/*
    private String[][]  ft_copie_map(String[][] real_map, String[][] map, int lvl)
    {
        String[][]      concatMap = map;
        int             old_width = (level_hero - 1) * 5 + 10 - (level_hero % 2);
        int             width = (lvl - 1) * 5 + 10 - (lvl % 2);
        int             dif_width = (width - old_width) / 2;
        int             new_width_max = width - dif_width;

        System.out.println("old width " + old_width + " width " + width + " dif width " + dif_width + " new width max " + new_width_max);
        for (int y = 0; y < width; y++)
        {
            if (y >= dif_width && y < new_width_max)
            {
                for (int x = dif_width; x < new_width_max; x++)
                {
                    concatMap[y][x] = real_map[y - dif_width][x - dif_width];
                }
            }
//            System.out.println(Arrays.toString(concatMap[y]));
        }
//        System.out.println();
        return concatMap;
    }*/

/*       private void    createMapDeux(int lvl)
    {
        int         w = (lvl - 1) * 5 + 10 - (lvl % 2);
        int     center = (w / 2);
        Tile[][]  map = new Tile[w][w];

        this.width_deux = w;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < w; j++)
            {
                map[i][j] = ft_random_monster_deux(1, 1, lvl);
                if ((i == center) && (j == center))
                {
                    String  hero = yeux.heros.getType();
                    if (hero.equals("barbar"))
                        map[i][j] = Tile.BARBAR;
                    else if (hero.equals("orc"))
                        map[i][j] = Tile.ORC;
                    else
                        map[i][j] = Tile.MAGE;
                }
//                System.out.print(map[i][j] + " ");
            }
//            System.out.println();
        }
        if (this.real_map == null)
            this.real_map = map;
        else
            this.real_map = ft_copie_map(real_map, map);
    }

    private Tile    ft_random_monster_deux(int p_x, int p_y, int lvl)
    {
        int     n = (int) (Math.random() * 100);

        if (n < 50 || n % 2 == 0)
            return Tile.TERRAIN;
        else
        {
            if (n % 3 == 0 && lvl >= 4)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Hydre", p_x, p_y));
                return Tile.HYDRE;
            }
            else if((n + 1) % 5 == 0 && lvl >= 3)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Troll", p_x, p_y));
                return Tile.TROLL;
            }
            else if(n % 5 == 0 && lvl >= 2)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Vampire", p_x, p_y));
                return Tile.VAMPIRE;
            }
            else
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Squelette", p_x, p_y));
                return Tile.SQUELETTE;
            }
        }
    }*/
}