//
// Created by pam on 19/06/18.
//

#include <memory>
#include <gtest/gtest.h>
#include "Subscriber.h"

// setUp and tearDown


TEST(Subscriber, init) {
	std::unique_ptr<Subscriber> sub = std::make_unique<Subscriber>("1630236", "Nicolas", "Gagnon", 8);
	EXPECT_EQ("1630236", sub->getId());
	EXPECT_EQ("Nicolas", sub->getFirstName());
	EXPECT_EQ("Gagnon", sub->getLastName());
	EXPECT_EQ(8, sub->getAge());
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
