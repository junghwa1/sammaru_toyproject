#pragma once
#ifndef TELEPHONE_H
#define TELEPHONE_H

typedef class telephone* telepointer;

class telephone {
public:
	telepointer left;
	string name;
	string number;
	bool star;
	telepointer right;

	telephone();
	~telephone();
	void printMenu();
	telephone createNode();
	void delete_member(telepointer h, string name);
	void delete_all();
	telepointer searchNode(string name);
	void insertNode(telepointer h, string name, string number);
	void show_member();
	void modify(telepointer h);
	void add_Favorites();
	void delete_Favorites();
	void print_Favorites();
};

#endif