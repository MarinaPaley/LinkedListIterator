﻿#include "pch.h"

#include "../LinkedList.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(IteratorTests)
    {
    public:

        TEST_METHOD(LeftShiftOperator_EmptyIntCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<int> emptyList;
            std::stringstream buffer;
            const std::string expected = "{ }";

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
            const std::string expected = "{ }";

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
            const std::string expected = "{ 1 }";

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
            const std::string expected = "{ 1 }";

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
            const std::string expected = "{ 1, 2, 3 }";

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
            const std::string expected = "{ 1, 2, 3 }";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(GetFirst_IntCollection_Success)
        {
            //Arrange
            const LinkedList<int> list = { 1, 2, 3 };
            const auto expected = 1;

            //Act
            const auto actual = list.GetFirst();

            //Assert
            Assert::AreEqual(expected, actual);
        }


        TEST_METHOD(GetFirst_StringCollection_Success)
        {
            //Arrange
            const LinkedList<std::string> list = { "1", "2", "3" };
            const std::string expected = "1";

            //Act
            const auto &actual = list.GetFirst();

            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(Add_IntCollection_Success)
		{
            //Arrange
            LinkedList<int> list = { 1, 2, 3 };

            const LinkedList<int> expected = { 1, 2, 3, 4 };

            //Act
            list.Add(4);

            //Assert
            Assert::AreEqual(expected, list);
        }

        TEST_METHOD(Add_StringCollection_Success)
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
    };
}