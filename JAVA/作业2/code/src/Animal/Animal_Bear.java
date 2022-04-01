package Animal;

public class Animal_Bear extends Animal{
    @Override
    public String get_animal(){
        return "这是一只熊";
    }

    @Override
    public String get_number(){
        bear++;
        return "熊的数量:"+ bear;
    }
}
