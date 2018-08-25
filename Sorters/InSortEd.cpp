#include<iostream>
#include<ctime>
#include<chrono>
#define size 10
using namespace std;
const int len=size;

class BaseSorter{
    //Got into git
    protected:
        int len;
        int arr[size];
        int copy[size];
        double duration;
    public:
        virtual void sortIt(){};
        int* Sorted(){
            return arr;
        }
       
        int* unSorted(){
            return copy;
        }
        double burst(){
            return duration;
        }
    
        BaseSorter(int*anArr, int len){
            for(int i=0;i<len;i++){
                copy[i]=*anArr++;
                arr[i]=copy[i];
            }
            this->len=len;
            //cout<<"Unsorted\n";
            //printIt();
            
            //cout<<"\nUp here\n";
            //sortIt();
            //cout<<"Skipped it\n";
            
            //cout<<"Got here"<<endl;
        }
        BaseSorter(){}

};

class SelectionSort: public BaseSorter{
    public: void sortIt(){
        std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
        cout<<"\nI am in SelectionSort\n";
        //cout<<len<<endl;
        //cout<<"inside\n";
        int minVal, swap;
        int i=0;
    	for(int i=0;i<len-1;i++){
    	    //cout<<"done1\n";
    		//printIt();
    		minVal=i;
    		int j=1;
    		for(int j=i+1;j<len;j++){
                   //cout<<"\nComparing "<<arr[i]<<" and "<<arr[j]<<endl;
    			if(arr[j]<arr[minVal]){
    				minVal=j;
    			}
    			//cout<<"done2\n";
    		}
    
    		//cout<<"\nMinVal: "<<arr[minVal]<<endl;
    		swap=arr[minVal];
    		arr[minVal]=arr[i];
    		arr[i]=swap;
            //cout<<"Swapped\n\n";
    	}
    	std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
        duration = std::chrono::duration_cast<std::chrono::duration<double> >(_end - _start).count();
    //	cout<<"done\n";
    }
    SelectionSort(int*anArr, int len): BaseSorter(anArr,len){
        
    }
};
class BubbleSort: public BaseSorter{
    public: void sortIt(){
        cout<<"I am in BubbleSort";
        int swap;
    	for(int i=0; i<len-1;i++){
    		//cout<<endl;
    		for(int j=0;j<len-i-1;j++){
    			if(arr[j]>arr[j+1]){
    				//cout<<"Swapping\n";
    				swap=arr[j];
    				arr[j]=arr[j+1];
    				arr[j+1]=swap;
    			}
    			//printList();
    		}
    	}
    }
    BubbleSort(int*anArr, int len): BaseSorter(anArr,len){
        
    }
};
class InsertionSort: public BaseSorter{
        public: void sortIt(){
        cout<<"I am in InsertionSort";
        int i, key, j;
    	for(int i=1;i<len;i++){
    		//printList();
    		//cout<<endl;
    		key=arr[i];
    		j=i-1;
    		while(j>=0&&arr[j]>key){
    			arr[j+1]=arr[j];
    			j--;
    		}
    		arr[j+1]=key;
    	}
    }
    InsertionSort(int*anArr, int len): BaseSorter(anArr,len){
        
    }
};
void fillList(int arr[], int len, int rng, bool usrIn){
    int holder,x;
		if(usrIn){
			for(int i=0;i<len;i++)
				cin>>arr[i];
		}
		else{
		    x=time(new time_t);
            for(int i=0;i<len;i++){
                holder=x*(i+1);
                srand(holder);
                arr[i]=rand()%rng;
            }
		}
};
void printIt(int*p){
    for(int i=0;i<len;i++){
        cout<<*p++<<'\t';
        if(i%10==0&&i!=0)
            cout<<endl;
    }
}


int main(int argc, const char* argv[]){
    int rng=1000000;
    int arr[len];
    fillList(arr,len,rng,0);
    BaseSorter *fakeSorter;
    int sortType=1;

    switch(sortType){
        case 0: fakeSorter= new BaseSorter(arr,len);
        break;
        case 1: fakeSorter= new InsertionSort(arr,len);
        break;
        case 2: fakeSorter= new BubbleSort(arr,len);
        
    }
    
    cout<<"\nSelectionSort:: Before sorting..."<<endl;
    printIt(fakeSorter->Sorted());
    fakeSorter->sortIt();
    cout<<"\nAfter effects..."<<endl;
    printIt(fakeSorter->Sorted());
    cout<<endl;
    /*
    BaseSorter *fakeSorter= new SelectionSort(arr,len);
    SelectionSort *aSelSort= new SelectionSort(arr,len);
    fakeSorter=aSelSort;
    
    
    //InsertionSort 
    InsertionSort aInSort(arr,len);
    cout<<"\nInsertionSort:: Before sorting..."<<endl;

    printIt(aInSort.Sorted());
    aInSort.sortIt();
    cout<<"\nAfter effects..."<<endl;
    printIt(aInSort.Sorted());
    cout<<endl;
    
    //BubbleSort
    BubbleSort aBBSort(arr,len);
    cout<<"\nBubbleSort:: Before sorting..."<<endl;

    printIt(aBBSort.Sorted());
    aBBSort.sortIt();
    cout<<"\nAfter effects..."<<endl;
    printIt(aBBSort.Sorted());
    cout<<endl<<endl;*/
    
} 