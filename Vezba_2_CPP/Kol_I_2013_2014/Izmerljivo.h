#pragma once
class Izmerljivo{
public:
	Izmerljivo(){}
	virtual ~Izmerljivo(){}
	virtual double getMera() const = 0;
};