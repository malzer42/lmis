//
// Created by pam on 25/06/18.
//

#include "../inc/Title.h"

Title::Title(const std::string &program, const std::string &release) : program_{program}, release_{release} {
	std::cout << getProgram() << '\t' << getRelease() << '\n';

}

Title::~Title() {

}


const std::string &Title::getProgram() const {
	return program_;
}

void Title::setProgram(const std::string &program) {
	program_ = {program};
}

const std::string &Title::getRelease() const {
	return release_;
}

void Title::setRelease(const std::string &release) {
	release_ = {release};
}

