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
#include <fstream>
using namespace std;

class Movie
{
public:
    // Constructors
    Movie();
    Movie(char movieType, int stock, string director, string title, int releaseYear);
    ~Movie();
    
    // Setters
    virtual void setData(ifstream &file);
    virtual void setMovieType(char movieType);
    virtual void setStock(int stock);
    virtual void setDirector(string director);
    virtual void setTitle(string title);
    virtual void setReleaseYear(int releaseYear);
    
    virtual void setMajorActor(string majorActor);
    virtual bool setReleaseMonth(int month);
    
    // Getters
    virtual char getMovieType() const;
    virtual int getStock() const;
    virtual string getDirector() const;
    virtual string getTitle() const;
    virtual int getReleaseYear( )const;
    
    virtual string getMajorActor()const;
    virtual int getReleaseMonth()const;
    
    //Methods that change the stock of a movie
    virtual bool increaseStock();
    virtual bool decreaseStock();
    
    //Operator overloads
    virtual bool operator==(const Movie& c)const = 0;
    virtual bool operator!=(const Movie& c)const = 0;
    virtual bool operator>(const Movie& c)const = 0;
    virtual bool operator<(const Movie& c)const = 0;
    virtual Movie* operator=(const Movie& c);

    //Displays the informations of a movie object
    virtual void display()const;
    
protected:
    char movieType;
    int stock;
    string director;
    string title;
    int releaseYear;
};

#endif /* Movie_h */
