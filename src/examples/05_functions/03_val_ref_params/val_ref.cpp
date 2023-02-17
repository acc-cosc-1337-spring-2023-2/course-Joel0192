void val_ref_params(int num, int &num1, const int &num2)
{
    num = 20;
    num1 = 20;
    //num2 = 20; can't modify it; build error

}