// Title.cpp: 
// Created by pam on 25/06/18.
//

#ifndef LMIS_TITLE_H
#define LMIS_TITLE_H

#include <string>
#include <iostream>

class Title {
public:
	Title(const std::string &program = {""}, const std::string &release = {""});

	~Title();

	const std::string &getProgram() const;

	void setProgram(const std::string &program);

	const std::string &getRelease() const;

	void setRelease(const std::string &release);

private:
	std::string program_;
	std::string release_;
};


#endif //LMIS_TITLE_H
