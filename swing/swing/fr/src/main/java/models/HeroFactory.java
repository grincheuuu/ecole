package models;

public class HeroFactory
{
    private static HeroFactory     heroF;

    private HeroFactory()
    {
    }

    public static HeroFactory  getNewHeroFactory()
    {
        if (heroF == null)
        {
            heroF = new HeroFactory();
        }
        return heroF;
    }

    public Hero     newHero(String p_name, String hero_name)
    {
        switch (p_name)
        {
            case "ORC":
                return new H_Orc(hero_name);
            case "MAGE":
                return new H_Mage(hero_name);
            case "BARBAR":
                return new H_Barbar(hero_name);
            default:
                System.out.println("Bad Hero name danger");
        }
        return null;
    }
}