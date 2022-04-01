package Animal;

public class Animal_Giraffe extends Animal {
    @Override
    public String get_animal(){
        return "这是一只长颈鹿";
    }

    @Override
    public String get_number(){
        giraffe++;
        return "长颈鹿的数量:"+ giraffe;
    }
}
