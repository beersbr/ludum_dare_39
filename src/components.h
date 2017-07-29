#pragma once

class Comopnent;
class GameObject;

class Component { 
public:
	Entity *owner;

	virtual void init() {}
	virtual void update() {}
	virtual void draw() {}

	virtual ~Component() {}
};


class GameObject { 
private:
	bool alive;
	bool dead;

	
}
