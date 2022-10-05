#include "TesterInterface.h"

TesterInterface::TesterInterface(int maxNumTests)
{
   // this->maxNumTesters = maxNumTesters;

    //testers = new NumberTester *[maxNumTesters];
    //for(int x = 0 ; x < maxNumTesters ; x++)
    //{
    //    testers[x] = NULL;
    //}
    currNumTesters = 0 ;

    if (maxNumTests < 1)
    {
        this->testers = new NumberTester*[0];
        this->maxNumTesters = 0 ;
    }
    else
    {
        this->maxNumTesters = maxNumTests;

    testers = new NumberTester *[maxNumTesters];
    for(int x = 0 ; x < maxNumTesters ; x++)
    {
        
        this->testers[x] = NULL;
    }

    }
}
TesterInterface::TesterInterface(TesterInterface * other)
{
    // std::cout<<"Here"<<std::endl;
   
    if(other == NULL)
    {
        maxNumTesters = 0 ;
        currNumTesters = 0 ;
        
        testers=  new NumberTester*[0];
        

    }
    else
    {
        maxNumTesters = other->maxNumTesters ;
        currNumTesters = other->currNumTesters ;

        testers=  new NumberTester*[maxNumTesters];
        for(int x = 0 ; x < maxNumTesters ; x++)
            {
                if(other->testers[x]!=NULL){
                    testers[x] = other->testers[x]->clone();

                }
                else{
                    testers[x] = NULL;
                }
            }

    }

}
TesterInterface::TesterInterface(TesterInterface & other)
{
    maxNumTesters = other.maxNumTesters ;
    currNumTesters = other.currNumTesters ;
     testers=  new NumberTester*[maxNumTesters];
        for(int x = 0 ; x < maxNumTesters ; x++)
        {
            {
                if(other.testers[x]!=NULL){
                    testers[x] = other.testers[x]->clone();

                }
                else{
                    testers[x] = NULL;
                }
            }
        }


}

TesterInterface::~TesterInterface()
{
    if(testers != NULL){
    for(int x = 0 ; x < maxNumTesters ; x++)
    {
        delete testers[x];
        testers[x] = NULL ;

    }
    delete [] testers ;
    testers = NULL ;

    }
}

int TesterInterface::addTester(NumberTester * tester)
{
    if(tester == NULL || this->currNumTesters == this->maxNumTesters)
    {
        return -1 ;
    }
    else 
    {
        for(int x  = 0 ; x < maxNumTesters ; x++)
        {
            if(testers[x] == NULL)
            {
                testers[x] = tester->clone();
                currNumTesters++ ;
                return x ; 
            }
            
        }
       
    }   
    return -1 ;
}

bool TesterInterface::removeTester(int pos)
{
    if(pos < 0 || pos >= maxNumTesters)
    {
        return false ;
    }
    if(testers[pos]==NULL)
    {
        return false ;
    }
    else 
    {
        delete testers[pos];
        testers[pos] = NULL; 
        currNumTesters-- ;
        return true ; 
    }
}

bool TesterInterface::evaluate(int num)
{
    int count = 0 ; 
    if((testers == NULL) || (getCurrNumTesters() == 0))
    {
        return false ;
    }
    else 
    {
        for(int x  = 0 ; x < getMaxNumTesters() ; x++)
        {
           // testers[x]=evaluate(num) ;
           if(testers[x] != NULL){
                if(testers[x]->evaluate(num) == true)
                 {
                   count++ ;
                 }
           }
            
        }

    }
    if(count == currNumTesters)
    {
        return true ;
    }
    else 
    {
        return false ;
    }
   
    
}

int * TesterInterface::failedTests(int num)
{ 
    int index = 0; 
    int T = numberOfFailedTests(num);
   
   /* for(int x = 0 ; x < maxNumTesters ; x++)
    {
        if(testers[x]->evaluate(num) == false)
        {
            index++;
        }
        else 
        {
            T++ ;
        }
    }*/

    int * array = new int[T];
    if(T == 0 || testers == NULL)
    {
        return array  ;
    }
    else 
    {
        for(int x = 0 ; x < getMaxNumTesters() ; x++)
        {
            if(testers[x] != NULL)
            {
                if(testers[x]->evaluate(num)==false)
                {
                    array[index++]= x;
                }
            }
        }
        return array;
    }
    
}

int TesterInterface::numberOfFailedTests(int num)
{


    if(testers == NULL )
    {
        return 0 ;
    }  
    if(currNumTesters <= 0 ) return 0;

    int index = 0; 
    int T = 0;
   
    for(int x = 0 ; x < getMaxNumTesters() ; x++)
    {
        if(!(testers[x] == NULL))
        {
        if(testers[x]->evaluate(num) == false)
        {
            index++;
        }
        else 
        {
            T++ ;
        }

        }
    }

        return index ;




}

NumberTester * TesterInterface::operator[](int pos)
{
    if(pos >= 0 && pos < maxNumTesters)
    {
        return testers[pos];
    }
    else 
    {
        return NULL ;
    }


}

int TesterInterface::getCurrNumTesters() const
{
    return currNumTesters ;
}

int TesterInterface::getMaxNumTesters() const
{
    return maxNumTesters ;
}
