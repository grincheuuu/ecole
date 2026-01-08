package fr.simulation.weather;

class Tower
{
    List<Flyable *> observers;

    void    register(Flyable* p_flyable);
    void    unregister(Flyable* p_flyable);

    void    conditionChanged();
}