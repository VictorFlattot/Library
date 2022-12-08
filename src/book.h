#include "date.h"
#include "writer.h"
#include <utility>
#include <vector>
#include <string>
#include "language.h"
#include "genre.h"

#pragma once


class Book {
private:
    std::string _title;
    Writer _writer;
    Language _language;
    Genre _genre;
    Date _datePublished;
    std::string _isnb;
    std::vector<std::string> _lastsBorrowers;
    bool _isBorrowed;

public:
    explicit Book(std::string title = "Untitled", Writer writer = Writer(), Language language = Language::Unspecified,
                  Genre genre = Genre::Unspecified, Date datePublished = Date(01, 01, 0000),
                  std::string ISNB = "0000000000", std::vector<std::string> lastsBorrowers = {},
                  bool isBorrowed = false);

    std::string getTitle() const {
        if (_title.empty()) return "Untitled";
        return _title;
    }

    /*
     * @param Borrower
     * @type {(borrower : std::string)}
     */
    void addLastBorrower(const std::string &borrower) { _lastsBorrowers.push_back(borrower); }


    /* =================================================================
     * Getters and setters
     */

    Writer getWriter() const { return _writer; }

    Language getLanguage() const { return _language; }

    Genre getGenre() const { return _genre; }

    Date getDatePublished() const { return _datePublished; }

    std::string getISNB() const { return _isnb; }

    std::vector<std::string> getLastsBorrowers() const { return _lastsBorrowers; };

    bool isBorrowed() const { return _isBorrowed; }

    void setTitle(std::string title) { _title = std::move(title); }

    void setWriter(Writer writer) { _writer = std::move(writer); }

    void setLanguage(Language language) { _language = language; }

    void setGenre(Genre genre) { _genre = genre; }

    void setDatePublished(Date datePublished) { _datePublished = datePublished; }

    void setISNB(std::string isnb) { _isnb = std::move(isnb); }

    void setLastsBorrowers(std::vector<std::string> lastBorrowers) { _lastsBorrowers = std::move(lastBorrowers); }

    void setIsBorrowed(bool isBorrowed) { _isBorrowed = isBorrowed; }

};

bool isBook(const std::string &title, Writer writer, Date published, const std::string &isnb);

bool isBook(const Book &book);

std::string displayVector(std::vector<std::string> const &strings);

std::string to_string(const Book &b);

std::ostream &operator<<(std::ostream &os, const Book &book);