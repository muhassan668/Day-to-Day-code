#include <iostream>
#include <vector>
using namespace std;

template <class T>
class DataBuffer{
	private:
		T* data;
		int size;
	public:
		DataBuffer(int s){
			size = s;
			data = new T[s];
		}
		~DataBuffer(){
			delete[] data;
		}
		DataBuffer(const DataBuffer<T>& other){
			size = other.size;
			data = new T[other.size];
			for(int i=0; i<other.size; i++){
				data[i] = other.data[i];
			}
		}
		DataBuffer<T>& operator=(const DataBuffer<T>& other){
			size = other.size;
			delete[] data;
			data = new T[other.size];
			for(int i=0; i<other.size; i++){
				data[i] = other.data[i];
			}
			return *this;
		}
		void fill(T val){
			cout<<"Filling....."<<endl;
			for(int i=0; i<size; i++){
				this->data[i] = val;
			}
		}
};
class AINode{
	protected:
		string nodeName;
	public:
		AINode(string n): nodeName(n){}
		virtual void processData() = 0;
		virtual ~AINode(){}
};
class VisionNode: public AINode{
	private:
		DataBuffer<float> obj;
	public:
		VisionNode(string n, int bufferSize): AINode(n), obj(bufferSize){}
		void processData() override{
			cout<<"Processing vision matrix..."<<endl;
		}
};
int main(){
cout << "--- Testing Rule of Three ---" << endl;
	DataBuffer<int> buffer1(5);
	cout << "Buffer 1 created." << endl;
	buffer1.fill(7);
	
	DataBuffer<int> buffer2 = buffer1; // Triggers Copy Constructor
	
	DataBuffer<int> buffer3(5); 
	buffer3 = buffer1; // Triggers Assignment Operator
	
	cout << "\n--- STL AI Pipeline ---" << endl;
	// Creating an STL Vector of base class pointers
	vector<AINode*> pipeline;
	
	// Pushing dynamically allocated derived classes
	pipeline.push_back(new VisionNode("Camera_1", 100));
	pipeline.push_back(new VisionNode("Camera_2", 100));
	
	// Using the STL .size() to loop and trigger polymorphism
	for(int i = 0; i < pipeline.size(); i++){
	    pipeline[i]->processData();
	}
	
	cout << "\n--- Memory Cleanup ---" << endl;
	// Manually deleting pointers inside the vector
	for(int i = 0; i < pipeline.size(); i++){
	    delete pipeline[i];
	}
	pipeline.clear(); // Emptying the vector itself
	
	return 0; // Stack variables (buffer1, buffer2, buffer3) get deleted here automatically
}
	












