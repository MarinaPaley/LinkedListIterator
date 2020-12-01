#include "pch.h"

#include "../LinkedList.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(IteratorTests)
	{
	public:
		
		TEST_METHOD(LeftShiftOperator_EmptyCollection_SpaceBetweenCurveBraces)
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

        TEST_METHOD(LeftShiftOperator_OneElementCollection_SpaceBetweenCurveBraces)
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

        TEST_METHOD(LeftShiftOperator_Collection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const LinkedList<int> list = {1,2,3};
            std::stringstream buffer;
            const std::string expected = "{ 1, 2, 3 }";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }
	};
}
