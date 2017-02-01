using DiscreteEventSimulator;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;

namespace DESTest
{
    
    
    /// <summary>
    ///This is a test class for StatisticsHandlerTest and is intended
    ///to contain all StatisticsHandlerTest Unit Tests
    ///</summary>
    [TestClass()]
    public class StatisticsHandlerTest
    {


        private TestContext testContextInstance;

        /// <summary>
        ///Gets or sets the test context which provides
        ///information about and functionality for the current test run.
        ///</summary>
        public TestContext TestContext
        {
            get
            {
                return testContextInstance;
            }
            set
            {
                testContextInstance = value;
            }
        }

        #region Additional test attributes
        // 
        //You can use the following additional attributes as you write your tests:
        //
        //Use ClassInitialize to run code before running the first test in the class
        //[ClassInitialize()]
        //public static void MyClassInitialize(TestContext testContext)
        //{
        //}
        //
        //Use ClassCleanup to run code after all tests in a class have run
        //[ClassCleanup()]
        //public static void MyClassCleanup()
        //{
        //}
        //
        //Use TestInitialize to run code before running each test
        //[TestInitialize()]
        //public void MyTestInitialize()
        //{
        //}
        //
        //Use TestCleanup to run code after each test has run
        //[TestCleanup()]
        //public void MyTestCleanup()
        //{
        //}
        //
        #endregion


        /*************************************************************
         * Test that the StatisticHandler is catching division by zero 
         * exceptions correctly.
         ************************************************************/

        //CalculateRepUtiliziation division by zero test.
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateRepUtiliziationTestDivisionByZero()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
            
            //initialize a service desk.
            ServiceDesk sd = new ServiceDesk(productTypes[0], 1, 0, null);           
            
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
            
            //intialize the expected result.
            double expected = double.NaN;
            
            //perform atcion
            target.CalculateRepUtiliziation(sd);
            double result = target.RepUtilization[productTypes[0]];

            //check results
            Assert.AreEqual(expected, result);
        }

        //CalculateAverageNumberWaiting division by zero test.        
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateAverageNumberWaitingTestDivisionByZero()
        {
            //initialize a product type.
            string[] productTypes = new string[] {ProductData.CAR_STEREO_PRODUCT};
            
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);           
           
            //intialize the expected result.
            double expected = double.NaN;
            
            //perform action.
            target.CalculateAverageNumberWaiting(productTypes[0]);
            double result = target.AverageNumberWaiting[productTypes[0]];
            
            //check results.
            Assert.AreEqual(expected, result);
        }

        //CalculateAverageWaitTime division by zero test.
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateAverageWaitTimeTestDivisionByZero()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
            
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
            
            //intialize the expected result.
            double expected = 0;

            //perform action.
            target.CalculateAverageWaitTime();
            double result = target.AverageWaitTime;

            //check results.
            Assert.AreEqual(expected, result);
        }

        //CalculateAverageSystemTime division by zero test.
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateAverageSystemTimeTestDivisionByZero()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
           
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
           
            //intialize the expected result.
            double expected = 0;

            //perform action.
            target.CalculateAverageSystemTime();
            double result = target.AverageSystemTime;

            //check results.
            Assert.AreEqual(expected, result);
        }

        /**********************************************************************
         * Test that the StatisticHandler is performing calculations correctly.
         *********************************************************************/

        //CalculateRepUtiliziation perform calculation test.
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateRepUtiliziationTestPerformCalculation()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
            
            //initialize a service desk.
            ServiceDesk sd = new ServiceDesk(productTypes[0], 1, 0, null);
           
            //initialze the service desk representative work time (30 minutes in seconds)
            sd.AddEntity(null, 1800);
           
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
            
            //initialize the total work time (in minutes)
            target.ObserveTime = 60;

            //intialize the expected result (the service rep should have worked 
            //for 50% of the available time).
            double expected = 0.5;

            //perform action
            target.CalculateRepUtiliziation(sd);
            double result = target.RepUtilization[productTypes[0]];

            //check results
            Assert.AreEqual(expected, result);
        }

        //CalculateAverageNumberWaiting perform calculation test.        
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateAverageNumberWaitingTestPerformCalculation()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
            //intialize the expected result.
            double expected = 6;

            //add number waiting samples
            target.TakeNumberWaitingSample(productTypes[0], 2);
            target.TakeNumberWaitingSample(productTypes[0], 4);
            target.TakeNumberWaitingSample(productTypes[0], 6);
            target.TakeNumberWaitingSample(productTypes[0], 8);
            target.TakeNumberWaitingSample(productTypes[0], 10);

            //perform action.
            target.CalculateAverageNumberWaiting(productTypes[0]);
            double result = target.AverageNumberWaiting[productTypes[0]];

            //check results.
            Assert.AreEqual(expected, result);
        }

        //CalculateAverageWaitTime perform calculation test.
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateAverageWaitTimeTestPerformCalculation()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
            //intialize the expected result.
            double expected = 3;

            //add time waiting samples
            target.TakeWaitTimeSample(1);
            target.TakeWaitTimeSample(2);
            target.TakeWaitTimeSample(3);
            target.TakeWaitTimeSample(4);
            target.TakeWaitTimeSample(5);

            //perform action.
            target.CalculateAverageWaitTime();
            double result = target.AverageWaitTime;

            //check results.
            Assert.AreEqual(expected, result);
        }

        //CalculateAverageSystemTime perform calculation test.
        [TestMethod()]
        [DeploymentItem("DiscreteEventSimulator.exe")]
        public void CalculateAverageSystemTimeTestPerformCalculation()
        {
            //initialize a product type.
            string[] productTypes = new string[] { ProductData.CAR_STEREO_PRODUCT };
            //initialize  a statistic handler.
            StatisticsHandler_Accessor target = new StatisticsHandler_Accessor(0, productTypes);
            //intialize the expected result.
            double expected = 9;

            //add system time samples
            target.TakeSystemTimeSample(3);
            target.TakeSystemTimeSample(6);
            target.TakeSystemTimeSample(9);
            target.TakeSystemTimeSample(12);
            target.TakeSystemTimeSample(15);

            //perform action.
            target.CalculateAverageSystemTime();
            double result = target.AverageSystemTime;

            //check results.
            Assert.AreEqual(expected, result);
        }
    }
}
