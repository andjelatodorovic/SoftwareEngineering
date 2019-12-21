#pragma once
#include <iostream>
#include "Izmerljivo.h"
#include "Tacka.h"
#include <math.h>

using namespace std;

template<class T> class Pravougaonik : public Izmerljivo{
private:
	Tacka<T> doleLevo, goreDesno;
public:
	Pravougaonik(Tacka<T> dl, Tacka<T> gd){
		this->doleLevo = dl; this->goreDesno = gd;
	}
	Pravougaonik(){
		doleLevo = Tacka<T>();
		goreDesno = Tacka<T>();
	}
	~Pravougaonik(){}
	Tacka<T> getDoleLevo() const {return doleLevo;}
	Tacka<T> getGoreDesno() const {return goreDesno;}

	T getNajduzaStrana() const{
		T maxStrana = goreDesno.getY() - doleLevo.getY();
		if(maxStrana < goreDesno.getX() - doleLevo.getX())
			maxStrana = goreDesno.getX() - doleLevo.getX(); 
		return maxStrana;
	}

	void setDoleLevo(Tacka<T> arg) {doleLevo = arg;}
	void setGoreDesno(Tacka<T> arg) {goreDesno = arg;}

	double getMera() const {
		double mera =   ((double) goreDesno.getY() - (double) doleLevo.getY()) 
					  * ((double) goreDesno.getX() - (double) doleLevo.getX()) ;
		return mera;
	}

	bool operator< (const Pravougaonik & dp) const{
		if(getMera() < dp.getMera())
			return true;
		else
			return false;
	}
};


	template<class T>
	ostream& operator << (ostream& os, const Pravougaonik<T> & d)
	{
		os<<"["<<d.getDoleLevo()<<","<<d.getGoreDesno()<<"]";
		return os; 
	}
