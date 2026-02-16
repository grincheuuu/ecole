package models;

class Coordonnes
{
    protected int x = 0;
    protected int y = 0;

    Coordonnes(int p_x, int p_y)
    {
        this.x = p_x;
        this.y = p_y;
//        System.out.println("Coordonnes : " + this.x + " " + this.y);
    }

    public int[]    getCoordonnes()
    {
        int[]   tab = {this.x, this.y};

        return tab;
    }
    public void     setCoordonnes(int p_x, int p_y)
    {
        this.x = p_x;
        this.y = p_y;
    }
}