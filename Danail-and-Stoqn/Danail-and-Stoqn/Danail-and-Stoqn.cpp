#include <iostream>
#include "../Project1/library.h"

using namespace std;
void testLibrary() {

	Book b1 = createBook("Book One", "Author A", 2000, 20.50);
	Book b2 = createBook("Book Two", "Author B", 1995, 15.75);

	Library lib;
	lib.name = "Test Library";
	lib.count = 2;
	lib.books = new Book[lib.count];
	lib.books[0] = b1;
	lib.books[1] = b2;

	printLibrary(lib);
	cout << "Average: " << averageBookPrice(lib) << endl;
	Book oldest = oldestBookInLibrary(lib);
	cout << "Oldest: ";
	printBook(oldest);
	delete[] lib.books;
}
int main() {
	testLibrary();
}