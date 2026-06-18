#include <iostream>
using namespace std;
int findTileSize(int length , int width){
    while(width !=0){
        int r = length % width;     // finding graetest common divisor that should be the size of tile
        length = width;
        width = r;
    }
    return length;
}
int findNumberOfTiles(int roomLength , int roomWidth , int sizeOfTile){
    int h = (roomLength/sizeOfTile)*(roomWidth/sizeOfTile);       // finding number of tiles
    return h;
}
int main(){
    int length , width;
    
    do{
        cout<<"Enter length of Room = ";
        cin>>length;
        if(length<=0){
            cout<<"Invalid length, Please ";
        }
    }while(length<=0);

    do{
        cout<<"Enter width of Room = ";
        cin>>width;
        if(width<=0){
            cout<<"Invalid width, Please ";
        }
    }while(width<=0);

    int g = findTileSize(length,width);
    int f = findNumberOfTiles(length , width , g);

    cout<<"The side length of the largest possible square tile is = "<<g<<endl;
    cout<<"The number of tiles required are = "<<f<<endl;
    return 0;
}
