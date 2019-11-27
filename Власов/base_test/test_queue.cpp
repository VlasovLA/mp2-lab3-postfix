#include <gtest.h>
#include "TQueue.h"
#include "TQueue.cpp"

TEST(TQueue, can_create_queue)
{
	EXPECT_NO_THROW(TQueue q(10));
}

TEST(TQueue, throws_when_try_create_queue_with_negative_size)
{
	EXPECT_ANY_THROW(TQueue q(-1));
}

TEST(TQueue, throws_when_try_create_queue_with_too_large_size)
{
	EXPECT_ANY_THROW(TQueue q(1000));
}

TEST(TQueue, first_in_first_out)
{
	TQueue q(3);
	q.Put(1);
	q.Put(2);
	q.Put(3);
	EXPECT_EQ(q.Get(), 1);
	EXPECT_EQ(q.Get(), 2);
	EXPECT_EQ(q.Get(), 3);
}

TEST(TQueue, throws_when_try_put_in_full_queue)
{
	TQueue q(3);
	q.Put(1);
	q.Put(2);
	q.Put(3);
	EXPECT_ANY_THROW(q.Put(4));
}

TEST(TQueue, throws_when_try_get_from_empty_queue)
{
	TQueue q(3);
	EXPECT_ANY_THROW(q.Get());
}