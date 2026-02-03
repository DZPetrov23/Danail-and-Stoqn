#include "library.h"
#include <iostream>
using namespace std;

Book createBook(const string& title,
    const string& author,
    int year,
    double price) {
    Book b;
    b.title = title;
    b.author = author;
    b.year = year;
    b.price = price;
    return b;
}

void printBook(const Book& book) {
    cout << "Title: " << book.title
        << ", Author: " << book.author
        << ", Year: " << book.year
        << ", Price: " << book.price << endl;
}

void printLibrary(const Library& library) {
    cout << "Library: " << library.name << endl;
    cout << "Number of books: " << library.count << endl;
    for (int i = 0; i < library.count; ++i) {
        cout << "Book " << i + 1 << ": ";
        printBook(library.books[i]);
    }
}

double averageBookPrice(const Library& library) {
    if (library.count == 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < library.count; ++i) {
        sum += library.books[i].price;
    }
    return sum / library.count;
}

Book oldestBookInLibrary(const Library& library) {
    if (library.count == 0) {
        Book empty;
        empty.year = 0;
        return empty;
    }
    Book oldest = library.books[0];
    for (int i = 1; i < library.count; ++i) {
        if (library.books[i].year < oldest.year) {
            oldest = library.books[i];
        }
    }
    return oldest;
}