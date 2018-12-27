#ifndef FIGURE_H
#define FIGURE_H

class Figure {
    public:


        virtual double        Square() = 0;
        virtual void          Print()  = 0;
		virtual unsigned char Type()   = 0;


        virtual ~Figure() {};



        bool operator < (Figure &fig) {
        	return this->Square() < fig.Square();
        }

		bool operator <= (Figure &fig) {
			return this->Square() <= fig.Square();
		}

		bool operator > (Figure &fig) {
			return this->Square() > fig.Square();
		}

		bool operator >= (Figure &fig) {
			return this->Square() >= fig.Square();
		}
};

#endif 
