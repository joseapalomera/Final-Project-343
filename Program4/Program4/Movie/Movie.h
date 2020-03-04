//
//  Movie.h
//  Program4
//
//  Created by Gurjepaul Brar on 3/3/20.
//  Copyright © 2020 Gurjepaul Brar. All rights reserved.
//

#ifndef Movie_h
#define Movie_h

#include <string>
#include <iostream>
using namespace std;

class Movie
{
    friend ostream& operator<<(ostream &os, const Movie &other);

public:
    // Constructors
    Movie();
    Movie(char movieType, int stock, string director, string title, int releaseYear);
    ~Movie();
    
    // Setters
    virtual void setMovieType(char movieType);
    virtual void setStock(int stock);
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setReleaseYear(int releaseYear);
    
    // Getters
    virtual char getMovieType() const;
    virtual int getStock() const;
    virtual string getDirector() const;
    virtual string getTitle() const;
    virtual int getReleaseYear( )const;
    
    // Operator overload
    virtual bool operator==(const Movie& m) const = 0;
    virtual bool operator!=(const Movie& m)const = 0;
    virtual bool operator>(const Movie& m) const = 0;
    virtual bool operator<(const Movie& m) const = 0;

protected:
    char movieType;
    int stock;
    string director;
    string title;
    int releaseYear;
};

#endif /* Movie_h */

