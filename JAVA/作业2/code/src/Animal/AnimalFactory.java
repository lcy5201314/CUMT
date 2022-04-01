package Animal;

public class AnimalFactory {
    public static Animal get_name(int index){
        Animal animal = null;
        if(index == 1){
            animal = new Animal_Bear();
        }
        else if(index == 2){
            animal = new Animal_Lion();
        }
        else if(index == 3){
            animal = new Animal_Tiger();
        }
        else if(index == 4){
            animal = new Animal_Monkey();
        }
        else if(index == 5){
            animal = new Animal_Giraffe();
        }
        return animal;
    }
}
