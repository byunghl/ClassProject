// TestHashMap.cpp
//
// ICS 45C Winter 2014
// Project #3: Maps and Legends
//
// Write unit tests for your HashMap class here.  I've provided one test already,
// though I've commented it out, because it won't compile until you've implemented
// three things: the HashMap constructor, the HashMap destructor, and HashMap's
// size() member function.

#include <gtest/gtest.h>
#include "HashMap.hpp"


namespace {
    unsigned int myHash(const std::string& key) {
            unsigned int sum = 0;
            for(unsigned int i = 0; i < key.length();i++) 
            {
                char ch = key.at(i);
                sum += ch;
            }
            return sum;
    }
}

// Test Case 1: Test default constructor
TEST(TestHashMap, sizeOfNewlyCreatedHashMapIsZero)
{
   HashMap empty;
   ASSERT_EQ(0, empty.size());
   ASSERT_EQ(0, empty.loadFactor());
   ASSERT_EQ(0, empty.maxBucketSize());
   ASSERT_EQ(10, empty.bucketCount());
}

//Test Case 2: test HashMap's constructor with a parameter.
TEST(TestHashMap, hashMapConstructorWithOneParameter) {
    HashMap hashMap(myHash); 
    ASSERT_EQ(0, hashMap.size()) << "default constructor cannot initialize property";
    ASSERT_EQ(0, hashMap.loadFactor() )<<  "default constructor cannot initialize property";
    ASSERT_EQ(0, hashMap.maxBucketSize()) <<  "default constructor cannot initialize property";
    ASSERT_EQ(10, hashMap.bucketCount()) <<  "default constructor cannot initialize property";
}

// Test Case 3: Test copy constructor 
TEST(TestHashMap, testCopyConstructor) {
    HashMap hm1;
    hm1.add("Hi","1234");
    hm1.add("Google", "4321");
    hm1.add("Naver","1234");
    hm1.add("Go", "4321");
    hm1.add("Boo","1234");
    hm1.add("Foo", "4321");
    const HashMap hm2 = hm1;

    EXPECT_EQ(hm1.size(), hm2.size());
    EXPECT_EQ(hm1.bucketCount(), hm2.bucketCount());
    EXPECT_EQ(hm1.maxBucketSize(), hm2.maxBucketSize());
    EXPECT_EQ(hm1.loadFactor(), hm2.loadFactor());
}

// Test Case: Test Destructor
TEST(TestHashMap, testDestructor) {
    
   HashMap* hm =  new HashMap;
    delete hm;

    // if there is no memory leak, that means destructor works !

}

// Test Case 4: Test = Operator Overload
TEST(TestHashMap, testEqualOperatorOverload) {

	HashMap hm1;
	hm1.add("Hi", "1234");
	hm1.add("aa121", "1234");
	hm1.add("bb441", "1234");
	hm1.add("ccc11", "1234");
	hm1.add("ddd121", "1234");
	hm1.add("qqq441", "1234");
	hm1.add("wew", "1234");
	hm1.add("wewe1121", "1234");
	hm1.add("Hi441", "1234");

	HashMap hm2;
	hm2.add("Hias", "1234");
	hm2.add("Hiqwq", "1234");
	
	hm1 = hm2;

	EXPECT_EQ(hm1.size(), hm2.size());	
	EXPECT_EQ(hm1.bucketCount(), hm2.bucketCount());
         EXPECT_EQ(hm1.maxBucketSize(), hm2.maxBucketSize());
         EXPECT_EQ(hm1.loadFactor(), hm2.loadFactor());
}

// Test Case 5: Test Add function.
TEST(TestHashMap, testAddFunction) {

	HashMap hm1;
	hm1.add("HiThere123", "1234");
	hm1.add("123Foo", "1234");
	hm1.add("Booajfajfdksa;ffajlsdkfjasdlfjsakdfjda;skfjsadf", "abcd1234");

	ASSERT_EQ(3, hm1.size());
}

// Test Case 6: Test remove function.
TEST(TestHashMap, testRemoveFunction) {

    HashMap hm;
    hm.add("boo@ics45.com", "lovelydog");
    hm.add("foo@ics45.com", "whoisfoo");
    hm.add("Victoria@secret.com", "whoisvictoria");

    hm.remove("boo@ics45.com");
    ASSERT_EQ(2, hm.size());
    ASSERT_EQ(0.2, hm.loadFactor());
    ASSERT_EQ(10, hm.bucketCount());
    hm.remove("foo@ics45.com");
    ASSERT_EQ(1, hm.size());
    ASSERT_EQ(0.1, hm.loadFactor());
    ASSERT_EQ(10, hm.bucketCount());
}

