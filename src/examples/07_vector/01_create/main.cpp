#include<iostream>
#include<vector>

using std::vector; using std::cout;

int main()
{
    vector<int> nums;//creates an empty vector
    cout<<"Size: "<< nums.size()<<"\n";
    cout<<"Capacity: "<<nums.capacity()<<"\n\n";

    nums.push_back(4);//add 4 to the vector(list)
    cout<<"Size: "<< nums.size()<<"\n";
    cout<<"Capacity: "<<nums.capacity()<<"\n\n";

    nums.push_back(10);//add 10 to the vector(list)
    cout<<"Size: "<< nums.size()<<"\n";
    cout<<"Capacity: "<<nums.capacity()<<"\n\n";

    nums.push_back(11);//add 11 to the vector(list)
    cout<<"Size: "<< nums.size()<<"\n";
    cout<<"Capacity: "<<nums.capacity()<<"\n\n";

    nums.push_back(5);//add 5 to the vector(list)
    cout<<"Size: "<< nums.size()<<"\n";
    cout<<"Capacity: "<<nums.capacity()<<"\n\n";

    nums.push_back(50);//add 50 to the vector(list)
    cout<<"Size: "<< nums.size()<<"\n";
    cout<<"Capacity: "<<nums.capacity()<<"\n\n";//capacity doubled

    for(auto n: nums)
    {
        cout<<n<<",";
    }

    cout<<"\n\n";

    vector<char> letters {'a', 'b', 'c', 'd', 'e', 'f'};
    cout<<"Size: "<< letters.size()<<"\n";
    cout<<"Capacity: "<<letters.capacity()<<"\n\n";


    //create vector
    vector<char> all_As(10, 'a');
    
    for(auto ch: all_As)
    {
        cout<<ch;
    }

    cout<<"\n\n";


    return 0;
}