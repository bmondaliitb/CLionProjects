#include <iostream>

// Write a class which takes the values of pt, eta, met, mt, njet, nbjet vars
// and fills it in the multi-dimensional array
class Efficiency{
public:
    Efficiency() = default;
    ~Efficiency() = default;
    void fillEvent(double pt, double eta, double njets, double nbjets, double mt, double met, double dPhi, double eventWeight);

    int getIndex(double bin[], double val);

    void print();

private:
    double nEvents[3][3][3][3][3][3][3]{};
    double ptBins[4]={0,45,65,150};
    double etaBins[4]={0,45,65,150};
    double njetBins[4]={0,45,65,150};
    double nbjetBins[4]={0,45,65,150};
    double mtBins[4]={0,45,65,150};
    double metBins[4]={0,45,65,150};
    double dphiBins[4]={0,45,65,150};
};

int Efficiency::getIndex(double bin[], double val) {
    int index = -1;
    if(bin[0]<val && val< bin[1]) index=0;
    else if(bin[1]<val && val<bin[2]) index =1 ;
    else if(bin[2]<val && val<bin[3]) index=2;
    return index;
}

void Efficiency::fillEvent(double pt, double eta, double njets, double nbjets, double mt, double met, double dphi, double eventWeight) {
    int indexPt = this->getIndex(ptBins,pt);
    int indexEta = this->getIndex(etaBins,eta);
    int indexNjet = getIndex(njetBins,njets);
    int indexNbjet = getIndex(nbjetBins,nbjets);
    int indexMt= getIndex(mtBins,mt);
    int indexMet= getIndex(metBins,met);
    int indexDphi= getIndex(dphiBins,dphi);
    nEvents[indexPt][indexEta][indexNjet][indexNbjet][indexMt][indexMet][indexDphi] += eventWeight;
}

void Efficiency::print() {
    for(int ptitr=0;ptitr<(sizeof ptBins/sizeof(double))-1; ptitr++)
        for(int etaitr=0;etaitr<(sizeof etaBins/sizeof(double ))-1; etaitr++)
            for(int njetsitr=0;njetsitr<(sizeof njetBins/sizeof(double))-1; njetsitr++)
                    for(int mtitr=0;mtitr<(sizeof mtBins/sizeof(double))-1; mtitr++)
                        for(int metitr=0;metitr<(sizeof metBins/sizeof(double))-1; metitr++)
                            for(int dphiitr=0;dphiitr<(sizeof dphiBins/sizeof(double))-1; dphiitr++)
                                std::cout<<nEvents[ptitr][etaitr][njetsitr][mtitr][metitr][dphiitr]<<std::endl;
}

int main() {
    auto* calculateEfficiency = new Efficiency;
    calculateEfficiency->fillEvent(20, 50, 80, 11, 0, 60, 60, 1.5);
    calculateEfficiency->fillEvent(20, 50, 80, 11, 0, 60, 60, 1.5);
    calculateEfficiency->fillEvent(20, 50, 80, 11, 0, 60, 60, 1.5);
    calculateEfficiency->fillEvent(20, 50, 80, 11, 0, 60, 60, 1.5);
    calculateEfficiency->fillEvent(20, 50, 80, 11, 0, 60, 60, 1.5);
    calculateEfficiency->print();

    return 0;
}


