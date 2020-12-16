#include <iostream>
#include "../LinkedList.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{
    TEST_CLASS(IteratorTests)
    {
    public:
        TEST_METHOD(LeftShiftOperator_EmptyIntCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<int> emptyList;
            std::stringstream buffer;
            const std::string expected = " ";

            //Act
            buffer << emptyList;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_EmptyStringCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<std::string> emptyList;
            std::stringstream buffer;
            const std::string expected = " ";

            //Act
            buffer << emptyList;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_OneIntElementCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<int> list = { 1 };
            std::stringstream buffer;
            const std::string expected = "1";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_OneStringElementCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<std::string> list = { "1" };
            std::stringstream buffer;
            const std::string expected = "1";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_IntCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<int> list = { 1, 2, 3 };
            std::stringstream buffer;
            const std::string expected = "1 2 3";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_StringCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<std::string> list = { "1", "2", "3" };
            std::stringstream buffer;
            const std::string expected = "1 2 3";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(GetFirst_IntCollection_AreEqualFirstItem)
        {
            //Arrange
            const LinkedList<int> list = { 1, 2, 3 };
            const auto expected = 1;

            //Act
            const auto actual = list.GetFirst();

            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetFirst_IntEmptyCollection_Exception)
        {
            //Arrange
            const LinkedList<int> empty = { };

            // Act & Assert
            Assert::ExpectException<std::exception>([&]() { auto item = empty.GetFirst(); });
        }

        TEST_METHOD(GetFirst_StringEmptyCollection_Exception)
        {
            //Arrange
            const LinkedList<std::string> empty = { };

            // Act & Assert
            Assert::ExpectException<std::exception>([&]() { auto item = empty.GetFirst(); });
        }

        TEST_METHOD(GetFirst_StringCollection_AreEqualFirstItem)
        {
            //Arrange
            const LinkedList<std::wstring> list = { L"1", L"2", L"3" };
            const std::wstring expected = L"1";

            //Act
            const auto &actual = list.GetFirst();

            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(Add_IntCollection_AreEqualAddBack)
        {
            //Arrange
            LinkedList<int> list = {1, 2, 3};

            const LinkedList<int> expected = {1, 2, 3, 4};

            //Act
            list.Add(4);

            //Assert
            Assert::AreEqual(expected, list);
        }

        TEST_METHOD(Add_IntEmptyCollection_OneIntElementInCollection)
        {
            //Arrange
            LinkedList<int> empty = {};

            const LinkedList<int> expected = { 1 };

            //Act
            empty.Add(1);

            //Assert
            Assert::AreEqual(expected, empty);
        }

        TEST_METHOD(Add_StringCollection_AreEqualAddBack)
        {
            // TODO: так как у теста только wostream и есть проблема со string,
            // то нужно использовать wstring вместо string

            //Arrange
            LinkedList<std::wstring> list = { L"1", L"2", L"3" };

            const LinkedList<std::wstring> expected = { L"1", L"2", L"3", L"4" };

            //Act
            list.Add(L"4");

            //Assert
            Assert::AreEqual(expected, list);
        }

        TEST_METHOD(AreEqualOperator_SameIntColletion_Success)
        {
            //Arrange
            const LinkedList<int> list = { 1, 2, 3 };
            //Act
            //Assert
            Assert::AreEqual(list, list);
        }

        TEST_METHOD(AreEqualOperator_TwoIntColletions_Success)
        {
            //Arrange
            const LinkedList<int> expected = { 1, 2, 3 };
            const LinkedList<int> actual = { 1, 2, 3 };
            //Act
            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(AreNotEqual_IntCollectionAndEmptyCollection_NotSuccess)
        {
            //Arrange
            const LinkedList<int> list = { 1, 2, 3 };
            const LinkedList<int> emptyList;

            Assert::AreNotEqual(list, emptyList);
        }

        TEST_METHOD(AreNotEqual_IntCollectionsDifferentLengthLeftLonger_NotSuccess)
        {
            //Arrange
            const LinkedList<int> expected = { 1, 2, 3 };
            const LinkedList<int> actual = { 1, 2 };

            Assert::AreNotEqual(expected, actual);
        }
        TEST_METHOD(AreNotEqual_IntCollectionsDifferentLengthLeftShorter_NotSuccess)
        {
            //Arrange
            const LinkedList<int> expected = { 1, 2, 3 };
            const LinkedList<int> actual = { 1, 2, 3, 4 };

            Assert::AreNotEqual(expected, actual);
        }

        TEST_METHOD(AreEqualOperator_SameStringColletions_Success)
        {
            //Arrange
            const LinkedList<std::wstring> list = { L"1", L"2", L"3" };

            //Act & Assert
            Assert::AreEqual(list, list);
        }

        TEST_METHOD(AreEqualOperator_TwoStringColletions_Success)
        {
            //Arrange
            const LinkedList<std::wstring> expected = { L"1", L"2", L"3" };
            const LinkedList<std::wstring> actual = { L"1", L"2", L"3" };

            //Act & Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(AreNotEqual_StringtCollectionAndEmptyCollection_NotSuccess)
        {
            //Arrange
            const LinkedList<std::wstring> list = { L"1", L"2", L"3" };
            const LinkedList<std::wstring> emptyList;

            //Act & Assert
            Assert::AreNotEqual(list, emptyList);
        }

        TEST_METHOD(AreNotEqual_StringCollectionsDifferentLengthLeftLonger_NotSuccess)
        {
            //Arrange
            const LinkedList<std::wstring> expected = { L"1", L"2", L"3" };
            const LinkedList<std::wstring> actual = { L"1", L"2" };


            Assert::AreNotEqual(expected, actual);
        }

        TEST_METHOD(AreNotEqual_StringCollectionsDifferentLengthLeftShorter_NotSuccess)
        {
            //Arrange
            const LinkedList<std::wstring> expected = { L"1", L"2", L"3" };
            const LinkedList<std::wstring> actual = { L"1", L"2", L"3", L"4" };

            Assert::AreNotEqual(expected, actual);
        }
    };
}
