#pragma once
#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Library.h"

TEST_CASE("User functionality") {
    User user1;
    CHECK(user1.getName() == "");
    user1.setPassword("test");
    CHECK(user1.getPassword() == "test");
    CHECK(user1.getAdmin() == 0);
    User user2;
    User user3;
    CHECK((user2 == user3) == 1);
    CHECK((user2 == user1) == 0);
    std::ifstream in("UserTestLoad.txt");
    user2.loadUser(in);
    CHECK(user2.getPassword() == "test");
    user2.setAdmin(1);
    CHECK(user2.getAdmin() == 1);
}


TEST_CASE("Book functionality")
{
    Book book1;
    CHECK(book1.getTitle() == "");
    Vector<String> tags;
    tags.pushBack("Test1");
    tags.pushBack("Test2");
    book1.setTags(tags);
    CHECK(book1.getTags()[1] == "Test2");
    book1.setTitle("test");
    CHECK(book1.getTitle() == "test");
    Book book2;
    std::ifstream in2("BookTestLoad.txt");
    book2.loadBook(in2);
    CHECK(book2.getRating() == 100.0);
}

TEST_CASE("UserStore functionality")
{
    UserStore uStore1;
    uStore1.addUser("test", "test2");
    CHECK(uStore1[0].getPassword() == "test2");
    uStore1.addUser("test", ".");
    CHECK(uStore1.getSize() == 1);
    uStore1.addUser("test2", ".");
    CHECK(uStore1.getSize() == 2);
    uStore1.removeUser("test");
    CHECK(uStore1.getSize() == 1);
    CHECK(uStore1[0].getPassword() == ".");
    uStore1.clear();
    CHECK(uStore1.getSize() == 0);
    std::ifstream in3("UserStoreTestLoad.txt");
    UserStore uStore2;
    uStore2.loadUsers(in3);
    CHECK(uStore2.activeUserIndex() == 0);
    CHECK(uStore2[0].getAdmin() == 1);
    CHECK(uStore2.getSize() == 4);
}

TEST_CASE("BookStore functionality")
{
    BookStore bStore1;
    std::ifstream in4("BookStoreTestLoad.txt");
    bStore1.loadBooks(in4, 0);
    CHECK(bStore1.getSize() == 4);
    bStore1.removeBook("test");
    CHECK(bStore1.getSize() == 4);
    bStore1.removeBook("J");
    CHECK(bStore1.getSize() == 3);
    bStore1.sortBooksAscending("title");
    CHECK(bStore1[0].getTitle() == "A");
    bStore1.sortBooksDescending("title");
    CHECK(bStore1[0].getTitle() == "Q");
    bStore1.clear();
    CHECK(bStore1.getSize() == 0);
}

TEST_CASE("CommandMenu functionality")
{
    CommandMenu menu1;
    menu1.setCommand("users add dani 100");
    menu1.getCommand();
    menu1.checkSecondCommand(menu1.getTheCommand()[2]);
    menu1.getParameters();
    CHECK(menu1.getTheCommand()[0] == "users add");
    CHECK(menu1.getTheParameters().getSize() == 2);
    menu1.setCommand("open test.txt");
    menu1.getCommand();
    menu1.checkSecondCommand(menu1.getTheCommand()[2]);
    menu1.getParameters();
    CHECK(menu1.getTheCommand()[0] == "open");
    CHECK(menu1.getTheParameters().getSize() == 1);
}

void runtests() {
    doctest::Context().run();
}

