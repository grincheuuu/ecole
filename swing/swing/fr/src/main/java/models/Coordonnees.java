package models;

class Coordonnes
{
    protected int x = 0;
    protected int y = 0;

    Coordonnes(int p_y, int p_x)
    {
        this.x = p_x;
        this.y = p_y;
//        System.out.println("Coordonnes : " + this.x + " " + this.y);
    }

    public int[]    getCoordonnes()
    {
        int[]   tab = {this.y, this.x};

        return tab;
    }
    public void     setCoordonnes(int p_y, int p_x)
    {
        this.x = p_x;
        this.y = p_y;
    }
    public void     changeCoordonnes(int p_y, int p_x)
    {
        this.x += p_x;
        this.y += p_y;
    }
}