package calculator;

public class AWrongException extends Exception{
    public AWrongException(){}
    public AWrongException(String err){
        super(err);
    }
}
