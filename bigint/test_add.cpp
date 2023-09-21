// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main()
{
  {

    // VERY INCOMPLETE set of tests.

    //------------------------------------------------------
    // Setup fixture
    bigint left(0);
    bigint right(0);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 0);
    assert(right == 0);
    assert(result == 0);
  }

  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(1);
    bigint right(0);
    bigint result;

    // Test
    result = left + right;
    // Verify
    assert(left == 1);
    assert(right == 0);
    assert(result == 1);
  }
  {
    //------------------------------------------------------
    // Setup fixture
    bigint left(1);
    bigint right(1);
    bigint result;

    // Test
    result = left + right;

    // Verify
    assert(left == 1);
    assert(right == 1);
    assert(result == 2);
  }

  // You need to add more test cases here. Remove this assert.

  // Add test cases as needed.
  {
    // testing adding two bigints of different sizes
    bigint left(123);
    bigint right(1);
    bigint result;

    result = left + right;

    assert(result == 124);
  }

  {
    // testing 0s within the number
    bigint left(100);
    bigint right(101);
    bigint result;

    result = left + right;

    assert(result == 201);
  }

  {
    // test rollover numbers (numbers that add to greater than or equal to 10)
    // numbers that add to exactly 10
    bigint left(15);
    bigint right(15);
    bigint result;

    result = left + right;

    assert(result == 30);

    // numbers of different size and add to more than 10
    left = 44;
    right = 7;

    result = left + right;

    assert(result == 51);

    // multiple rollovers in a row
    left = 122;
    right = 78;

    result = left + right;

    assert(result == 200);
  }

  std::cout << "Done with testing addition." << std::endl;
  return 0;
}
