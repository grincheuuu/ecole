package models;
import java.util.Arrays; // pour imprimer les strings sinon impression adresse
import java.lang.Math;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Map
{
    private int         width = 0;
    private int         width_deux = 0;
    private int         level_hero = 1;
    private Observer    yeux = null;
    private MapTile.Tile[][]  real_map = null;
    EnnemisFactory      EFactory = EnnemisFactory.getEnnemisFactory();
    private static final Logger logger = LoggerFactory.getLogger(Map.class);

    public Map(Observer oeil)
    {
        this.width = (level_hero - 1) * 5 + 10 - (level_hero % 2);
        yeux = oeil;
        yeux.register_map(this);
        createMap();
//        System.out.println();
    }

    private void    createMap()
    {
        int         center = (width / 2);
        MapTile.Tile[][]  map = new MapTile.Tile[width][width];

        for (int y = 0; y < width; y++)
        {
            for (int x = 0; x < width; x++)
            {
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
                else
                    map[y][x] = ft_random_monster(y, x);
//                System.out.println(map[y][x] + " ");
            }
//            System.out.println(Arrays.toString(real_map[y]));
        }
        if (this.real_map == null)
            this.real_map = map;
        else
            this.real_map = ft_copie_map(real_map, map);
//        ft_print_map(this.real_map);
    }

    private MapTile.Tile[][]  ft_copie_map(MapTile.Tile[][] real_map, MapTile.Tile[][] map)
    {
        MapTile.Tile[][]      concatMap = map;
        int             old_width = (level_hero - 1 - 1) * 5 + 10 - ((level_hero - 1) % 2);
        int             width = (level_hero - 1) * 5 + 10 - (level_hero % 2);
        int             dif_width = (width - old_width) / 2;
        int             new_width_max = width - dif_width;

        logger.info("old width {}  width {}  dif width {}  new width max {}", old_width, width, dif_width, new_width_max);
        for (int y = 0; y < width; y++)
        {
            if (y >= dif_width && y < new_width_max)
            {
                for (int x = dif_width; x < new_width_max; x++)
                {
                    concatMap[y][x] = real_map[y - dif_width][x - dif_width];
                    vilainCoordonnes(y, x, y - dif_width, x - dif_width);
                }
            }
        }
        yeux.heros.setCoordonnes(yeux.heros.getCoordonnes()[0] + dif_width, yeux.heros.getCoordonnes()[1] + dif_width);
        return concatMap;
    }

    private void        vilainCoordonnes(int y, int x, int old_y, int old_x)
    {
        if (real_map[old_y][old_x] == MapTile.Tile.HYDRE || real_map[old_y][old_x] == MapTile.Tile.TROLL
         || real_map[old_y][old_x] == MapTile.Tile.VAMPIRE || real_map[old_y][old_x] == MapTile.Tile.SQUELETTE)
        {
            Ennemis vilain = yeux.getVilain(old_y, old_x);
            vilain.setCoordonnes(y, x);
        }
    }

    private MapTile.Tile    ft_random_monster(int p_y, int p_x)
    {
        int     n = (int) (Math.random() * 100);

        if (n < 50 || n % 2 == 0)
            return MapTile.Tile.TERRAIN;
        else
        {
            if (n % 3 == 0 && level_hero >= 4)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Hydre", p_y, p_x));
                return MapTile.Tile.HYDRE;
            }
            else if((n + 1) % 5 == 0 && level_hero >= 3)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Troll", p_y, p_x));
                return MapTile.Tile.TROLL;
            }
            else if(n % 5 == 0 && level_hero >= 2)
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Vampire", p_y, p_x));
                return MapTile.Tile.VAMPIRE;
            }
            else
            {
                yeux.registerEnnemis(EFactory.newEnnemis("Squelette", p_y, p_x));
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
//        System.out.println("map_regenerate width " + getWidth());
        createMap();
    }

    public MapTile.Tile     getMapTile(int y, int x)
    {
        return real_map[y][x];
    }

    public MapTile.Tile[][]     get_map()
    {
        return real_map;
    }

    void        setMap(int y, int x, MapTile.Tile someone)
    {
        real_map[y][x] = someone;
    }
}