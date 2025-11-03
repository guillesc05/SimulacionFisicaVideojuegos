#pragma once
class UpdateableObject
{
public:
	virtual void integrate(double t) = 0;
	virtual ~UpdateableObject() {}
};

