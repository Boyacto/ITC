#include<iostream>
#include<string>
using namespace std;

class RelojD{
private:
    int iHr,iMin;
public:
    RelojD();
    RelojD(int iHr,int iMin);

    void setHora(int iHr);
    void setMin(int iMin);
    
    int getHora();
    int getMin();

    void desplegar();
    void incrementaMinutos();
};

RelojD::RelojD(){
    iHr = 0;
    iMin = 0;
}

RelojD::RelojD(int iHr,int iMin){
    this->iHr = iHr;
    this->iMin = iMin;
}

void RelojD::setHora(int iHri){
    if(iHri >=0 && iHri<=23){
        iHr =iHri;
    }
    else{
        cout<<"Valor no valido"<<endl;
    }
}
void RelojD::setMin(int iMini){
    if(iMini >=0 && iMini<=59){
        iMin =iMini;
    }
    else{
        cout<<"Valor no valido"<<endl;
    }
}
int RelojD::getHora(){
    return iHr;
}
int RelojD::getMin(){
    return iMin;
}

void RelojD::desplegar(){
    cout<<iHr<<":"<<iMin<<"\n"<<endl;
}
void RelojD::incrementaMinutos(){
    if(iMin==59){
        if(iHr ==23){
            iHr =0;
            iMin=0;
        }
        else{
            iHr++;
            iMin =0;
        }
    }
    else{
        iMin++;
    }
}
