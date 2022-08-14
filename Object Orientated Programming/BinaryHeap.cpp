#include <iostream>
#include <vector>

using namespace std;

class BinaryHeap{
public:
    vector<int> data;

    int parent(int idx){
    	return (idx-1)/2;
        
    }

    int left_child(int idx){
        return (2*idx)+1;
    }

    int right_child(int idx){
        return (2*idx)+1;
    }

    int num_children(int idx){
        if(data[left_child(idx)] and data[right_child(idx)])
             return 2;
        else if(data[left_child(idx)]  ^ data[right_child(idx)])
            return 1;
        else
            return 0;
    }
    
void swap(int parentNode, int child)
	{
     int swaps = data[parentNode];
     data[parentNode] = data[child];
     data[child] = swaps;
	}


    void push(int value){
        data.push_back(value);
        int i = data.size()-1;
        while(data[parent(i)] < data[i] ){
        	int b = data[parent(i)];
        	data[parent(i)] = data[i];
        	data[i]= b;
        	i = parent(i);
		}
    }

    void pop(){
    	int i = data.size()-1;
        int max;
    	data[0] = data[i];
    	data.pop_back();
            i = 0;
            
        while(true)
		{
            max = i;
            if(num_children(i) == 2)
			{
                if(data[right_child(i)]<data[left_child(i)])
				{
                    if(data[i]< data[left_child(i)])
					{
                    swap(i, left_child(i));
                            i = left_child(i);
                    }
                }
                
                else 
				{
                    if(data[i]< data[right_child(i)])
					{
                    swap(i, right_child(i));
                    i = right_child(i);
                    }
                }

            }
            
            if(num_children(i) == 1)
			{
                if(data[left_child(i)])
				{
                    if(data[left_child(i)]> data[i])
					{
						swap(i, left_child(i));
                        i = left_child(i);
					}
                        
                }
                else
				{
                	if(data[right_child(i)])
					{
                    	if(data[right_child(i)]> data[i])
                    	{
                    		swap(i, right_child(i));
                            i = right_child(i);
						}
                        	
                	}
                }
            }
            
            if(max == i)
            {
            	break;
			}
                
        }
    }

    void print(){
        for(auto &v : data)
		{
            cout << v << " ";
        }
        cout << endl;
    }
};

int main(){
	
	BinaryHeap bh;
	string line;
	
	while(getline(cin, line) && line[0] != 'x')
	{
		if(line[0] == 'p')
		{
			bh.pop();
		}
		else
		{
			bh.push(stoi(line));
		}

		bh.print();
	}
	return 0;
}
