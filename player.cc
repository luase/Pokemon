#include "player.h"

#include <iostream>

Player::Player()
{
}

Player::Player(vector<Pokemon> pok, vector<Item> it, string name)
{
	set_Pokemon(pok);
	set_Items(it);
	set_name(name);
}

void Player::set_Pokemon(vector<Pokemon> pok)
{
	pokemones = pok;
	return;
}

void Player::set_Items(vector<Item> it)
{
	items = it;
}

void Player::set_name(string name)
{
	(*this).name = name;
}

int Player::num_Pokemon()
{
	return pokemones.size();
}

int Player::num_Items()
{
	return items.size();
}

string Player::name_poke(int n)
{
	if (n > pokemones.size() || n < 0)
		return "No data pokemon.";
	return pokemones[n].name();
}
string Player::name_item(int n)
{
	if (n > items.size() || n < 0)
		return "No data item.";
	return items[n].nombre;
}

string Player::ver_nombre(Player p)
{
	return p.name;
}
