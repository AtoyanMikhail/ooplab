#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class AbilityException : public std::exception {
public:
    virtual const char* what() const throw() = 0;
};

class NoAbilitiesException : public AbilityException {
public:
    const char* what() const throw() {
        return "No abilities are available!";
    }
};

class ShipPlacementException : public std::exception {
public:
    const char* what() const throw() {
        return "It is not possible to place a ship here!";
    }
};

class OutOfBoundsException : public std::exception {
public:
    const char* what() const throw() {
        return "Off-the-field attack!";
    }
};

#endif