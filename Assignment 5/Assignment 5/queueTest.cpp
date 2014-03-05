#include "TestHarness.h"
#include "Queue.h"
#include <deque>
#include <list>
#include <vector>
#include <string>

TEST(basicInitTest, Queue){
	Queue<std::list<float>> flq;
	Queue<std::vector<char>> cvq;
	Queue<std::vector<std::string>> svq;
}

TEST(dequeTest, Queue){
	Queue<std::deque<int>> idq;
	idq.push(5);
	idq.push(3);
	idq.push(9);
	CHECK_EQUAL(5, idq.pop());
	CHECK_EQUAL(3, idq.pop());
	CHECK_EQUAL(9, idq.pop());
}