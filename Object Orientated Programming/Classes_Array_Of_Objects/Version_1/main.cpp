#include "dog.h"

void swapNames( Dog& first, Dog& second);
int main2(Dog* array[]);
int exists_in_array(Dog* array[], string n);
void print(Dog* array[]);

// Main Funtion
int main(int argc, char *argv[], char *envp[])
{
    const int sizearray = 10;
    Dog** Dogs = new Dog*[sizearray];
    for(int counterVariable1 = main2(Dogs);counterVariable1<10;counterVariable1 = counterVariable1 + main2(Dogs) + 1){
        Dogs[counterVariable1] = NULL;
        // cout<<"We here: "<<counterVariable1<<endl;
    }
    int temp_option;
    int age_String, counterVariable2;
    temp_option = age_String = counterVariable2 = main2(Dogs);

    while(temp_option!=3)
    {

        string name_String{};
        string dogOwner_String,DogOwner_String,address_String;
        name_String = dogOwner_String = DogOwner_String = address_String = "";

        cout<<"Enter 1 to add a dog, 2 to swap names or 3 to stop: ";
        cin>>temp_option;
        if(temp_option!=3)
        {
            if(temp_option == 2)
            {
                string firsttoswap = "",secondtoswap = "";
                cout<<"Enter name of first dog: ";
                cin>>firsttoswap;

                cout<<"Enter name of second dog: ";
                cin>>secondtoswap;

                if(exists_in_array(Dogs,firsttoswap)>=0 && exists_in_array(Dogs,firsttoswap)<10 && exists_in_array(Dogs,firsttoswap)!=-1 && exists_in_array(Dogs,secondtoswap)!=-1)
                {
                    swapNames(*Dogs[exists_in_array(Dogs,firsttoswap)],*Dogs[exists_in_array(Dogs,secondtoswap)]);
                    print(Dogs);
                }
                else if(exists_in_array(Dogs,firsttoswap)==11){
                    swapNames(*Dogs[0],*Dogs[1]);
                    print(Dogs);
                }
                else cout<<"No dog found"<<endl;
            }
            else if(temp_option == 1)
            {
                cout<<"Please enter the name of the dog: ";
                cin>>name_String;

                cout<<"Please enter the age: ";
                cin>>age_String;

                cout<<"Does the dog have an owner: ";
                cin>>dogOwner_String;

                if(dogOwner_String=="Yes")
                {
                    cout<<"Please enter the owners name: ";
                    cin>>DogOwner_String;

                    cout<<"Please enter the address: ";
                    cin>>address_String;
                }
                else{ /*Do Nothing*/ }
                Dog *TempDog = new Dog();
                TempDog->setName(name_String);
                TempDog->setAge(age_String);
                Citizen ownerVar;
                if(dogOwner_String=="Yes")
                {
                    // Entering the dog's owner
                    ownerVar.setName(DogOwner_String);
                    ownerVar.setAddress(address_String);
                }
                else
                {
                    // hoping for adoption
                    ownerVar.setName("hoping for adoption");
                    ownerVar.setAddress("");
                }
                TempDog->setCitizen(&ownerVar);
                // Initializing the array
                Dogs[counterVariable2] = TempDog;
                counterVariable2 = counterVariable2 + 1;

                print(Dogs);
            }
            else{ continue; }
        }
        else{ continue; }
    }
    return 0;
}

// Helper Functions
void swapNames( Dog& first, Dog& second)
{
    string nameFirstToSwap = first.getName(), nameSecondToSwap = second.getName();
    first.setName(nameSecondToSwap);
    second.setName(nameFirstToSwap);
}

void print(Dog* array[])
{
    string print = "The list of dogs are as follows: ",finalString = "";
    for(int counterVariable1 = main2(array); counterVariable1<10 && array[counterVariable1]!=NULL; counterVariable1 = counterVariable1 + main2(array)+ 1)
    {
        string tempPrint = array[counterVariable1]->getCitizen()->getName();
        print+=array[counterVariable1]->getName();
        print+="(Owner: "+tempPrint+"), ";
    }
    finalString = print.substr(0, print.length()-2);
    cout<<finalString<<endl;
}

int main2(Dog* array[])
{
    Dog *TempDog = new Dog();
    TempDog->setName("Parastratiosphecomyiabull");
    TempDog->setAge(5);
    Citizen ownerVar;
    if(TempDog->getName()!="")
    {
        // hoping for adoption
        ownerVar.setName("hoping for adoption");
        ownerVar.setAddress("Brooklyn");
    }
    TempDog->setCitizen(&ownerVar);
    if(TempDog->getName()!="")
    {
        return 0;
    }
    return -1;
}

int exists_in_array(Dog* array[], string n)
{
    for(int counterVariable1 = main2(array);counterVariable1<10,(array[counterVariable1]!=NULL);counterVariable1 = counterVariable1 + 1)
    {
        if(array[counterVariable1]->getName()==n)return counterVariable1;
        else{ continue; }
    }
    return -1;
} 