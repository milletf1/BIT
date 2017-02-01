
#include "StdAfx.h"
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
namespace UnitTesting {
    using namespace System;
    ref class PatientPriorityQueueTest;
    
    
    /// <summary>
///This is a test class for PatientPriorityQueueTest and is intended
///to contain all PatientPriorityQueueTest Unit Tests
///</summary>
	[TestClass]
	public ref class PatientPriorityQueueTest
	{

	private: Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  testContextInstance;
			 /// <summary>
			 ///Gets or sets the test context which provides
			 ///information about and functionality for the current test run.
			 ///</summary>
	public: property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  TestContext
			{
				Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  get()
				{
					return testContextInstance;
				}
				System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^  value)
				{
					testContextInstance = value;
				}
			}

#pragma region Additional test attributes
			// 
			//You can use the following additional attributes as you write your tests:
			//
			//Use ClassInitialize to run code before running the first test in the class
			//public: [ClassInitialize]
			//static System::Void MyClassInitialize(TestContext^  testContext)
			//{
			//}
			//
			//Use ClassCleanup to run code after all tests in a class have run
			//public: [ClassCleanup]
			//static System::Void MyClassCleanup()
			//{
			//}
			//
			//Use TestInitialize to run code before running each test
			//public: [TestInitialize]
			//System::Void MyTestInitialize()
			//{
			//}
			//
			//Use TestCleanup to run code after each test has run
			//public: [TestCleanup]
			//System::Void MyTestCleanup()
			//{
			//}
			//
#pragma endregion
	/*******************************************************************************************
		 *									   Push Tests
		 ******************************************************************************************/
			
			//Test push works correctly.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePushTest()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 10));
				int expected = 10;
				//Act
				int actual = target->peek()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}

			//Test PriorityQueue orders correctly when the last patient has the higest priority.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePushOrderingTest1()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 10));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("second", 20));
				int expected = 20;
				//Act
				int actual = target->peek()->getPriority();

				Assert::AreEqual(expected, actual);
			}

			//Test PriorityQueue orders correctly when the first patient has the higest priority.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePushOrderingTest2()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 20));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("second", 10));
				int expected = 30;
				//Act
				int actual = target->peek()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}

			//Test push not adding to PriorityQueue when PriorityQueue is full.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePushQueueFullTest()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());				
				bool expected = true;
				bool actual = true;
				//Act
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				target->push(firstPatient);
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("second", 2));
				target->push(secondPatient);
				Patient_Accessor^ thirdPatient = (gcnew Patient_Accessor("third", 3));
				target->push(thirdPatient);
				Patient_Accessor^ fourthPatient = (gcnew Patient_Accessor("fourth", 4));
				target->push(fourthPatient);
				Patient_Accessor^ fifthPatient = (gcnew Patient_Accessor("fifth", 5));
				target->push(fifthPatient);
				Patient_Accessor^ sixthPatient = (gcnew Patient_Accessor("sixth", 6));
				target->push(sixthPatient);
				Patient_Accessor^ seventhPatient = (gcnew Patient_Accessor("seventh", 7));
				target->push(seventhPatient);
				Patient_Accessor^ eighthPatient = (gcnew Patient_Accessor("eighth", 8));
				target->push(eighthPatient);
				Patient_Accessor^ ninthPatient = (gcnew Patient_Accessor("ninth", 9));
				target->push(ninthPatient);
				Patient_Accessor^ tenthPatient = (gcnew Patient_Accessor("tenth", 10));
				target->push(tenthPatient);
				Patient_Accessor^ eleventhPatient = (gcnew Patient_Accessor("eleventh", 11));
				target->push(eleventhPatient);
				
				
				//Iterate through each patient in the list
				for each(Patient_Accessor^ p in target->getPatientQueue())
				{
					//Check if the current patient is the one that should be missing from the list
					if(p->getName()->CompareTo("eleventh") == 0)
					{						
						actual = false;
					}					
				}
				//Assert
				Assert::AreEqual(expected, actual);
			}

		/*******************************************************************************************
		 *									   isEmpty Tests
		 ******************************************************************************************/

			//Test PriorityQueue returns true when isEmpty is called when their are no patients in queue.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueueIsEmptyTrue()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());				
				bool expected = true;
				//Act
				bool actual = target->isEmpty();
				//Assert
				Assert::AreEqual(expected, actual);
			}

			//Test PriorityQueue returns false when isEmpty is called when their are patients in queue.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueueIsEmptyFalse()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				bool expected = false;
				//Act
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				target->push(firstPatient);
				bool actual = target->isEmpty();
				//Assert
				Assert::AreEqual(expected, actual);
			}
		/*******************************************************************************************
		 *									  Count Tests
		 ******************************************************************************************/

			//Test PriorityQueue returns the correct count.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueueCountTest()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());				
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				int expected = 1;
				//Act
				target->push(firstPatient);
				int actual = target->count();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			
		/*******************************************************************************************
		 *									   Peek Tests
		 ******************************************************************************************/
			//Test peek returns nullptr when PriorityQueue is empty.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePeekEmpty()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ expected = nullptr;
				//Act
				Patient_Accessor^ actual = target->peek();
				//Assert
				Assert::AreEqual(expected, actual);
			}

			//Test peek works correctly when PriorityQueue has one Patient.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePeekOne()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());				
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				int expected = 1;
				//Act
				target->push(firstPatient);
				int actual = target->peek()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test peek works correctly when PriorityQueue has more than one Patient.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePeekMany()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("first", 2));
				int expected = 2;
				//Act
				target->push(firstPatient);
				target->push(secondPatient);
				int actual = target->peek()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test peek works correctly after calling pop.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePopThenPeek()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("first", 2));
				int expected = 1;
				//Act
				target->push(firstPatient);
				target->push(secondPatient);
				target->pop();
				int actual = target->peek()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test number of Patients in the queue after peek.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePeekThenCount()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				int expected = 1;
				//Act
				target->peek();
				int actual = target->count();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			 

		/*******************************************************************************************
		 *									    Pop Tests
		 ******************************************************************************************/
			//Test pop returns nullptr when PriorityQueue is empty.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePopEmpty()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ expected = nullptr;
				//Act
				Patient_Accessor^ actual = target->pop();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test pop works correctly when PriorityQueue has one Patient.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePopOne()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				int expected = 1;
				//Act
				target->push(firstPatient);
				int actual = target->pop()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test pop works correctly when PriorityQueue has more than one Patient.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePopMany()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("first", 2));
				int expected = 2;
				//Act
				target->push(firstPatient);
				target->push(secondPatient);
				int actual = target->pop()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test pop works correctly after peek.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePeekThenPop()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("first", 2));
				int expected = 2;
				//Act
				target->push(firstPatient);
				target->push(secondPatient);
				target->peek();
				int actual = target->pop()->getPriority();
				//Assert
				Assert::AreEqual(expected, actual);
			}
			//Test number of Patients in the queue after pop.
	public: [TestMethod]
			[DeploymentItem(L"PriorityQueue.exe")]
			void PatientPriorityQueuePopThenCount()
			{
				//Arrange
				PatientPriorityQueue_Accessor^ target = (gcnew PatientPriorityQueue_Accessor());
				Patient_Accessor^ firstPatient = (gcnew Patient_Accessor("first", 1));
				Patient_Accessor^ secondPatient = (gcnew Patient_Accessor("first", 2));
				int expected = 1;
				//Act
				target->push(firstPatient);
				target->push(secondPatient);
				target->pop();
				int actual = target->count();
				//Assert
				Assert::AreEqual(expected, actual);	
			}
	};
}
namespace UnitTesting {
    
}
