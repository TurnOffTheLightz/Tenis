#include"Handler.h"
#include"Collision.h"

Handler* Handler::_instance = NULL;

Handler::Handler(Graphics *g) {

	_graphics = g;

	CreatePlayers();

	_backgroundImg = new Texture("castle.png",0,0,800,600);
	
	_ball = new Ball(385.0f,285.0f,"ball.png");
}

Handler::~Handler() {

	_graphics = NULL;
}

void Handler::Release() {

	delete _instance;
	_instance = NULL;
}

void Handler::Render(){

	_graphics->ClearBackBuffer();

	_backgroundImg->Render();

	for (Player p : _players) {

		p.Render();
	}
	
	_ball->Render();

	_graphics->PrintScore(PlayerLeft()->Score(),PlayerRight()->Score());
	_graphics->Render();
}

void Handler::Update(){

	if (_space) {

		_space = false;
		if (!_ball->Shoot()) {

			_ball->Shoot(true);
		}
	}

	for (Player p : _players) {

		p.Update();
	}

	_ball->Update(PlayerLeft(),PlayerRight());

	if (Collision::Intersects(*_ball->GetTexture()->GetTextureRect(), 
		*PlayerLeft()->GetTexture()->GetTextureRect())) {
	
		_ball->ReverseVX();
	}
	if (Collision::Intersects(*_ball->GetTexture()->GetTextureRect(),
		*PlayerRight()->GetTexture()->GetTextureRect())) {

		_ball->ReverseVX();
	}

}

void Handler::Space(bool x){

	_space = x;
}

bool Handler::Space() {

	return _space;
}

Player * Handler::PlayerLeft(){

	return &_players.at(0);
}
Player * Handler::PlayerRight() {

	return &_players.at(1);
}

void Handler::AddPlayer(Player &p){

	_players.push_back(p);
}

Handler *Handler::Instance(Graphics *g) {

	if (_instance == NULL) _instance = new Handler(g);
	return _instance;
}
void Handler::CreatePlayers() {

	Player pl(-1,250.0f,"player.png",Player::left);
	Player pr(-1,250.0f,"player.png",Player::right);

	AddPlayer(pl);
	AddPlayer(pr);
}