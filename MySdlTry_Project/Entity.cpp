#include"Entity.h"

void Entity::Update(){

	printf("(x,y)\t->\t(%.f,%.f)\n", _x, _y);
}

void Entity::Render(){

}

Entity::Entity() {

}
Entity::Entity(float x, float y,std::string filename){

	_x = x;
	_y = y;
	_filename = filename;
}

Entity::~Entity(){
}
float Entity::X() {
	return _x;
}
float Entity::Y() {
	return _y;
}
void Entity::X(float x){

	_x = x;
}
void Entity::Y(float y) {

	_y = y;
}

