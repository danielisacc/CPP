#ifndef TIPS_H
#define TIPS_H
    /*
    Class: Tips
    Constrctor Params: taxRate
    Attributes: double taxrate
    Methods: computeTip
    --------------------------
    Class designed to provide framework for Tip objects
    */
    class Tips{
        private:
        double taxRate;

        public:
        Tips(int taxRate = 0.085) {taxRate = taxRate;}

        double computeTip(double bill, double taxRate);
    };
#endif