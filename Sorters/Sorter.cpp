#include<iostream>
#include<ctime>
#include<chrono>
#define size 1000
using namespace std;
const int len=size;



class SelectionSort{
        int len;
        int arr[size];
        int copy[size];
        double duration;
        void sortIt();
    public:
        int* Sorted(){
            return arr;
        }
        int* unSorted(){
            return copy;
        }
        /*void printIt(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<'\t';
                if(i%10==0&&i!=0)
                    cout<<endl;
            }
        }*/
        double burst(){
            return duration;
        }
        SelectionSort(int*anArr, int len){
            for(int i=0;i<len;i++){
                copy[i]=*anArr++;
                arr[i]=copy[i];
            }
            this->len=len;
            //cout<<"Unsorted\n";
            //printIt();
            std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
            //cout<<"\nUp here\n";
            sortIt();
            //cout<<"Skipped it\n";
            std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
            duration = std::chrono::duration_cast<std::chrono::duration<double> >(_end - _start).count();
            //cout<<"Got here"<<endl;
        }
};
void SelectionSort::sortIt(){
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
//	cout<<"done\n";
}
class InsertionSort{
        int len;
        int arr[size];
        int copy[size];
        double duration;
        void sortIt();
    public:
        int* Sorted(){
            return arr;
        }
        int* unSorted(){
            return copy;
        }
        /*void printIt(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<'\t';
                if(i%10==0&&i!=0)
                    cout<<endl;
            }
        }*/
        double burst(){
            return duration;
        }
        InsertionSort(int*anArr, int len){
            for(int i=0;i<len;i++){
                copy[i]=*anArr++;
                arr[i]=copy[i];
            }
            this->len=len;
            //cout<<"Unsorted\n";
            //printIt();
            std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
            //cout<<"\nUp here\n";
            sortIt();
            //cout<<"Skipped it\n";
            std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
            duration = std::chrono::duration_cast<std::chrono::duration<double> >(_end - _start).count();
            //cout<<"Got here"<<endl;
        }

};
void InsertionSort::sortIt(){
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
class BubbleSort{
        int len;
        int arr[size];
        int copy[size];
        double duration;
        void sortIt();
    public:
        int* Sorted(){
            return arr;
        }
        int* unSorted(){
            return copy;
        }
        /*void printIt(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<'\t';
                if(i%10==0&&i!=0)
                    cout<<endl;
            }
        }*/
        double burst(){
            return duration;
        }
        BubbleSort(int*anArr, int len){
            for(int i=0;i<len;i++){
                copy[i]=*anArr++;
                arr[i]=copy[i];
            }
            this->len=len;
            //cout<<"Unsorted\n";
            //printIt();
            std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
            //cout<<"\nUp here\n";
            sortIt();
            //cout<<"Skipped it\n";
            std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
            duration = std::chrono::duration_cast<std::chrono::duration<double> >(_end - _start).count();
            //cout<<"Got here"<<endl;
        }

};
void BubbleSort::sortIt(){
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
}
void printIt(int*p){
    for(int i=0;i<len;i++){
        cout<<*p++<<'\t';
        if(i%10==0&&i!=0)
            cout<<endl;
    }
}
int main(){
    int rng=1000000;
    int arr[len];
    fillList(arr,len,rng,0);
    
    SelectionSort stuff=SelectionSort(arr,len);
    cout<<"\nUnsorted\n";
    printIt(stuff.unSorted());
    cout<<"\nSorted\n";
    printIt(stuff.Sorted());
    
    InsertionSort stuff1=InsertionSort(arr,len);
    cout<<"\nUnsorted\n";
    printIt(stuff1.unSorted());
    cout<<"\nSorted\n";
    printIt(stuff1.Sorted());
    BubbleSort stuff2=BubbleSort(arr,len);
    cout<<"\nUnsorted\n";
    printIt(stuff2.unSorted());
    cout<<"\nSorted\n";
    printIt(stuff2.Sorted());
    cout<<endl;
    cout<<endl<<"SelectionSort: "<<stuff.burst()*1000<<" milliseconds";
    cout<<endl<<"InsertionSort: "<<stuff1.burst()*1000<<" milliseconds";
    cout<<endl<<"BubbleSort: "<<stuff2.burst()*1000<<" milliseconds"<<endl;
    
}