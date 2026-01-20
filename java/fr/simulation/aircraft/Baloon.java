package fr.simulation.aircraft;
import fr.simulation.weather.Flyable;
import fr.simulation.weather.Tower;
import fr.simulation.weather.WeatherTower;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Baloon extends Aircraft implements Flyable
{
    private String          type = "Baloon";
    private WeatherTower    weathertower;
    private String          condition = "unknow";
    BufferedWriter          b;

    public Baloon(long p_id, String p_name, Coordinates p_coordinates)
    {
        super(p_id, p_name, p_coordinates);
    }
    @Override
    public void updateCondition()
    {
        condition = weathertower.getWeather(this.coordinates);
        weathertower.changeWeather();
        switch(condition)
        {
            case "unknow":
            {
                condition = "SUN";
                this.coordinates.setLongitude(2);
                this.coordinates.setHeight(4);
                try{
                    says();
                    b.write("): Let's enjoy the good weather and take some pics.");
                    b.newLine();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            }
            case "SUN":
            {
                condition = "SUN";
                this.coordinates.setLongitude(2);
                this.coordinates.setHeight(4);
                try{
                    says();
                    b.write("): Let's enjoy the good weather and take some pics.");
                    b.newLine();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            }
            case "RAIN":
            {
                condition = "RAIN";
                this.coordinates.setHeight(-5);
                try{
                    says();
                    b.write("): It's raining. Better watch out for lightings.");
                    b.newLine();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            }
            case "FOG":
            {
                condition = "FOG";
                this.coordinates.setHeight(-3);
                try{
                    says();
                    b.write("): This is hot.");
                    b.newLine();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            }
            case "SNOW":
            {
                condition = "SNOW";
                this.coordinates.setHeight(-15);
                try{
                    says();
                    b.write("): My rotor is going to freeze!");
                    b.newLine();
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
                break;
            }
            default:
                break; 
        }
        landing();
    }

    private void    landing()
    {
        if (this.coordinates.getHeight() <= 0)
        {
            says();
            try
            {
                b.write(") landing.");
                b.newLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
//            System.out.println(this.getType() + "#" + this.getName() + "(" + this.getId() + ") landing.");
            weathertower.unregister(this);
        }
    }

    @Override
    public void    registerTower(WeatherTower p_tower)
    {
        this.weathertower = p_tower;
        p_tower.register(this);
    }

    private void    says()
    {
        try
        {
            b.write(this.type);
            b.write("#");
            b.write(this.name);
            b.write("(");
            String  id = Long.toString(this.id);
            b.write(id);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void     setB(BufferedWriter bw)
    {
        b = bw;
    }

    public String  getType()
    {
        return type;
    }
    public long     getId()
    {
        return id;
    }
    public String   getName()
    {
        return name;
    }
}

/**
 *     @Override
    public void updateCondition()
    {
        condition = weathertower.getWeather(this.coordinates);
        weathertower.changeWeather();
        switch(condition)
        {
            case "unknow":
            {
                condition = "SUN";
                this.coordinates.setLongitude(2);
                this.coordinates.setHeight(4);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): Let's enjoy the good weather and take some pics.");
                break;
            }
            case "SUN":
            {
                condition = "RAIN";
                this.coordinates.setHeight(-5);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): It's raining. Better watch out for lightings.");
                break;
            }
            case "RAIN":
            {
                condition = "FOG";
                this.coordinates.setHeight(-3);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): This is hot.");
                break;
            }
            case "FOG":
            {
                condition = "SNOW";
                this.coordinates.setHeight(-15);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): My rotor is going to freeze!");
                break;
            }
            case "SNOW":
            {
                condition = "SUN";
                this.coordinates.setLongitude(2);
                this.coordinates.setHeight(4);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): Let's enjoy the good weather and take some pics.");
                break;
            }
            default:
                break; 
        }
        landing();
    }
 */

/**
    @Override
    public void updateCondition()
    {
        condition = weathertower.getWeather(this.coordinates);
        weathertower.changeWeather();
        switch(condition)
        {
            case "unknow":
            {
                condition = "SUN";
                this.coordinates.setLongitude(2);
                this.coordinates.setHeight(4);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): Let's enjoy the good weather and take some pics.");
                break;
            }
            case "SUN":
            {
                condition = "SUN";
                this.coordinates.setLongitude(2);
                this.coordinates.setHeight(4);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): Let's enjoy the good weather and take some pics.");
                break;
            }
            case "RAIN":
            {
                condition = "RAIN";
                this.coordinates.setHeight(-5);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): It's raining. Better watch out for lightings.");
                break;
            }
            case "FOG":
            {
                condition = "FOG";
                this.coordinates.setHeight(-3);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): This is hot.");
                break;
            }
            case "SNOW":
            {
                condition = "SNOW";
                this.coordinates.setHeight(-15);
                System.out.println(this.type + "#" + this.name + "(" + this.id
                 + "): My rotor is going to freeze!");
                break;
            }
            default:
                break; 
        }
        landing();
    }*/