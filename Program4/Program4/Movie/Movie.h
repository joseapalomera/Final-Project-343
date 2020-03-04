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
    void setMovieType(char movieType);
    void setStock(int stock);
    void setDirector(string director);
    void setTitle(string title);
    void setReleaseYear(int releaseYear);
    
    // Getters
    char getMovieType() const;
    int getStock() const;
    string getDirector() const;
    string getTitle() const;
    int getReleaseYear( )const;
    
    // Operator overload
    bool operator==(const Movie& m) const;
    bool operator!=(const Movie& m)const;
    bool operator>(const Movie& m) const;
    bool operator<(const Movie& m) const;

private:
    char movieType;
    int stock;
    string director;
    string title;
    int releaseYear;
};

#endif /* Movie_h */