// Test Case 7: Test contains function.
TEST(TestHashMap, testContainsFunction){

    HashMap hm;
    hm.add("boo@ics45.com", "lovelydog");
    hm.add("foo@ics45.com", "whoisfoo");
    hm.add("Victoria@secret.com", "whoisvictoria");

    ASSERT_TRUE(hm.contains("boo@ics45.com") );
    ASSERT_TRUE(hm.contains("foo@ics45.com") );
    ASSERT_TRUE(hm.contains("Victoria@secret.com") );
}
// Test Case 8: Test value function.
TEST(TestHashMap, testValueFunction){

    HashMap hm;
    hm.add("boo@ics45.com", "lovelydog");
    hm.add("foo@ics45.com", "whoisfoo");
    hm.add("Victoria@secret.com", "whoisvictoria");

    EXPECT_EQ("lovelydog", hm.value("boo@ics45.com") );
    EXPECT_EQ("whoisfoo", hm.value("foo@ics45.com") );
    EXPECT_EQ("whoisvictoria", hm.value("Victoria@secret.com") );
}

// Test Case 9: Test size() function.
TEST(TestHashMap, testSizeFunction){
    HashMap hm;
    hm.add("boo@ics45.com", "lovelydog");
    hm.add("foo@ics45.com", "whoisfoo");
    hm.add("Victoria@secret.com", "whoisvictoria");
    hm.add("Thorton", "codemaster");
    hm.add("tooManyClass", "failed");

    ASSERT_EQ(5, hm.size());
}

// Test Case 10: Test bucketCount() function.
TEST(TestHashMap, testBucketCountFunction){
    HashMap hm;
    hm.add("boo@ics45.com", "lovelydog");
    hm.add("foo@ics45.com", "whoisfoo");
    hm.add("Victoria@secret.com", "whoisvictoria");
    hm.add("Thorton", "codemaster");
    hm.add("tooManyClass", "failed");

    ASSERT_EQ(10, hm.bucketCount());

    hm.add("BillGates", "Microsoft");
    hm.add("WarrenBuffet", "bestInvestor");
    hm.add("Byunghl", "sufferedStudent");
    hm.add("Incubus", "goodBand");

    ASSERT_EQ(21, hm.bucketCount());
}

// Test Case 11: Test loadFactor() function.
TEST(TestHashMap, testLoadFactorFunction){
    HashMap hm;
    hm.add("boo@ics45.com", "lovelydog");
    hm.add("foo@ics45.com", "whoisfoo");
    hm.add("Victoria@secret.com", "whoisvictoria");
    hm.add("Thorton", "codemaster");
    hm.add("tooManyClass", "failed");

    ASSERT_EQ(0.5, hm.loadFactor());

    hm.add("BillGates", "Microsoft");
    hm.add("WarrenBuffet", "bestInvestor");
    hm.add("Byunghl", "sufferedStudent");
    hm.add("Incubus", "goodBand");

    double expectedLoadFactor = double(9.0/21.0);
    ASSERT_EQ( expectedLoadFactor, hm.loadFactor());
}


// Test Case 12: Test maxBucketSize() function.
TEST(TestHashMap, testMaxBucketSizeFunction){
    HashMap hm;
    hm.add("Hello2", "1234");
    hm.add("Singe0", "1234");
    hm.add("Timo3", "1234");
   
    ASSERT_EQ(3, hm.maxBucketSize());
}

// Test Case 13: Test increaseNumberOfAccount() function
TEST(TestHashMap, testIncreaseNumberOfAccountFunction) {
    HashMap hm;
    hm.increaseNumberOfAccount();
    ASSERT_EQ(1, hm.size());
}

// Test Case 14: Test decreaeNumberOfAccount() function
TEST(TestHashMap, testDecreaseNumberOfAccountFunction) {
    HashMap hm;
    hm.increaseNumberOfAccount();
    hm.increaseNumberOfAccount();
    hm.increaseNumberOfAccount();
    ASSERT_EQ(3, hm.size());
    hm.decreaseNumberOfAccount();
    ASSERT_EQ(2, hm.size());
    hm.decreaseNumberOfAccount();
    ASSERT_EQ(1, hm.size());
}

