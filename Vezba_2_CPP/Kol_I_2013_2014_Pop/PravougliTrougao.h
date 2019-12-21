#pragma once
#include <iostream>
#include "Mera.h"
#include "Point2D.h"
#include <math.h>

using namespace std;

template<class T> class PravougliTrougao : public Mera{
private:
	Point2D<T> osnovaLevo;
	Point2D<T> osnovaDesno;
	Point2D<T> vrh;
public:
	PravougliTrougao(Point2D<T> osnovaLevo, Point2D<T> osnovaDesno, Point2D<T> vrh ){
		this->osnovaLevo = osnovaLevo; this->osnovaDesno = osnovaDesno; this->vrh = vrh;
	}
	PravougliTrougao(){
		osnovaLevo = Point2D<T>();
		osnovaDesno = Point2D<T>();
		vrh = Point2D<T>();
	}
	~PravougliTrougao(){}
	Point2D<T> getOsnovaLevo() const {return osnovaLevo;}
	Point2D<T> getOsnovaDesno() const {return osnovaDesno;}
	Point2D<T> getVrh() const {return vrh;}

	void setOsnovaLevo(const Point2D<T> & arg) {osnovaLevo = arg;}
	void setOsnovaDesno(const Point2D<T> & arg) {osnovaDesno = arg;}
	void setVrh(const Point2D<T> & arg) {vrh = arg;}

	double getMera() const {
		double h = (double) vrh.getY() - (double) osnovaDesno.getY();
		h = h < 0 ? -1*h : h;
		double mera = ((double) osnovaDesno.getX() - (double) osnovaLevo.getX()) * h / 2.;
		return mera;
	}

	bool operator< (const PravougliTrougao<T> & dp) const{
		if(getMera() < dp.getMera())
			return true;
		else
			return false;
	}
	bool operator==(const PravougliTrougao<T> & dp) const{
		if(getMera() == dp.getMera())
			return true;
		else
			return false;
	}
};


	template<class T>
	ostream& operator << (ostream& os, const PravougliTrougao<T> & d)
	{
		os<<"["<<d.getOsnovaLevo()<<","<<d.getOsnovaDesno()<<"," << d.getVrh()<<"]";
		return os; 
	}
